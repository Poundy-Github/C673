#include "base_decoder.h"
#include <stdarg.h>

/* -------------------------------------------------------------------------------- */
/*  Register settings stream parser for MTS-based fpga resimulation 				        */
/*  Parses register streams written by the DSP to configure the FPGA                */    
/*  and sets the internal register map                                              */
/* -------------------------------------------------------------------------------- */

// FEX - FPGA Stream generation
//uint16 addrIDCombined = ((blockID<<12U)&0xF000U) | ((addr>>1)&0x0FFFU);
//  m_BufferMemory[m_BufferCurrentSize    ] = (reinterpret_cast<uint8 *>(&addrIDCombined))[1];
//  m_BufferMemory[m_BufferCurrentSize + 1U] = (reinterpret_cast<uint8 *>(&addrIDCombined))[0];
//  m_BufferMemory[m_BufferCurrentSize + 2U] = (reinterpret_cast<uint8 *>(&val) )[1];
//  m_BufferMemory[m_BufferCurrentSize + 3U] = (reinterpret_cast<uint8 *>(&val) )[0];

//void BaseDecoder::decodeStream(BlockIDs_e block_id, unsigned short* register_stream, int stream_size)
//{
//  unsigned short tmp, tmp_addr, tmp_data, tmp_block_id;
//
//  if(stream_size%2!=0) EXCEPTION("Illegal size for register stream");
//
//  for int i= 0; i<stream_size; stream_size+= 2)
//  {
//    // swap bytes
//    tmp= (((register_stream[i] & 0xFF) << 8) | ((register_stream[i] & 0xFF00)>>8));
//    tmp_addr      = ((tmp & 0x0FFF)<<1);
//    tmp_block_id  = ((tmp & 0xF000)>>12);
//
//    if (tmp_block_id==block_id)
//    {
//      // swap bytes
//      tmp_data= (((register_stream[i+1] & 0xFF) << 8) | ((register_stream[i+1] & 0xFF00)>>8));
//      m_registers[tmp_addr] = tmp_data;
//    }
//  }
//}

bool BaseDecoder::isRegisterStream(unsigned short* register_stream)
{
  if(register_stream == NULL) EXCEPTION("Nullpointer register stream");

  ConfigDataHeader_s  *pConfigDataHeader;
  pConfigDataHeader = (ConfigDataHeader_s*)register_stream;

  if((pConfigDataHeader->VirtualAddress & ui32_VIRTUAL_ADDRESS_MASK) == ui32_VIRTUAL_ADDRESS_WRITEREG_GEN) 
    return true;
  else                                                                               
    return false;
}

void BaseDecoder::decodeStream(BlockIDs_e block_id, unsigned short* register_stream, int stream_size)
{  
  ConfigDataHeader_s  *pConfigDataHeader;
  BlockIdRegAddr_u     BlockIdRegAddr;
  int StreamStart = sizeof(ConfigDataHeader_s)/sizeof(unsigned short);

  if(register_stream == NULL)               EXCEPTION("Nullpointer register stream");
  if(stream_size % 2 != 0)                  EXCEPTION("Illegal size for register stream");
  if(!isRegisterStream(register_stream))    EXCEPTION("No valid register stream");

  pConfigDataHeader = (ConfigDataHeader_s*)register_stream;

  for(int i= StreamStart; i<stream_size; i+= 2)
  {
    BlockIdRegAddr.raw_value= swapEndianess(register_stream[i]);
    if (BlockIdRegAddr.structured.BlockId == block_id) {
      m_registers[BlockIdRegAddr.structured.RegisterAddress << 1] = swapEndianess(register_stream[i+1]);    
      m_ConfigReceived= true;
    }
  }
}

//unsigned short BaseDecoder::swapEndianess(unsigned short valueIn)
//{
//  return (((valueIn & 0xFF) << 8) | ((valueIn & 0xFF00)>>8));
//}


void BaseDecoder::resetDecoder()
{
  m_registers.clear();
  m_ConfigReceived  = false;
}


int BaseDecoder::getRegisterValue(int address) {

  if (m_registers.end() != m_registers.find(address)) {
    return m_registers[address];
  }
  EXCEPTION("Can't find register address 0x%X", address);
  return -1;
}

map<int, int> &BaseDecoder::getRegisters()
{
  return m_registers;
}


void BaseDecoder::setRegisterValue(int address, int data) 
{
  m_registers[address]= data;
}


bool BaseDecoder::isRegisterSet(int address)
{
  if (m_registers.end() != m_registers.find(address))
    return true;
  else
    return false;
}

bool BaseDecoder::ConfigReceived(void)
{
  return m_ConfigReceived;
}



/*----------------------------------------------------------------------------------------------------*/
/*  Generalized output (printf) function, may be changed to log file or similar, whatever is needed   */ 
/*  Use the EXCEPTION() makro, this will automatically insert function, file and line!                */
/*----------------------------------------------------------------------------------------------------*/
void BaseDecoder::Exception(const char * function, const char * file, const unsigned int line, char * fmt, ...) {
  va_list arg;
  int len;
  char tmp[8192];
  char tmp2[8192];

  va_start(arg, fmt);
  len = vsnprintf(tmp, sizeof(tmp)-sizeof(char), fmt, arg);
  va_end(arg);
  len = snprintf(tmp2, sizeof(tmp2)-sizeof(char), "%s (function %s() at %s:%u)\n", tmp, function, file, line);

  throw (char*) tmp2;
}