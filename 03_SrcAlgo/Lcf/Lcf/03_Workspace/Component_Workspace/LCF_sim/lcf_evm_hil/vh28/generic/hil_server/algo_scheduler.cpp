#include "algo_scheduler.h"

#include <ti/sysbios/hal/Hwi.h>

#include <assert.h>

C_AlgoBase *C_AlgoBase::pc_Singleton = 0;

C_AlgoBase::C_AlgoBase()
{
    if( pc_Singleton )
    {
        FATAL_ERROR("error: multiple AlgoBase instances");
    } else
    {
        pc_Singleton = this;
    }
    sl_NumInputs = 0;
    sl_NumOutputs = 0;
    m_f32_RunTimeSI = 0.0;
    m_i32_UsedStack = 0;
    AddPort(e_PROVIDE, "HIL_RunTimeSI", e_float32, &m_f32_RunTimeSI, sizeof(m_f32_RunTimeSI));
    AddPort(e_PROVIDE, "HIL_UsedStack", e_sint32, &m_i32_UsedStack, sizeof(m_i32_UsedStack));
}

void C_AlgoBase::AddPort(
        E_PortType e_PortType,
        const char *name, 
        E_DataType e_DataType,
        void *pAddress,
        int size)
{
    S_ValueDescription *pas_Port = 0;
    switch(e_PortType)
    {
        case e_REQUEST:
            pas_Port = &as_InputPorts[sl_NumInputs++];
            break;
        case e_PROVIDE:
            pas_Port = &as_OutputPorts[sl_NumOutputs++];
            break;
    }
    pas_Port->e_DataType = e_DataType;
    strcpy(pas_Port->ac_name, name);
    pas_Port->pAddress = pAddress;
    pas_Port->size = size;
}

/* Begin: SimV3 compatibility support */
void C_AlgoBase::AddReceivePort(const char *PortName, SimPortDataTypes_t eType, void *pVoid, int Size) {
    S_ValueDescription *pas_Port = 0;
    pas_Port = &as_InputPorts[sl_NumInputs++];

    pas_Port->e_DataType = e_TranslateEnum_SimV3toHil(eType);
    strcpy(pas_Port->ac_name, PortName);
    pas_Port->pAddress = pVoid;
    pas_Port->size = Size;
}

void C_AlgoBase::AddReceivePort(const char *PortName, SimPortDataTypes_t eType, void *pVoid, int Size, unsigned int PortMode) {
    S_ValueDescription *pas_Port = 0;
    pas_Port = &as_InputPorts[sl_NumInputs++];

    pas_Port->e_DataType = e_TranslateEnum_SimV3toHil(eType);
    strcpy(pas_Port->ac_name, PortName);
    pas_Port->pAddress = pVoid;
    pas_Port->size = Size;
}

void C_AlgoBase::AddProvidePort(const char *PortName, SimPortDataTypes_t eType,  void *pVoid, int Size) {
    S_ValueDescription *pas_Port = 0;
    pas_Port = &as_OutputPorts[sl_NumOutputs++];
    pas_Port->e_DataType = e_TranslateEnum_SimV3toHil(eType);
    strcpy(pas_Port->ac_name, PortName);
    pas_Port->pAddress = pVoid;
    pas_Port->size = Size;
}

E_DataType C_AlgoBase::e_TranslateEnum_SimV3toHil(SimPortDataTypes_t e_SimV3Type) {
  E_DataType e_HilSimType;

  switch( e_SimV3Type )
  {
    case (simUI8_t):
      e_HilSimType = e_uint8;
      break;
    case (simI8_t):
      e_HilSimType = e_sint8;
      break;
    case (simUI16_t):
      e_HilSimType = e_uint16;
      break;
    case (simI16_t):
      e_HilSimType = e_sint16;
      break;
    case (simUI32_t):
      e_HilSimType = e_uint32;
      break;
    case (simI32_t):
      e_HilSimType = e_sint32;
      break;
    case (simF32_t):
      e_HilSimType = e_float32;
      break;
    case (simI64_t):
      e_HilSimType = e_sint64;
      break;
    case (simF64_t):
      e_HilSimType = e_float64;
      break;
    case (simUI64_t):
      e_HilSimType = e_uint64;
      break;
    case (simOPAQUE_t):
      e_HilSimType = e_array_uint8;
      break;
    case (simREFERENCE_t):
      assert(false); // port type is not supported
      break;
    default:
      assert(false); // port type is not supported
      break;
  }
  return e_HilSimType;
}
/* End: SimV3 compatibility support */


