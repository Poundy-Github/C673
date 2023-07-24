#include "stdafx.h"
#include "hil_client.h"
#include <winsock2.h>
#include <string>

class C_HilClientImpl : public CSimSwcBase
{
    static const unsigned char ub_SET_VALUE = 96;
    static const unsigned char ub_GET_VALUE = 19;
    static const unsigned char ub_DO_INIT = 34;
    static const unsigned char ub_DO_RUN = 42;
    static const unsigned char ub_DO_EXIT = 23;

    static const unsigned int ul_INPUT_PORT = 23u << 16;
    static const unsigned int ul_OUTPUT_PORT = 17u << 16;
    static const unsigned int ul_PORT_INFO = 13u << 16;
    static const unsigned int ul_PORT_DESC = 7u << 16;

    SOCKET c_s;
    std::string send_str;
public:
    C_HilClientImpl()
    {
      sockaddr_in addr;
      WORD         wVersionRequested;
      WSADATA      wsaData;
      int sl_i;

      wVersionRequested = MAKEWORD(1, 1); 
      sl_i = WSAStartup(wVersionRequested, &wsaData);
      if (sl_i != 0)
      {
        abort();
      }

      c_s = socket(AF_INET, SOCK_STREAM, 0);
      if( c_s == INVALID_SOCKET )
      {
        abort();
      }
      addr.sin_family = AF_INET;
      addr.sin_port = htons(7);
      addr.sin_addr.s_addr = inet_addr( "192.168.10.42" );
      if( connect( c_s, (SOCKADDR*)&addr, sizeof(addr) ) == SOCKET_ERROR )
      {
        closesocket(c_s);
      }
      send_str = "";
    }


    ~C_HilClientImpl()
    {
        closesocket(c_s);
    }
    
    void close_socket()
    {
      closesocket(c_s);
    }

    void flush_send()
    {
        int bytes = 0, i;
        while( bytes < (int)send_str.size() )
        {
            i = send(c_s, send_str.c_str() + bytes, static_cast<int>(send_str.size()) - bytes, 0);
            if( i <= 0 )
            {
                i = WSAGetLastError();
                printf("send: WSA error %d\n", i);
                closesocket(c_s);
                TriggerEvent("AlgoCalcDone",0,0);
            }
            bytes += i;
        }
        send_str = "";
    }

    void send_wrap(const std::string &s)
    {
        send_str += s;
        if( send_str.size() > 1024 )
        {
            flush_send();
        }
    }

    std::string recv_wrap(int size)
    {
        static const int bufSize = 1024;
        static char aub_Buf[bufSize];
        int remaining, i;
        std::string v = "";
        flush_send();
        while((int)v.size() < size)
        {
            remaining = size - static_cast<int>(v.size());
            if( remaining > bufSize )
            {
                remaining = bufSize;
            }
            i = recv(c_s, aub_Buf, remaining, 0);
            if( i <= 0 )
            {
                i = WSAGetLastError();
                if( i == 10054 )
                {
                    printf( "recv: Connection reset by peer\n" );
                } else
                {
                    printf( "recv: Unknown WSA error %d\n", i);
                }
                //Begin: Error handling (ulwa)
                closesocket(c_s);
                TriggerEvent("AlgoCalcDone",0,0);
                //End: Error handling (ulwa)
                //commented by ulwa: abort();
            }
            v += std::string(aub_Buf, i);
        }
        return v;
    }

    unsigned long getaddress(E_PortType pt, unsigned long address)
    {
        switch( pt )
        {
        case e_REQUEST: return address | ul_INPUT_PORT;
        case e_PROVIDE: return address | ul_OUTPUT_PORT;
        case e_PORTINFO: return address | ul_PORT_INFO;
        case e_PORTDESC: return address | ul_PORT_DESC;
        }
        return 0;
    }

    void set_value(E_PortType pt, unsigned long address, const void *pv_v, int size)
    {
        address = getaddress(pt, address);
        send_wrap(
            std::string( (const char*)&ub_SET_VALUE, 1 ) +
            std::string( (const char*)&address, 4 ) +
            std::string( (const char*)&size, 4) +
            std::string( (const char*)pv_v, size) );
    }

    void get_value(E_PortType pt, unsigned long address, void *pv_v, int size)
    {
        std::string v;
        address = getaddress(pt, address);
        send_wrap(
            std::string( (const char*)&ub_GET_VALUE, 1 ) +
            std::string( (const char*)&address, 4 ) +
            std::string( (const char*)&size, 4) );
        v = recv_wrap(size);
        memcpy(pv_v, v.c_str(), size);
    }

    void do_init(long p)
    {
        send_wrap(std::string( (const char*)&ub_DO_INIT, 1) + std::string( (const char*)&p, 4) );
    }

