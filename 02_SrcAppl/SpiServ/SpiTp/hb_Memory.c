
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "hb_Memory.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define MEMORY_BUF_8B_NUM 0u
#define MEMORY_BUF_16B_NUM 0u
#define MEMORY_BUF_32B_NUM 0u
#define MEMORY_BUF_64B_NUM 16u
#define MEMORY_BUF_128B_NUM 8u
#define MEMORY_BUF_256B_NUM 8u
#define MEMORY_BUF_512B_NUM 0u
#define MEMORY_BUF_1024B_NUM 8u
#define MEMORY_BUF_2048B_NUM 8u
#define MEMORY_BUF_4096B_NUM 8u

#define MEMORY_BLOCK_TYPE_NUM 10u

#define MEMORY_BUF_TOTLE_NUB  \
  (MEMORY_BUF_8B_NUM +        \
   MEMORY_BUF_16B_NUM +       \
   MEMORY_BUF_32B_NUM +       \
   MEMORY_BUF_64B_NUM +       \
   MEMORY_BUF_128B_NUM +      \
   MEMORY_BUF_256B_NUM +      \
   MEMORY_BUF_512B_NUM +      \
   MEMORY_BUF_1024B_NUM +     \
   MEMORY_BUF_2048B_NUM +     \
   MEMORY_BUF_4096B_NUM)

#define MEMORY_BUF_TOTLE_SIZE     \
  (8 * MEMORY_BUF_8B_NUM +        \
   16 * MEMORY_BUF_16B_NUM +      \
   32 * MEMORY_BUF_32B_NUM +      \
   64 * MEMORY_BUF_64B_NUM +      \
   128 * MEMORY_BUF_128B_NUM +    \
   256 * MEMORY_BUF_256B_NUM +    \
   512 * MEMORY_BUF_512B_NUM +    \
   1024 * MEMORY_BUF_1024B_NUM +  \
   2048 * MEMORY_BUF_2048B_NUM +  \
   4096 * MEMORY_BUF_4096B_NUM)

/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/
typedef struct {
  uint32 size;
  boolean used;
} MemoryHeaderType;

typedef struct {
  MemoryHeaderType header;
  void* addr;
} MemoryPoolInfoType;

typedef struct {
  uint16 blockSize;
  uint16 blockNum;
} MemoryBlockInfoType;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
static MemoryBlockInfoType Memory_blockInfo[MEMORY_BLOCK_TYPE_NUM] = {
    {8, MEMORY_BUF_8B_NUM},
    {16, MEMORY_BUF_16B_NUM},
    {32, MEMORY_BUF_32B_NUM},
    {64, MEMORY_BUF_64B_NUM},
    {128, MEMORY_BUF_128B_NUM},
    {256, MEMORY_BUF_256B_NUM},
    {512, MEMORY_BUF_512B_NUM},
    {1024, MEMORY_BUF_1024B_NUM},
    {2048, MEMORY_BUF_2048B_NUM},
    {4096, MEMORY_BUF_4096B_NUM}
};

#pragma section ".ipcram"
static uint8 Memory_pool[MEMORY_BUF_TOTLE_SIZE] = {0};
#pragma section

static MemoryPoolInfoType Memory_poolInfo[MEMORY_BUF_TOTLE_NUB];

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
static void hb_Memory_initPool(void* poolPtr, MemoryPoolInfoType* poolInfo,
                               MemoryBlockInfoType* blockInfo, uint16 blockNo);
/******************************************************************************/
/*-------------------------_Globale Function----------------------------------*/
/******************************************************************************/
void hb_Memory_Init(void) {
  hb_Memory_initPool(&Memory_pool[0], &Memory_poolInfo[0], &Memory_blockInfo[0],
                     MEMORY_BLOCK_TYPE_NUM);
}

void* hb_Memory_malloc(uint32 size) {
  uint16 i;
  HB_MEMORY_ENTER();
  void* addr = NULL_PTR;
  for (i = 0; i < MEMORY_BUF_TOTLE_NUB; i++) {
    if ((Memory_poolInfo[i].header.used == FALSE) &&
        (Memory_poolInfo[i].header.size >= size)) {
      Memory_poolInfo[i].header.used = TRUE;
      addr = Memory_poolInfo[i].addr;
      break;
    }
  }
  HB_MEMORY_EXIT();
  return addr;
}

void hb_Memory_free(void* addr) {
  uint16 i;
  HB_MEMORY_ENTER();
  for (i = 0; i < MEMORY_BUF_TOTLE_NUB; i++) {
    if (addr == Memory_poolInfo[i].addr) {
      Memory_poolInfo[i].header.used = FALSE;
      addr = NULL_PTR;
      break;
    }
  }
  HB_MEMORY_EXIT();
}


// memory control
void *hb_memset(void *s, int c, uint32 n) {
  int i = 0;
  char *ss = (char *)s;

  for (i = 0; i < n; i++) {
    ss[i] = c;
  }
  return s;
}

void *hb_memcpy(void *dest, const void *src, uint32 n) {
  int i = 0;
  char *d = (char *)dest;
  const char *s = (char *)src;

  for (i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

int hb_memcmp(const void *cs, const void *ct, uint32 count) {
  const unsigned char *su1, *su2;
  int res = 0;

  for (su1 = (const unsigned char*)cs, su2 = (const unsigned char*)ct; 0 < count; ++su1, ++su2, count--) {
    if ((res = *su1 - *su2) != 0) {
      break;
    }
  }
  return res;
}

int hb_strcmp(const char *cs, const char *ct) {
  unsigned char c1, c2;

  while (1) {
    c1 = *cs++;
    c2 = *ct++;
    if (c1 != c2) {
      return c1 < c2 ? -1 : 1;
    }
    if (!c1) {
      break;
    }
  }

  return 0;
}

uint32 hb_strlen(const char *s) {
  const char *sc;

  for (sc = s; *sc != '\0'; ++sc)
    /* nothing */;
  return sc - s;
}
/******************************************************************************/
/*---------------------------Static Function----------------------------------*/
/******************************************************************************/
static void hb_Memory_initPool(void* poolPtr, MemoryPoolInfoType* poolInfo,
                               MemoryBlockInfoType* blockInfo, uint16 blockNo) {
  uint16 i;
  uint16 j;
  uint16 index;
  uint32 addr = 0;

  index = 0;
  addr = (uint32)poolPtr;

  for (i = 0; i < blockNo; i++) {
    for (j = 0; j < blockInfo[i].blockNum; j++) {
      poolInfo[index].header.used = FALSE;
      poolInfo[index].header.size = blockInfo[i].blockSize;
      poolInfo[index].addr = (void *)addr;
      index++;
      addr += blockInfo[i].blockSize;
    }
  }
  return;
}