C_AlgoScheduler *C_AlgoScheduler::pc_Singleton = 0;

C_AlgoScheduler::C_AlgoScheduler()
{
    e_SchedulerState = e_READ_CMD;
    sl_NextTokenSize = 1;
    sl_NextTokenValid = 0;
    pv_NextTokenDest = &ub_Cmd;
}

void C_AlgoScheduler::init()
{
    C_AlgoBase *pc_Algo = C_AlgoBase::pc_Singleton;

    if( !pc_Algo )
    {
        FATAL_ERROR( "error: no algo base instance");
    }
    pc_Algo->getInputPortDefinitions(pas_Inputs, sl_NumInputs);
    pc_Algo->getOutputPortDefinitions(pas_Outputs, sl_NumOutputs);
}

void C_AlgoScheduler::feedScheduler(void *buf, int size)
{
    static const unsigned char ub_SET_VALUE = 96;
    static const unsigned char ub_GET_VALUE = 19;
    static const unsigned char ub_GET_MULT_VALUE = 33;
    static const unsigned char ub_DO_INIT   = 34;
    static const unsigned char ub_DO_RUN    = 42;
    static const unsigned char ub_DO_EXIT   = 23;

    if( size > (sl_NextTokenSize - sl_NextTokenValid) )
    {
        FATAL_ERROR( "error: unexpected size in feed scheduler" );
    }
    memcpy((unsigned char*)pv_NextTokenDest + sl_NextTokenValid, buf, size);
    sl_NextTokenValid += size;

    if( sl_NextTokenValid == sl_NextTokenSize )
    {
        switch( e_SchedulerState )
        {
        case e_READ_CMD:
            if( ub_Cmd == ub_SET_VALUE || 
                ub_Cmd == ub_GET_VALUE )
            {
                ub_Cnt = 1;
                e_SchedulerState = e_READ_ADDRESS;
            } else if( ub_Cmd == ub_GET_MULT_VALUE )
            {
                e_SchedulerState = e_READ_COUNT;
            } else if( ub_Cmd == ub_DO_INIT || 
                       ub_Cmd == ub_DO_RUN ||
                       ub_Cmd == ub_DO_EXIT )
            {
                e_SchedulerState = e_READ_FUNC_PARAM;
            } else
            {
                FATAL_ERROR( "error: unknown command");
            }
            break;
        case e_READ_FUNC_PARAM:
            if( ub_Cmd == ub_DO_INIT )
            {
                executeInit();
            } else if( ub_Cmd == ub_DO_RUN )
            {
                executeRun();
            } else if( ub_Cmd == ub_DO_EXIT )
            {
                executeExit();
            }
            e_SchedulerState = e_READ_CMD;
            break;
        case e_READ_COUNT:
            e_SchedulerState = e_READ_ADDRESS;
            break;
        case e_READ_ADDRESS:
            e_SchedulerState = e_READ_SIZE;
            break;
        case e_READ_SIZE:
            if( ub_Cmd == ub_SET_VALUE )
            {
                e_SchedulerState = e_READ_VALUE;
            } else if( ub_Cmd == ub_GET_VALUE ||
                       ub_Cmd == ub_GET_MULT_VALUE )
            {
                executeGet();
                ub_Cnt--;
                if( ub_Cnt == 0 )
                {
                    e_SchedulerState = e_READ_CMD;
                } else
                {
                    e_SchedulerState = e_READ_ADDRESS;
                }
            } else
            {
                FATAL_ERROR( "error: unknown command");
                e_SchedulerState = e_READ_CMD;
            }
            break;
        case e_READ_VALUE:
            e_SchedulerState = e_READ_CMD;
            break;
        }
        sl_NextTokenValid = 0;
        switch( e_SchedulerState )
        {
        case e_READ_VALUE:
            pv_NextTokenDest = getPointerToCurrentAddress(ui32_Size);
            sl_NextTokenSize = ui32_Size;
            if( pv_NextTokenDest != 0 )
            {
                break;
            } else
            {
                FATAL_ERROR( "error: invalid address");
            }
        case e_READ_CMD:
            ub_Cmd = 0;
            pv_NextTokenDest = &ub_Cmd;
            sl_NextTokenSize = 1;
            break;
        case e_READ_COUNT:
            ub_Cnt = 0;
            pv_NextTokenDest = &ub_Cnt;
            sl_NextTokenSize = 1;
            break;
        case e_READ_ADDRESS:
            ui32_Address = 0xffff;
            pv_NextTokenDest = &ui32_Address;
            sl_NextTokenSize = 4;
            break;
        case e_READ_SIZE:
            ui32_Size = 0;
            pv_NextTokenDest = &ui32_Size;
            sl_NextTokenSize = 4;
            break;
        case e_READ_FUNC_PARAM:
            pv_NextTokenDest = &sl32_FuncParam;
            sl_NextTokenSize = 4;
        }
    }
}

