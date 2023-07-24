/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "exec/fs_catx.h"


/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*------------------------------TYEP DEFINITION-------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"

fs_cat_reset_reason_t g_fs_last_reset_reason;

fs_cat_count_t g_fs_cat_magic[FS_CAT_MAGIC_SIZE];

fs_cat_count_t g_fs_cat1_count;

fs_cat_count_t g_fs_cat2_count;

#define FS_STOP_SEC_VAR_NON_CLEARED
#include "Fs_MemMap.h"
/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/



/******************************************************************************/
/*------------------------------Static variables------------------------------*/
/******************************************************************************/
#define FS_START_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

struct fs_cat_t
{
    fs_catx_id_t cat3s[FS_EXEC_MAX_RECORD_CAT3_COUNT];
};

struct fs_cat_t s_cat_data = { {0} };

#define FS_STOP_SEC_VAR_CLEARED_LOCAL
#include "Fs_MemMap.h"

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Static Function----------------------------------*/
/******************************************************************************/


/******************************************************************************/
/*-------------------------Global Function----------------------------------*/
/******************************************************************************/
#define FS_START_SEC_CODE_LOCAL
#include "Fs_MemMap.h"

/**
 * \functions FSCat_Init
 *
 * \brief  FSCat is the module take control of CAT1/CAT2/CAT3 count
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void FSCat_Init(void)
{
    bool magic_ok = true;
    for(uint8_t i = 0; i < FS_CAT_MAGIC_SIZE; i++ )
	{
        if(g_fs_cat_magic[i] != i)
		{
            magic_ok = false;
            break;
        }
    }
    if( !magic_ok )
	{
        FS_LOG_DEBUG("%s","Catx Magic ReInited");
        /* do cat1/2 init */
        for(uint8_t i = 0; i < FS_CAT_MAGIC_SIZE; i ++ )
		{
            g_fs_cat_magic[i] = i;
        }
        g_fs_cat1_count = 0;
        g_fs_cat2_count = 0;
        g_fs_last_reset_reason = FS_CAT_RESET_REASON_RESET;
    }

    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT;i ++ )
	{
        s_cat_data.cat3s[i] = 0;
    }
}

/**
 * \functions FSCat_Init
 *
 * \brief  DeInit FSCat module
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void FSCat_DeInit(void)
{
    /** pass */
}

/**
 * \functions FSCat_Cat3Count
 *
 * \brief  Get the number of Cat3 count
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return The number of cat3.
 *
 * \comments
 *
 */
fs_cat_count_t FSCat_Cat3Count(void)
{
    uint8_t count = 0;
    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT;i++)
	{
        if( s_cat_data.cat3s[i] != 0 )
		{
            count ++;
        }
    }
    return count;
}

/**
 * @brief Add a CAT3 error
 * 
 * The cat3 id is stored in internel.
 * Calling `FSCat_Cat3Count` for getting current total number of CAT3s;
 * 
 * After calling `FSCat_ClearCat3`,the correspond cat3 will be cleared.
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * 
*/
void FSCat_AddCat3(fs_catx_id_t cat3id)
{
    bool has_added = false;
    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT;i ++ )
	{
        if( s_cat_data.cat3s[i] != 0 && s_cat_data.cat3s[i] == cat3id)
		{
            has_added = true;
            break;
        }
    }
	
    if(has_added)
	{
        return ;
    }
	
    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT;i++)
	{
        if( s_cat_data.cat3s[i] == 0 )
		{
            s_cat_data.cat3s[i] = cat3id;
            break;
        }
    }
}

/**
 * @brief Clear a CAT3 error
 * 
 * Clear the cat3 id stored in internel.
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * 
 */
void FSCat_ClearCat3(fs_catx_id_t cat3id)
{
    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT;i++)
	{
        if( s_cat_data.cat3s[i] == cat3id )
		{
            s_cat_data.cat3s[i] = 0;
            break;
        }
    }
}

/**
 * @brief Check is the cat3 is allready stored
 * 
 * Check is the cat3 is all ready stored
 * 
 * @param cat3id the cat3id,it is either a Dem_EventIdType or FS_CAT3_XX
 * @retval true the CAT3 is allready stored,false not recorded.
 * 
 */
bool FSCat_HasCat3(fs_catx_id_t cat3id)
{
    for(uint8_t i = 0; i < FS_EXEC_MAX_RECORD_CAT3_COUNT; i++)
	{
        if(s_cat_data.cat3s[i] == cat3id)
		{
            return true;
        }
    }
    return false;
}

#define FS_STOP_SEC_CODE_LOCAL
#include "Fs_MemMap.h"


