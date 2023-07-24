#ifndef ALGO_SCHEDULER_H
#define ALGO_SCHEDULER_H

#include <stdio.h>
#include <netmain.h>
#include <_stack.h>

#define FATAL_ERROR(str) printf("%s:%d -> %s\n", __FILE__, __LINE__, str);
#define AC_NAME_LENGTH 1024

typedef enum {
    e_float32      = 0, 
    e_float64      = 1, 
    e_sint8        = 2, 
    e_sint16       = 3, 
    e_sint32       = 4, 
    e_sint64       = 5,
    e_uint8        = 6, 
    e_uint16       = 7, 
    e_uint32       = 8, 
    e_uint64       = 9,
    e_array_uint8  = 10, 
    e_array_uint16 = 11, 
    e_array_uint32 = 12
} E_DataType;

/* Begin: SimV3 compatibility support */
typedef enum {
  simUI8_t = 0,
  simI8_t,
  simUI16_t,
  simI16_t,
  simUI32_t,
  simI32_t,
  simF32_t,
  simI64_t,
  simF64_t,
  simOPAQUE_t,
  simREFERENCE_t,
  simUI64_t
}SimPortDataTypes_t;
/* End: SimV3 compatibility support */

typedef enum
{
    e_REQUEST,
    e_PROVIDE
} E_PortType;

struct S_ValueDescription
{
    char ac_name[AC_NAME_LENGTH];
    E_DataType e_DataType;
    void *pAddress;
    int  size;
};

class C_AlgoBase
{
protected:
    C_AlgoBase();

    virtual void Init(int sl32_p) = 0;
    virtual void Run(int sl32_p) = 0;
    virtual void Exit(int sl32_p) = 0;

    void AddPort(
        E_PortType e_PortType,
        const char *name, 
        E_DataType e_DataType,
        void *pAddress,
        int size);

    /* Begin: SimV3 compatibility support */
    void AddReceivePort(
        const char *PortName,
        SimPortDataTypes_t eType,
        void *pVoid, 
        int Size);
    void AddReceivePort(
        const char *PortName,
        SimPortDataTypes_t eType,
        void *pVoid,
        int Size,
        unsigned int PortMode);
    void AddProvidePort(
        const char *PortName,
        SimPortDataTypes_t eType,
        void *pVoid,
        int Size);
    E_DataType e_TranslateEnum_SimV3toHil(SimPortDataTypes_t e_SimV3Type);
    /* End: SimV3 compatibility support */

private:
    static const int sl_MaxPorts = 4096;
    S_ValueDescription as_InputPorts[sl_MaxPorts];
    S_ValueDescription as_OutputPorts[sl_MaxPorts];
    float m_f32_RunTimeSI;
    int m_i32_UsedStack;

    int sl_NumInputs;
    int sl_NumOutputs;

    virtual void getInputPortDefinitions(
        const S_ValueDescription *&rpInputs,
        int &rsl_NumInputs) const
    {
        rpInputs = as_InputPorts;
        rsl_NumInputs = sl_NumInputs;
    }

    virtual void getOutputPortDefinitions(
        const S_ValueDescription *&rpOutputs,
        int &rsl_NumOutputs) const
    {
        rpOutputs = as_OutputPorts;
        rsl_NumOutputs = sl_NumOutputs;
    }

private:
    static C_AlgoBase *pc_Singleton;
    friend class C_AlgoScheduler;
};

class C_AlgoScheduler
{
public:
    C_AlgoScheduler();

    int dtask_tcp_algo(SOCKET s);
    

    static int dtask_tcp_algo_callback(SOCKET s, UINT32 unused);
private:
    void init();

    void feedScheduler(void *buf, int size);
    void executeInit();
    void executeRun();
    void executeExit();
    void executeGet();
    void *getPointerToCurrentAddress(int sl_Size);

    const S_ValueDescription *pas_Inputs;
    int sl_NumInputs;

    const S_ValueDescription *pas_Outputs;
    int sl_NumOutputs;

    static C_AlgoScheduler *pc_Singleton;

    enum 
    {
        e_READ_CMD,
        e_READ_COUNT,
        e_READ_ADDRESS,
        e_READ_SIZE,
        e_READ_VALUE,
        e_READ_FUNC_PARAM
    } e_SchedulerState;

    int sl_NextTokenSize;
    int sl_NextTokenValid;
    void *pv_NextTokenDest;

    unsigned char ub_Cmd;
    unsigned char ub_Cnt;
    unsigned int ui32_Address;
    unsigned int ui32_Size;
    int sl32_FuncParam;

    SOCKET socket;

};

#endif
