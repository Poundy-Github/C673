/******************************************************************************/
/**
@file			AES_Encrypt.c
@copyright		(C) Texas Instruments
@version		1.2
@date			June 2013
*
@author			Juergen Austen, Maximilian Albrecht
*
@language		ANSI/ISO C for MSP430
*
@description	Provides AES Encryption functions to calculate Signatures
*
*******************************************************************************/
#include "AES_Encrypt.h"
/******************************************************************************
* - Defines
******************************************************************************/
#define BC  4

/******************************************************************************
* - Data Types
******************************************************************************/
struct stBitType  /*TBOX  ????WINDOWS ??LINUX ??§³????  ???*/
{
  unsigned char Bit0   : 1;
  unsigned char Bit1   : 1;
  unsigned char Bit2   : 1;
  unsigned char Bit3   : 1;
  unsigned char Bit4   : 1;
  unsigned char Bit5   : 1;
  unsigned char Bit6   : 1;
  unsigned char Bit7   : 1;
};

union unBitConvert
{
  struct stBitType  BitValue;
  unsigned char     ucValue;
};
/******************************************************************************
* - Variables
******************************************************************************/
const unsigned char S_Box[256] = {
 99, 124, 119, 123, 242, 107, 111, 197,  48,   1, 103,  43, 254, 215, 171, 118,
202, 130, 201, 125, 250,  89,  71, 240, 173, 212, 162, 175, 156, 164, 114, 192,
183, 253, 147,  38,  54,  63, 247, 204,  52, 165, 229, 241, 113, 216,  49,  21,
  4, 199,  35, 195,  24, 150,   5, 154,   7,  18, 128, 226, 235,  39, 178, 117,
  9, 131,  44,  26,  27, 110,  90, 160,  82,  59, 214, 179,  41, 227,  47, 132,
 83, 209,   0, 237,  32, 252, 177,  91, 106, 203, 190,  57,  74,  76,  88, 207,
208, 239, 170, 251,  67,  77,  51, 133,  69, 249,   2, 127,  80,  60, 159, 168,
 81, 163,  64, 143, 146, 157,  56, 245, 188, 182, 218,  33,  16, 255, 243, 210,
205,  12,  19, 236,  95, 151,  68,  23, 196, 167, 126,  61, 100,  93,  25, 115,
 96, 129,  79, 220,  34,  42, 144, 136,  70, 238, 184,  20, 222,  94,  11, 219,
224,  50,  58,  10,  73,   6,  36,  92, 194, 211, 172,  98, 145, 149, 228, 121,
231, 200,  55, 109, 141, 213,  78, 169, 108,  86, 244, 234, 101, 122, 174,   8,
186, 120,  37,  46,  28, 166, 180, 198, 232, 221, 116,  31,  75, 189, 139, 138,
112,  62, 181, 102,  72,   3, 246,  14,  97,  53,  87, 185, 134, 193,  29, 158,
225, 248, 152,  17, 105, 217, 142, 148, 155,  30, 135, 233, 206,  85,  40, 223,
140, 161, 137,  13, 191, 230,  66, 104,  65, 153,  45,  15, 176,  84, 187,  22,
};

const unsigned char Inv_S_Box[256] = {
 82,   9, 106, 213,  48,  54, 165,  56, 191,  64, 163, 158, 129, 243, 215, 251,
124, 227,  57, 130, 155,  47, 255, 135,  52, 142,  67,  68, 196, 222, 233, 203,
 84, 123, 148,  50, 166, 194,  35,  61, 238,  76, 149,  11,  66, 250, 195,  78,
  8,  46, 161, 102,  40, 217,  36, 178, 118,  91, 162,  73, 109, 139, 209,  37,
114, 248, 246, 100, 134, 104, 152,  22, 212, 164,  92, 204,  93, 101, 182, 146,
108, 112,  72,  80, 253, 237, 185, 218,  94,  21,  70,  87, 167, 141, 157, 132,
144, 216, 171,   0, 140, 188, 211,  10, 247, 228,  88,   5, 184, 179,  69,   6,
208,  44,  30, 143, 202,  63,  15,   2, 193, 175, 189,   3,   1,  19, 138, 107,
 58, 145,  17,  65,  79, 103, 220, 234, 151, 242, 207, 206, 240, 180, 230, 115,
150, 172, 116,  34, 231, 173,  53, 133, 226, 249,  55, 232,  28, 117, 223, 110,
 71, 241,  26, 113,  29,  41, 197, 137, 111, 183,  98,  14, 170,  24, 190,  27,
252,  86,  62,  75, 198, 210, 121,  32, 154, 219, 192, 254, 120, 205,  90, 244,
 31, 221, 168,  51, 136,   7, 199,  49, 177,  18,  16,  89,  39, 128, 236,  95,
 96,  81, 127, 169,  25, 181,  74,  13,  45, 229, 122, 159, 147, 201, 156, 239,
160, 224,  59,  77, 174,  42, 245, 176, 200, 235, 187,  60, 131,  83, 153,  97,
 23,  43,   4, 126, 186, 119, 214,  38, 225, 105,  20,  99,  85,  33,  12, 125
};