    void do_run(long p)
    {
        send_wrap(std::string( (const char*)&ub_DO_RUN, 1) + std::string( (const char*)&p, 4) );
        /* Trigger the run on EVM HIL immediately */
        flush_send();
    }

    void do_exit(long p)
    {
        send_wrap(std::string( (const char*)&ub_DO_EXIT, 1) + std::string( (const char*)&p, 4) );
    }
};

static C_HilClientImpl *pc_Client = 0;

static SimPortDataTypes_t ae_typeid2simtype[] = 
{
    simF32_t,    // e_float32      
    simF64_t,    // e_float64      
    simI8_t,     // e_sint8        
    simI16_t,    // e_sint16       
    simI32_t,    // e_sint32       
    simI64_t,    // e_sint64       
    simUI8_t,    // e_uint8        
    simUI16_t,   // e_uint16       
    simUI32_t,   // e_uint32       
    simI64_t,    // e_uint64, missing UI type :-(
    simOPAQUE_t, // e_array_uint8  
    simOPAQUE_t, // e_array_uint16 
    simOPAQUE_t, // e_array_uint32 
};

C_HilClient::C_HilClient()
{
    StartUP();
}

C_HilClient::~C_HilClient()
{
    pc_Client->close_socket();
}

long C_HilClient::StartUP()
{
    unsigned long sl_i, sl_p, sl_k;
    std::string c_name, c_portName, c_elemName;
    CTKImageData_t *pc_img;
    char ac_name[1024]; 
    long sl_TypeId, sl_Size, sl_IsReceivePort;
    S_ValueDescription *pas_Port;
    SimFunc_t fct_Trigger;

    b_Initialized = false;
    sl_NumInputs = 0;
    sl_NumOutputs = 0;
    if( pc_Client )
    {
        abort();
    }
    pc_Client = new C_HilClientImpl();
    pc_Client->get_value(e_PORTINFO, 1, &sl_NumInputs, sizeof(sl_NumInputs));
    pc_Client->get_value(e_PORTINFO, 2, &sl_NumOutputs, sizeof(sl_NumOutputs));
    sl_p = 0;
    for(sl_i = 0; sl_i < sl_NumInputs + sl_NumOutputs; sl_i++, sl_p++)
    {
        if( sl_i < /*sl_NumParams + */sl_NumInputs )
        {
            pas_Port = &as_InputPorts[sl_i];
            sl_IsReceivePort = 1;
        } else 
        {
            pas_Port = &as_OutputPorts[sl_i - sl_NumInputs];
            sl_IsReceivePort = 0;
        }
        pc_Client->get_value(e_PORTDESC, 3*sl_p+0, ac_name, sizeof(ac_name));
        pc_Client->get_value(e_PORTDESC, 3*sl_p+1, &sl_TypeId, sizeof(sl_TypeId));
        pc_Client->get_value(e_PORTDESC, 3*sl_p+2, &sl_Size, sizeof(sl_Size));
        c_name = ac_name;
        if( c_name.find("!") == 0 )
        {
            // pls remove ! and use client / server ports instead of callbacks
            abort();
            c_name = c_name.substr(1);
            fct_Trigger = _Run;
        } else
        {
            fct_Trigger = 0;
        }
        if( c_name.find("[image]/") == 0 )
        {
            c_name = c_name.substr(strlen("[image]/"));
            sl_k = static_cast<long>(c_name.find("."));
            if( sl_k == std::string::npos )
            {
                abort();
            }
            c_portName = c_name.substr(0, sl_k);
            c_elemName = c_name.substr(sl_k+1);
            if( c_ImgByName.count(c_portName) == 0 )
            {
                if( c_elemName != "data" )
                {
                    // data has to be the first element...
                    abort();
                }
                c_ImgByName[c_portName] = new char[sizeof(CTKImageData_t) + sl_Size];
                ((CTKImageData_t*)c_ImgByName[c_portName])->HeaderSize = sizeof(CTKImageData_t);
                ((CTKImageData_t*)c_ImgByName[c_portName])->Version = 0;
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmType = CTK_IMG_TYPE_GREY16;     
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmWidth = 0;
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmHeight = 0;     
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmBitsPixel = 12;
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmBytesRow = 2048;
                ((CTKImageData_t*)c_ImgByName[c_portName])->XScale = 1;
                ((CTKImageData_t*)c_ImgByName[c_portName])->YScale = 1;
                ((CTKImageData_t*)c_ImgByName[c_portName])->BayerPattern = 0;
                ((CTKImageData_t*)c_ImgByName[c_portName])->Reserved01 = 0;
                ((CTKImageData_t*)c_ImgByName[c_portName])->Reserved02 = 0;
                ((CTKImageData_t*)c_ImgByName[c_portName])->bmSize = sizeof(CTKImageData_t) + sl_Size;

                strcpy(pas_Port->name, ac_name);
                pas_Port->e_DataType = (E_DataType)sl_TypeId;
                pas_Port->size = sl_Size;
                pas_Port->pData = (char*)(c_ImgByName[c_portName]) + sizeof(CTKImageData_t);
                if( sl_IsReceivePort )
                {
                    AddReceivePort(c_portName.c_str(), ae_typeid2simtype[sl_TypeId], c_ImgByName[c_portName], sizeof(CTKImageData_t) + sl_Size, 0, fct_Trigger, this);
                } else
                {
                    AddProvidePort(c_portName.c_str(), ae_typeid2simtype[sl_TypeId], c_ImgByName[c_portName], sizeof(CTKImageData_t) + sl_Size);
                }
            } else
            {
                strcpy(pas_Port->name, ac_name);
                pas_Port->e_DataType = (E_DataType)sl_TypeId;
                pas_Port->size = sl_Size;
                pc_img = (CTKImageData_t*)c_ImgByName[c_portName];
                if( c_elemName == "width" )
                {
                    if( (E_DataType)sl_TypeId != e_sint16 )
                    {
                        abort();
                    }
                    pas_Port->pData = &pc_img->bmWidth;
                } else if( c_elemName == "height" )
                {
                    if( (E_DataType)sl_TypeId != e_sint16 )
                    {
                        abort();
                    }
                    pas_Port->pData = &pc_img->bmHeight;
                } else if( c_elemName == "bytesPerRow" )
                {
                    if( (E_DataType)sl_TypeId != e_sint16 )
                    {
                        abort();
                    }
                    pas_Port->pData = &pc_img->bmBytesRow;
                } else if( c_elemName == "bitsPerPixel" )
                {
                    if( (E_DataType)sl_TypeId != e_sint16 )
                    {
                        abort();
                    }
                    pas_Port->pData = &pc_img->bmBitsPixel;
                } else
                {
                    abort();
                }
            }
        } else
        {
            strcpy(pas_Port->name, ac_name);
            pas_Port->e_DataType = (E_DataType)sl_TypeId;
            pas_Port->size = sl_Size;
            pas_Port->pData = new char[sl_Size];
            if( sl_IsReceivePort )
            {
                AddReceivePort(c_name.c_str(), ae_typeid2simtype[sl_TypeId], pas_Port->pData, pas_Port->size, 0, fct_Trigger, this);
            } else
            {
                AddProvidePort(c_name.c_str(), ae_typeid2simtype[sl_TypeId], pas_Port->pData, pas_Port->size);
            }
        }
    }
    AddClientPort("AlgoCalcDone", NULL, 0, PORT_WITH_AUTOCLONE);
    AddServerPort("Init",    _Init,    this);
    AddServerPort("Exit",    _Exit,    this);
    AddServerPort("Run",     _Run,     this);
    AddServerPort("Trigger", _Trigger, this);
    AddServerPort("Wait",    _Wait,    this);

    // make sure that inputs values are synchronized with the HW
    // therefore get all the inputs
    for(sl_i = 0; sl_i < sl_NumInputs; sl_i++)
    {
#ifdef PRINT_DEBUG
        if( as_InputPorts[sl_i].size <= 4 )
        {
            printf( "i %d: %x %x %x %x\n", 
                sl_i, 
                as_InputPorts[sl_i].size >= 1 ? ((unsigned char*)as_InputPorts[sl_i].pData)[0] : 0,
                as_InputPorts[sl_i].size >= 2 ? ((unsigned char*)as_InputPorts[sl_i].pData)[1] : 0,
                as_InputPorts[sl_i].size >= 3 ? ((unsigned char*)as_InputPorts[sl_i].pData)[2] : 0,
                as_InputPorts[sl_i].size >= 4 ? ((unsigned char*)as_InputPorts[sl_i].pData)[3] : 0);
        }
#endif
        pc_Client->get_value(e_REQUEST, sl_i, as_InputPorts[sl_i].pData, as_InputPorts[sl_i].size);
    }
    for(sl_i = 0; sl_i < sl_NumOutputs; sl_i++)
    {
#ifdef PRINT_DEBUG
        printf( "o %d\n", sl_i);
#endif
        pc_Client->get_value(e_PROVIDE, sl_i, as_OutputPorts[sl_i].pData, as_OutputPorts[sl_i].size);
    }

    return 0;
}

