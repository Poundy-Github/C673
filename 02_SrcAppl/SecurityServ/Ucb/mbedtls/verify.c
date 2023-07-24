#include "common.h"
#include "aes.h"
#include "platform.h"
#include "platform_util.h"
#include "error.h"

#if 0

static const unsigned char EncMacKey[16] = 
{
    0x20, 0x79, 0xD8, 0x42, 0x06, 0xBC, 0xE0, 0x93, 0x6B, 0x76, 0xAE, 0x8E, 0x85, 0xCD, 0xBB, 0x81
};


int mbedtls_verify(const unsigned char hash[16], const unsigned char Signature[16])
{
    int ret;
    unsigned char calchash[16];
    unsigned char MacKey[16];

    ret = mbedtls_aes_decrypt_ecb(EcuKey, EncMacKey, MacKey);

    if (ret == 0)
    {
        ret = mbedtls_aes_decrypt_ecb(MacKey, Signature, calchash);
    }

    if (ret == 0)
    {
        ret = memcmp(hash, calchash, 16);
    }

    return ret;
}
#endif

int mbedtls_aes_decrypt_ecb(const unsigned char *key, const unsigned char input[16], unsigned char output[16])
{
    int ret;
    mbedtls_aes_context ctx;

    mbedtls_aes_init(&ctx);
 
    ret = mbedtls_aes_setkey_dec(&ctx, key, 128U);
    if (ret == 0)
    { 
        ret = mbedtls_aes_crypt_ecb(&ctx, MBEDTLS_AES_DECRYPT, input, output);
    }

    mbedtls_aes_free(&ctx);

    return ret;
}

int mbedtls_aes_decrypt_ecb_256(const unsigned char *key, const unsigned char input[32], unsigned char output[32])
{
    int ret;
    mbedtls_aes_context ctx;

    mbedtls_aes_init(&ctx);
 
    ret = mbedtls_aes_setkey_dec(&ctx, key, 128U);
    if (ret == 0)
    { 
        ret = mbedtls_aes_crypt_ecb(&ctx, MBEDTLS_AES_DECRYPT, input, output);
		ret = mbedtls_aes_crypt_ecb(&ctx, MBEDTLS_AES_DECRYPT, &input[16], &output[16]);
    }

    mbedtls_aes_free(&ctx);

    return ret;
}

int mbedtls_aes_encrypt_ecb_256(const unsigned char *key, const unsigned char input[32], unsigned char output[32])
{
    int ret;
    mbedtls_aes_context ctx;



   mbedtls_aes_init(&ctx);

    ret = mbedtls_aes_setkey_dec(&ctx, key, 128U);
    if (ret == 0)
    {
        ret = mbedtls_aes_crypt_ecb(&ctx, MBEDTLS_AES_ENCRYPT, input, output);
        ret = mbedtls_aes_crypt_ecb(&ctx, MBEDTLS_AES_ENCRYPT, &input[16], &output[16]);
    }



   mbedtls_aes_free(&ctx);



   return ret;
}



