#include "Cdd_Ucb_Cfg.h"


const unsigned char Ucb_DBG_EcuKey[16u] = 
{
    0x07, 0x2B, 0x50, 0x4A, 0x4A, 0xBB, 0x5D, 0xAF, 0xE3, 0xFC, 0x83, 0x7D, 0xF8, 0xAB, 0x22, 0x4B
};

//For Seed_UCB_PW_demo only, NOT for mass production!!!
static const unsigned char UCB_PW_SEED[32u] = 
{
    0x20, 0x79, 0xD8, 0x42, 0x06, 0xBC, 0xE0, 0x93, 0x6B, 0x76, 0xAE, 0x8E, 0x85, 0xCD, 0xBB, 0x81, 0x20, 0x79, 0xD8, 0x42, 0x06, 0xBC, 0xE0, 0x93, 0x6B, 0x76, 0xAE, 0x8E, 0x85, 0xCD, 0xBB, 0x81
};



#if (UCB_DBG_PASSWORD_CONST_SWITCH == STD_ON)
const uint32 Ucb_DBG_Password[8u]=
{
    UCB_PASSWARD_PW0,
    UCB_PASSWARD_PW1,
    UCB_PASSWARD_PW2,
    UCB_PASSWARD_PW3,
    UCB_PASSWARD_PW4,
    UCB_PASSWARD_PW5,
    UCB_PASSWARD_PW6,
    UCB_PASSWARD_PW7
};
#endif

const uint32 Ucb_PFlash_Password[8u]=
{
    UCB_PFlash_PASSWARD_PW0,
    UCB_PFlash_PASSWARD_PW1,
    UCB_PFlash_PASSWARD_PW2,
    UCB_PFlash_PASSWARD_PW3,
    UCB_PFlash_PASSWARD_PW4,
    UCB_PFlash_PASSWARD_PW5,
    UCB_PFlash_PASSWARD_PW6,
    UCB_PFlash_PASSWARD_PW7
};