void C_HilClient::ClientCallInit(long p1)
{
    unsigned long sl_i;
    b_Initialized = true;
    for(sl_i = 0; sl_i < sl_NumInputs; sl_i++)
    {
#ifdef PRINT_DEBUG
        if( as_InputPorts[sl_i].size <= 4 )
        {
            printf( "i %d: %x %x %x %x\n", 
                sl_i, 
                as_InputPorts[sl_i].size >= 1 ? ((unsigned char*)as_InputPorts[sl_i].pData)[0] : 0,
                as_InputPorts[sl_i].size >= 2 ? ((unsigned char*)as_InputPorts[sl_i].pData)[1] : 0,
                as_InputPorts[sl_i].size >= 3 ? ((unsigned char*)as_InputPorts[sl_i].pData)[2] : 0,
                as_InputPorts[sl_i].size >= 4 ? ((unsigned char*)as_InputPorts[sl_i].pData)[3] : 0);
        }
#endif
        pc_Client->set_value(e_REQUEST, sl_i, as_InputPorts[sl_i].pData, as_InputPorts[sl_i].size);
    }
    pc_Client->do_init(p1);
}

/* Triggers EVM HIL and waits until outputs are available */
void C_HilClient::ClientCallRun(long p1)
{
  ClientCallTrigger(p1);
  ClientCallWait();
}