void C_AlgoScheduler::executeInit()
{
	/* Calls Init() in derived classes */
    C_AlgoBase::pc_Singleton->Init(sl32_FuncParam);
}

static void *pv_getSP()
{
    volatile int i;
    return (void*)&i; // just want to check stack size, warning ok
}

void C_AlgoScheduler::executeRun()
{
    unsigned int oldCSR;
    static char c_Init = 'A';
    int sl_i;
    char *pv_SP;
    
    pv_SP = (char*)pv_getSP();

    for(sl_i = 256; sl_i < (1 << 15); sl_i++)
    {
        if( (unsigned int)pv_SP > (unsigned int)&sl_i )
        {
            pv_SP[(sl_i + 256)] = c_Init;
        } else
        {
            pv_SP[-(sl_i + 256)] = c_Init;
        }
    }

#ifndef _VICP_DEBUG
    oldCSR = Hwi_disable();
#endif
    /* Calls Run() in derived classes */
    C_AlgoBase::pc_Singleton->Run(sl32_FuncParam);
#ifndef _VICP_DEBUG
    Hwi_restore(oldCSR);
#endif

    if( (unsigned int)pv_SP > (unsigned int)&sl_i )
    {
        for(sl_i = (1 << 15)-1; pv_SP[sl_i+256] == c_Init && sl_i >= 0; sl_i--)
        {
        }
    } else
    {
        for(sl_i = (1 << 15)-1; pv_SP[-(sl_i+256)] == c_Init && sl_i >= 0; sl_i--)
        {
        }        
    }
    C_AlgoBase::pc_Singleton->m_i32_UsedStack = sl_i + 256;
    C_AlgoBase::pc_Singleton->m_f32_RunTimeSI = 0;
}

void C_AlgoScheduler::executeExit()
{
	/* Calls Exit() in derived classes */
    C_AlgoBase::pc_Singleton->Exit(sl32_FuncParam);
}

static void send_wrap(SOCKET socket, void *pv_Src, unsigned int ui32_Size)
{
    unsigned int ui32_Sent = 0;
    int sl_i;
    while(ui32_Sent < ui32_Size )
    {
        sl_i = send(socket, (unsigned char*)pv_Src + ui32_Sent, ui32_Size - ui32_Sent, 0);
        if( sl_i < 0 )
        {
            FATAL_ERROR( "send failed!");
            break;
        }
        ui32_Sent += sl_i;
    }
}

void C_AlgoScheduler::executeGet()
{
    void *pv_Src = getPointerToCurrentAddress(ui32_Size);
    if( !pv_Src )
    {
        FATAL_ERROR( "Unknown address or size mismatch" );
    } else
    {
        send_wrap(socket, pv_Src, ui32_Size);
    }
}

