/*
 *  ======== netHooks.c ========
 *  This file contains hook functions to start the send and recv threads
 */

#include <xdc/std.h>
#include <ti/ndk/inc/netmain.h>


#define ALGO_SRV_TASK_PRIO     OS_TASKPRINORM
#define ALGO_SRV_STACK_SIZE    0x40000


static HANDLE hAlgoServer = 0;


int dtask_tcp_algo_callback(SOCKET s, UINT32 v);

static int dtask_tcp_algo_wrapper(SOCKET s, UINT32 v)
{
  return dtask_tcp_algo_callback(s, v);
}


void netOpenHook()
{
  // Create algo wrapper
  hAlgoServer = DaemonNew(SOCK_STREAMNC, 0, 7, dtask_tcp_algo_wrapper, ALGO_SRV_TASK_PRIO, ALGO_SRV_STACK_SIZE, 0, 3);

  printf("Created algo server (0x%p) with stack size %d [bytes] (PRIO:%i)\n", (void*) hAlgoServer,
      (int) ALGO_SRV_STACK_SIZE, ALGO_SRV_TASK_PRIO);
}


void netCloseHook()
{
  if (hAlgoServer)
  {
    DaemonFree(hAlgoServer);
  }
}