/* Triggers EVM HIL */
void C_HilClient::ClientCallTrigger(long p1)
{
    unsigned long sl_i;
    for(sl_i = 0; sl_i < sl_NumInputs; sl_i++)
    {
#ifdef PRINT_DEBUG
        if( as_InputPorts[sl_i].size <= 4 )
        {
            printf( "i %d: %x %x %x %x\n", 
                sl_i, 
                as_InputPorts[sl_i].size >= 1 ? ((unsigned char*)as_InputPorts[sl_i].pData)[0] : 0,
                as_InputPorts[sl_i].size >= 2 ? ((unsigned char*)as_InputPorts[sl_i].pData)[1] : 0,
                as_InputPorts[sl_i].size >= 3 ? ((unsigned char*)as_InputPorts[sl_i].pData)[2] : 0,
                as_InputPorts[sl_i].size >= 4 ? ((unsigned char*)as_InputPorts[sl_i].pData)[3] : 0);
        }
#endif
        if(FindRPortByName(as_InputPorts[sl_i].name)->IsDirty())
        {
          pc_Client->set_value(e_REQUEST, sl_i, as_InputPorts[sl_i].pData, as_InputPorts[sl_i].size);
          FindRPortByName(as_InputPorts[sl_i].name)->SetNotDirty();
        }
        /*
        switch( as_InputPorts[sl_i].e_DataType )
        {
        case e_float32:
            printf("set_value(Input %d) -> %f\n", sl_i, *((float*)as_InputPorts[sl_i].pData) );
            break;
        case e_sint32:
            printf("set_value(Input %d) -> %d\n", sl_i, *((int*)as_InputPorts[sl_i].pData) );
            break;
        case e_uint32:
            printf("set_value(Input %d) -> %d\n", sl_i, *((unsigned int*)as_InputPorts[sl_i].pData) );
            break;
        }*/
    }

    /* Trigger EVM HIL */
    pc_Client->do_run(p1);
}

/* Waits until EVM HIL outputs are available */
void C_HilClient::ClientCallWait()
{
    unsigned long sl_i;

    for(sl_i = 0; sl_i < sl_NumOutputs; sl_i++)
    {
#ifdef PRINT_DEBUG
        printf( "o %d\n", sl_i);
#endif
        pc_Client->get_value(e_PROVIDE, sl_i, as_OutputPorts[sl_i].pData, as_OutputPorts[sl_i].size);
    }
}

void C_HilClient::Run(long p1)
{
    ClientCallRun(p1);
    TriggerEvent("AlgoCalcDone",0,0);
}

void C_HilClient::Trigger(long p1)
{
    ClientCallTrigger(p1);
}

void C_HilClient::Wait()
{
    ClientCallWait();
    TriggerEvent("AlgoCalcDone",0,0);
}


void C_HilClient::Init(long p1)
{
    ClientCallInit(p1);
}

void C_HilClient::Exit(long p1)
{
    ClientCallExit(p1);
}

void C_HilClient::ClientCallExit(long p1)
{
    pc_Client->do_exit(p1);
}

void C_HilClient::_Run(void *pc_Self, long p1, long /*p2*/)
{
    static_cast<C_HilClient*>(pc_Self)->Run(p1);
}

void C_HilClient::_Trigger(void *pc_Self, long p1, long /*p2*/)
{
    static_cast<C_HilClient*>(pc_Self)->Trigger(p1);
}

void C_HilClient::_Wait(void *pc_Self, long /*p1*/, long /*p2*/)
{
    static_cast<C_HilClient*>(pc_Self)->Wait();
}

void C_HilClient::_Init(void *pc_Self, long p1, long /*p2*/)
{
    static_cast<C_HilClient*>(pc_Self)->Init(p1);
}

void C_HilClient::_Exit(void *pc_Self, long p1, long /*p2*/)
{
    static_cast<C_HilClient*>(pc_Self)->Exit(p1);
}