const unsigned char RCON[16] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f};

unsigned char ucSig[4][4];
unsigned char ucKey[4][4],RCON_Count;

unsigned char testttdata[16];

/******************************************************************************
* - Functions
******************************************************************************/
/******************************************************************************
 *
 * @brief	Sub-functions of the AES encryption routine
 *
 * @date	June 2013
 *
 * @version	1.0
 *
 ******************************************************************************/
void AddRoundKey(void)
{// Exor corresponding text input and round key input bytes
	unsigned char i, j;

	for (i=0; i<4; i++)
   		for (j= 0; j<BC; j++)
        	ucSig[i][j] ^= ucKey[i][j];
}

void SubBytes(void)
{	// Replace every byte of the input by the byte at that place
	// in the nonlinear S-box.
  	// This routine implements SubBytes and InvSubBytes
	unsigned char i, j;

	for (i=0; i<4; i++)
		for (j=0; j<BC; j++)
       		ucSig[i][j] = S_Box[ucSig[i][j]];
}

void InvSubBytes(void)
{   // Replace every byte of the input by the byte at that place
    // in the nonlinear S-box.
    // This routine implements SubBytes and InvSubBytes
unsigned char i, j;

for (i=0; i<4; i++)
for (j=0; j<BC; j++)
       ucSig[i][j] = Inv_S_Box[ucSig[i][j]];
}

void ShiftRows(void)
{	// Row 0 remains unchanged
	// The other three rows are shifted a variable amount
  	unsigned char ucTemp;
                                                                                // rotate over 1 byte
  	ucTemp = ucSig[0][1];                                                   // set temp value
	ucSig[0][1] = ucSig[1][1];
	ucSig[1][1] = ucSig[2][1];
	ucSig[2][1] = ucSig[3][1];
	ucSig[3][1] = ucTemp;

	// rotate over 2 bytes
	ucTemp = ucSig[0][2];                                                   // set temp value
	ucSig[0][2] = ucSig[2][2];
	ucSig[2][2] = ucTemp;

	ucTemp = ucSig[1][2];                                                   // set temp value
	ucSig[1][2] = ucSig[3][2];
	ucSig[3][2] = ucTemp;

  	// rotate over 3 bytes
  	ucTemp = ucSig[1][3];                                                   // set temp value
  	ucSig[1][3] = ucSig[0][3];
  	ucSig[0][3] = ucSig[3][3];
  	ucSig[3][3] = ucSig[2][3];
  	ucSig[2][3] = ucTemp;
}

void InvShiftRows(void)
{// Row 0 remains unchanged
// The other three rows are shifted a variable amount
  unsigned char ucTemp;
                                                                                // rotate over 1 byte
  ucTemp = ucSig[0][1];                                                   // set temp value
  ucSig[0][1] = ucSig[3][1];
  ucSig[3][1] = ucSig[2][1];
  ucSig[2][1] = ucSig[1][1];
  ucSig[1][1] = ucTemp;

  // rotate over 2 bytes
  ucTemp = ucSig[0][2];                                                   // set temp value
  ucSig[0][2] = ucSig[2][2];
  ucSig[2][2] = ucTemp;

  ucTemp = ucSig[1][2];                                                   // set temp value
  ucSig[1][2] = ucSig[3][2];
  ucSig[3][2] = ucTemp;

  // rotate over 3 bytes
  ucTemp = ucSig[0][3];                                                   // set temp value
  ucSig[0][3] = ucSig[1][3];
  ucSig[1][3] = ucSig[2][3];
  ucSig[2][3] = ucSig[3][3];
  ucSig[3][3] = ucTemp;

}