void *C_AlgoScheduler::getPointerToCurrentAddress(int sl_Size)
{
    static const unsigned char ub_INPUT_PORT = 23;
    static const unsigned char ub_OUTPUT_PORT = 17;
    static const unsigned char ub_PORT_INFO = 13;
    static const unsigned char ub_PORT_DESC = 7;

    static int sl_TypeID;
    unsigned short ui16_StructSelect = ui32_Address >> 16;
    unsigned short ui16_Element = ui32_Address & 0xffffU;
    const S_ValueDescription *pas_Struct = 0;
    void *pv_Res = 0;
    int sl_StructSize = 0;

    switch(ui16_StructSelect)
    {
    case ub_INPUT_PORT:
        pas_Struct = pas_Inputs;
        sl_StructSize = sl_NumInputs;
        break;
    case ub_OUTPUT_PORT:
        pas_Struct = pas_Outputs;
        sl_StructSize = sl_NumOutputs;
        break;
    }
    if( pas_Struct && ui16_Element < sl_StructSize )
    {
        pas_Struct += ui16_Element;
        switch( pas_Struct->e_DataType )
        {
        case e_float32:
        case e_float64:
        case e_sint8:
        case e_sint16:
        case e_sint32:
        case e_sint64:
        case e_uint8:
        case e_uint16:
        case e_uint32:
        case e_uint64:
            if( sl_Size == pas_Struct->size )
            {
                pv_Res = pas_Struct->pAddress;
            }
            break;
        default:
            if( sl_Size <= pas_Struct->size )
            {
                pv_Res = pas_Struct->pAddress;
            }
        }
    } else
    {
        switch(ui16_StructSelect)
        {
        case ub_PORT_INFO:
            switch( ui16_Element )
            {
            case 1:
                pv_Res = &sl_NumInputs;
                break;
            case 2:
                pv_Res = &sl_NumOutputs;
                break;
            default:
               FATAL_ERROR( "problem with port info id\n" );           
            }
            break;
        case ub_PORT_DESC:
            if( ui16_Element < (sl_NumInputs)*3 )
            {
                pas_Struct = pas_Inputs;
                sl_StructSize = sl_NumInputs;
            } else
            {
                pas_Struct = pas_Outputs;
                sl_StructSize = sl_NumOutputs;
                ui16_Element -= (sl_NumInputs)*3;
            }
            if( ui16_Element/3 < sl_StructSize )
            {
                pas_Struct += ui16_Element/3;
                switch( ui16_Element % 3 )
                {
                case 0:
                    pv_Res = (void*)(pas_Struct->ac_name);
                    sl_Size = AC_NAME_LENGTH;
                    break;
                case 1:
                    sl_TypeID = (int)pas_Struct->e_DataType;
                    pv_Res = (void*)&sl_TypeID;
                    sl_Size = 4;
                    break;
                case 2:
                    pv_Res = (void*)&pas_Struct->size;
                    sl_Size = 4;
                    break;
                }
            } else
            {
               FATAL_ERROR( "problem with address resolve (size mismatch?)\n" );           
            }
            break;
        default:
            FATAL_ERROR( "problem with address resolve (size mismatch?)\n" );
        }
    }
    return pv_Res;
}

// dtask_tcp_algo() - derived from TCP Echo server
// (SOCK_STREAMNC, port 7)
//
// Returns "1" if socket 's' is still open, and "0" if its been closed
//
int C_AlgoScheduler::dtask_tcp_algo(SOCKET s)
{
    struct timeval s_to;
    int            sl_i, sl_ExpectedSize;
    static const int sl_MaxSize = 16384;
    static unsigned char  ach_Buffer[sl_MaxSize];

    printf( "New client connected.\n");

    socket = s;

    // Configure our socket timeout to be 5 seconds
    s_to.tv_sec  = 5;
    s_to.tv_usec = 0;
    setsockopt( s, SOL_SOCKET, SO_SNDTIMEO, &s_to, sizeof( s_to ) );
    setsockopt( s, SOL_SOCKET, SO_RCVTIMEO, &s_to, sizeof( s_to ) );

    sl_i = 1;
    setsockopt( s, IPPROTO_TCP, TCP_NOPUSH, &sl_i, 4 );

    do
    {
        sl_ExpectedSize = sl_NextTokenSize - sl_NextTokenValid;
        if( sl_ExpectedSize > sl_MaxSize )
        {
            sl_ExpectedSize = sl_MaxSize;
        }
        sl_i = recv(s, ach_Buffer, sl_ExpectedSize, 0 );
        //printf("%d\n", sl_i);
        if( sl_i > 0 )
        {
            feedScheduler(ach_Buffer, sl_i);
        }
        else
        {
            if( sl_i == 0 )
            {
                printf("Connection closed by client\n");
            } else
            {
                if( fdError() == EWOULDBLOCK )
                {
                    continue;
                }
                printf("Error %d %d\n", sl_i, fdError() );
            }
            break;
        }
    } while(sl_ExpectedSize > 0 );


    // Return "0" since we closed the socket
    return(1);
}

int C_AlgoScheduler::dtask_tcp_algo_callback(SOCKET s, UINT32)
{
    static C_AlgoScheduler scheduler;
    if(!pc_Singleton)
    {
        pc_Singleton = &scheduler;
        pc_Singleton->init();
    }
    return pc_Singleton->dtask_tcp_algo(s);
}

extern "C" int dtask_tcp_algo_callback(SOCKET s, UINT32 v)
{
    return C_AlgoScheduler::dtask_tcp_algo_callback(s, v);
}
