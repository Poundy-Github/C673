#ifndef DECODER_BASE_H
#define DECODER_BASE_H

#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;


/* -------------------------------------------------------------------------------- */
/*  MACROS                                                                          */
/* -------------------------------------------------------------------------------- */
#ifdef _MSC_VER
// MS Visual Studio
#define EXCEPTION(x, ...) BaseDecoder::Exception(__FUNCTION__, __FILE__, __LINE__, x, __VA_ARGS__)
#define snprintf _snprintf
#else
// GNU
#define EXCEPTION(x, args...) BaseDecoder::Exception(__FUNCTION__, __FILE__, __LINE__, x, ##args)
#endif


/* -------------------------------------------------------------------------------- */
/*  Type definitions                                                                */
/* -------------------------------------------------------------------------------- */
typedef enum {
  FrameworkID,
  DebayerRightID,
  DebayerLeftID,
  RectifierID,
  DummyID0,
  SgmID,
  PowerflowID,
  HoglrfID,
  DummyID1
} BlockIDs_e;

//typedef enum {
//  RectifierLutLeft,
//  RectifierLutRight
//} ParameterTypes_e;

struct BlockIdRegAddr_s {
  unsigned short RegisterAddress:12;
  unsigned short BlockId:4;
};

union BlockIdRegAddr_u {
  unsigned short    raw_value;
  BlockIdRegAddr_s  structured;  
};

struct ConfigDataHeader_s {
  unsigned int VirtualAddress;
  unsigned int DataLength;
};



/* -------------------------------------------------------------------------------- */
/*  Class BaseDecoder (BaseClass)                                                   */
/* -------------------------------------------------------------------------------- */
class BaseDecoder
{
private:


protected:
  map<int, int> m_registers;
  bool m_ConfigReceived;


public:
  BaseDecoder(){};
  virtual ~BaseDecoder(){};

  static const unsigned int ui32_VIRTUAL_ADDRESS_WRITEREG_GEN = 0x32000000U;
  static const unsigned int ui32_VIRTUAL_ADDRESS_MASK         = 0xFFFFFFF0U;

  // to be implemented in derived model decoders. 
  // will call decodeStream from BaseDecoder with corresponding block_id and do model specific stuff
  virtual void decodeStream(unsigned short* register_stream, int stream_size) = 0;

  // check if register_stream contain register config data for FPGA algo blocks
  static bool isRegisterStream(unsigned short* register_stream);

  // set register file contents from MTS context   
  void decodeStream(BlockIDs_e block_id, unsigned short* register_stream, int stream_size);

  // clear register map
  void resetDecoder();

  // swap bytes of a 16bit value
  //unsigned short swapEndianess(unsigned short valueIn);
  inline unsigned short swapEndianess(unsigned short valueIn)
  {
    return _byteswap_ushort(valueIn);
  }

  // register access
  int getRegisterValue(int address);
  map<int, int> &getRegisters();    
  void setRegisterValue(int address, int data);
  bool isRegisterSet(int address);  
  bool ConfigReceived(void);



  /*----------------------------------------------------------------------------------------------------------*/
  /* Throws an exception with debug data...                                                                   */
  /* Use the EXCEPTION() makro, this will automatically insert function, file and line!                       */
  /*----------------------------------------------------------------------------------------------------------*/
  static void Exception(const char * function, const char * file, const unsigned int line, char * fmt, ...);
};

#endif