unsigned char modMult02(unsigned char x)
{
  union unBitConvert  Input,Output;

  Input.ucValue = x;

  Output.BitValue.Bit0 = Input.BitValue.Bit7;
  Output.BitValue.Bit7 = Input.BitValue.Bit6;
  Output.BitValue.Bit6 = Input.BitValue.Bit5;
  Output.BitValue.Bit5 = Input.BitValue.Bit4;
  Output.BitValue.Bit2 = Input.BitValue.Bit1;

  Output.BitValue.Bit1 = Input.BitValue.Bit0 ^ Input.BitValue.Bit7;
  Output.BitValue.Bit3 = Input.BitValue.Bit2 ^ Input.BitValue.Bit7;
  Output.BitValue.Bit4 = Input.BitValue.Bit3 ^ Input.BitValue.Bit7;

  return Output.ucValue;
}

unsigned char modMult03(unsigned char x)
{
  return (x ^ modMult02(x));
}

unsigned char modMult04(unsigned char x)
{
  return (modMult02(modMult02(x)));
}

unsigned char modMult08(unsigned char x)
{
  return (modMult02(modMult02(modMult02(x))));
}

unsigned char modMult09(unsigned char x)
{// 9 = 1 + 8
  return (x ^ modMult08(x));
}

unsigned char modMult0B(unsigned char x)
{// 11 = 8 + 2 + 1
  return (modMult08(x) ^ modMult02(x) ^ x);
}

unsigned char modMult0D(unsigned char x)
{// 13 = 8 + 4 + 1
  return (modMult08(x) ^ modMult04(x) ^ x);
}

unsigned char modMult0E(unsigned char x)
{// 14 = 8 + 4 + 2
  return (modMult08(x) ^ modMult04(x) ^ modMult02(x));
}

void MixColumns(void)
{  // Mix the four bytes of every column in a linear way
   unsigned char MixResult[4][4],i,j;

    for (i=0; i<4; i++)
      {
        MixResult[i][0] = modMult02(ucSig[i][0]) ^ modMult03(ucSig[i][1]) ^ ucSig[i][2] ^ ucSig[i][3];
        MixResult[i][1] = modMult02(ucSig[i][1]) ^ modMult03(ucSig[i][2]) ^ ucSig[i][3] ^ ucSig[i][0];
        MixResult[i][2] = modMult02(ucSig[i][2]) ^ modMult03(ucSig[i][3]) ^ ucSig[i][0] ^ ucSig[i][1];
        MixResult[i][3] = modMult02(ucSig[i][3]) ^ modMult03(ucSig[i][0]) ^ ucSig[i][1] ^ ucSig[i][2];
      }
    for (i=0 ; i<4 ; i++)
        for (j=0 ; j<4 ; j++)
            ucSig[j][i] = MixResult[j][i];
}

void InvMixColumns(void)
{  // Mix the four bytes of every column in a linear way
	unsigned char MixResult[4][4],i,j;
		
    for (i=0; i<4; i++)
      {   
      	if(i==2){};
        MixResult[i][0] = modMult0E(ucSig[i][0]) ^ modMult09(ucSig[i][3]) ^ modMult0D(ucSig[i][2]) ^ modMult0B(ucSig[i][1]);
        MixResult[i][1] = modMult0E(ucSig[i][1]) ^ modMult09(ucSig[i][0]) ^ modMult0D(ucSig[i][3]) ^ modMult0B(ucSig[i][2]);
        MixResult[i][2] = modMult0E(ucSig[i][2]) ^ modMult09(ucSig[i][1]) ^ modMult0D(ucSig[i][0]) ^ modMult0B(ucSig[i][3]);
        MixResult[i][3] = modMult0E(ucSig[i][3]) ^ modMult09(ucSig[i][2]) ^ modMult0D(ucSig[i][1]) ^ modMult0B(ucSig[i][0]);
      }
    for ( i=0 ; i<4 ; i++)
        for (j=0 ; j<4 ; j++)
            ucSig[j][i] = MixResult[j][i];
}

