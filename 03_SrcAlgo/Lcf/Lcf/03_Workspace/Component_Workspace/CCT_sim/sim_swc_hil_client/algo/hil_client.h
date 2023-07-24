#ifndef HIL_CLIENT_BASE
#define HIL_CLIENT_BASE

#include "sim_swc_base.h"
#include "ctk_img_type.h"
#include "sim_def.h"
#include <map>

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

typedef enum
{
    e_REQUEST,
    e_PROVIDE,
    e_PORTINFO,
    e_PORTDESC
} E_PortType;

struct S_ValueDescription
{
    char name[1024];
    E_DataType e_DataType;
    int  size;
    void *pData;
};

class C_HilClient : public CSimSwcBase
{
public:
    C_HilClient();
    ~C_HilClient();

    long StartUP();

    static void _Run(void *pc_Self, long sl_p1, long sl_p2);
    void Run(long p1);

    static void _Trigger(void *pc_Self, long sl_p1, long sl_p2);
    void Trigger(long p1);

    static void _Wait(void *pc_Self, long sl_p1, long sl_p2);
    void Wait();

    static void _Init(void *pc_Self, long sl_p1, long sl_p2);
    void Init(long p1);

    static void _Exit(void *pc_Self, long sl_p1, long sl_p2);
    void Exit(long p1);

    void ClientCallInit(long p1);
    void ClientCallRun(long p1);
    void ClientCallTrigger(long p1);
    void ClientCallWait();
    void ClientCallExit(long p1);

private:
    IClientAction *m_pAlgoCalcDone;

    static const int sl_MaxPorts = 1024;
    S_ValueDescription as_InputPorts[sl_MaxPorts];
    S_ValueDescription as_OutputPorts[sl_MaxPorts];

    unsigned long sl_NumInputs;
    unsigned long sl_NumOutputs;
    bool b_Initialized;

    std::map<std::string, void *> c_ImgByName;
};

#endif