void KeySchedule(void)
{
	unsigned char CipherResult[4][4],i,j;

    CipherResult[3][0] = ucKey[3][1];                                           // Rotate last col of Key
    CipherResult[3][1] = ucKey[3][2];
    CipherResult[3][2] = ucKey[3][3];
    CipherResult[3][3] = ucKey[3][0];

    for (i=0; i<4; i++)                                                         // Add Key and RCON to last col
      {
        CipherResult[3][i] = S_Box[CipherResult[3][i]];                         // substitute last col with sbox
        if (i)
           CipherResult[0][i] = ucKey[0][i] ^ CipherResult[3][i];
        else
           CipherResult[0][i] = ucKey[0][i] ^ CipherResult[3][i] ^ RCON[RCON_Count];

        CipherResult[1][i] = ucKey[1][i] ^ CipherResult[0][i];                  // Add second col = Key 2 col + Result 1 col
        CipherResult[2][i] = ucKey[2][i] ^ CipherResult[1][i];
        CipherResult[3][i] = ucKey[3][i] ^ CipherResult[2][i];
      }

    for (i=0; i<4; i++)
      for (j=0; j<4; j++)
        {
           ucKey[i][j] = CipherResult[i][j];
        }
    RCON_Count++;
}
/******************************************************************************
 *
 * @brief	AES-128bit Encryption routine. Encrypts input data with 128 bit key
 *
 * @date	June 2013
 *
 * @version	1.0
 * @param	ucInput_Chal:	Array contains the Challenge
 * 							(=information to encrypt). Will be overwritten!!!
 * 							On return, this array contains the encryption result
 * 			ucInputKey:		Array containing the encryption key
 *
 ******************************************************************************/
void AES128_Encrypt(unsigned char *ucInput_Chal, unsigned char *ucInputKey)
{
	unsigned char i,k;
	
	RCON_Count = 0;
	for (i=0; i<4;i++)
		for (k=0; k<4;k++)
		{
        ucSig[i][k] = ucInput_Chal[i*4+k];
        ucKey[i][k] = ucInputKey[i*4+k];
      	}

	AddRoundKey();
	for (i=0; i<(9 + ROUND_ADDER) ; i++) 
    {
		SubBytes();
		ShiftRows();
		MixColumns();
		KeySchedule();
		AddRoundKey();
    }
	SubBytes();
	ShiftRows();
	//Not at last round:  MixColumns();
	KeySchedule();
	AddRoundKey();

	for (i=0; i<4;i++)
		for (k=0; k<4;k++)
			ucInput_Chal[i*4+k] = ucSig[i][k];
}
/******************************************************************************
 *
 * @brief	AES-128bit Decryption routine. Decrypts encrypted input data with
 * 			128 bit key
 *
 * @date	June 2013
 *
 * @version	1.0
 * @param	ucInput_Chal:	Array contains the encrypted data. Will be overwritten!!!
 * 							On return, this array contains the decryption result
 * 			ucInputKey:		Array containing the encryption key
 *
 ******************************************************************************/
void AES128_Decrypt(unsigned char *ucInput_Chal, unsigned char *ucInputKey)
{
	unsigned char i,k,m;

  	RCON_Count = 0;
  	for (i=0; i<4;i++)
   	 for (k=0; k<4;k++)
      {
        ucSig[i][k] = ucInput_Chal[i*4+k];
        ucKey[i][k] = ucInputKey[i*4+k];
      }
 	 for (i=0; i<10;i++)
  	  {
        KeySchedule();
  	  }
  	AddRoundKey();
 	 for (i=0; i<(9 + ROUND_ADDER) ; i++)
  	  {
    	  InvShiftRows();
   		  InvSubBytes();
   	   	  RCON_Count = 0;
      
     	 for (m=0; m<4;m++)
      	  for (k=0; k<4;k++)
      	  {
      	   ucKey[m][k] = ucInputKey[m*4+k];
     	   }
     	 for (k=i+1; k<10;k++)
     	   {
              KeySchedule();
      	   }
     	 AddRoundKey();
     	 InvMixColumns();
     }
  	 InvShiftRows();
 	 InvSubBytes();
  
 	 for (m=0; m<4;m++)
  	 for (k=0; k<4;k++)
 	  {
  	 	ucKey[m][k] = ucInputKey[m*4+k];
  	  }
  
  	AddRoundKey();

  	for (i=0; i<4;i++)
  	{
    	for (k=0; k<4;k++)
     	 {
      	  ucInput_Chal[i*4+k] = ucSig[i][k];
     	 }
    }
}

