#ifndef _GA_GLOBAL_H_INCLUDED
#error include setup error: forbidden inclusion of GA local-scope header file; only component *_main.h + *_wrapper.h, and ga_global.h (or ga_global_emlib.h on emlib dependancy) are allowed
#endif

#ifndef GA_AEB_INTERFACES_EXT_H_INCLUDED
#define GA_AEB_INTERFACES_EXT_H_INCLUDED

/*! @ingroup aeb_interfaces
@{
@file
External header of the AEB_INTERFACES component.    */


#if (GA_CFG_AEB_INTERFACES == 1)

#ifdef __cplusplus
extern "C" {
#endif

/* --- virtual addresses --------------------------------------------------- */
#define AEB_INTERFACES_VA_CONTROL_DATA       ()   /*!< virtual address of controlData (uL) */

/* ---- constants ---------------------------------------------------------- */
#define AEB_CFG_DEBUG_FRAMES       (0)

/* ---- type InterfaceVersion ---------------------------------------------- */
#define AEB_INTERFACES_CONTROL_DATA_INTVER  (1)  /*!< version of AEB_INTERFACES_ControlData */

/* ---- type definitions --------------------------------------------------- */
#define aeb_interfaces_AEB_MOD_STARTUP   (0u)
#define aeb_interfaces_AEB_MOD_INIT      (1u)
#define aeb_interfaces_AEB_MOD_RUNNING   (2u)
#define aeb_interfaces_AEB_MOD_SHUTDOWN  (3u)
#define aeb_interfaces_AEB_MOD_PAUSE     (4u)

/*! @brief AEB Operation mode */
typedef uint8 eAEB_OP_MODE_t;

#define aeb_interfaces_opModeReset       (0u)   /*!< Reset */
#define aeb_interfaces_opModePause       (1u)   /*!< Pause */
#define aeb_interfaces_opModeNormal      (2u)   /*!< Normal */

/*! @brief OpMode(AEB_INTERFACES) */
typedef uint8 AEB_INTERFACES_OpMode;

#define aeb_interfaces_opModeReset       (0u)   /*!< Reset */
#define aeb_interfaces_opModePause       (1u)   /*!< Pause */
#define aeb_interfaces_opModeNormal      (2u)   /*!< Normal */

/*! @brief OpMode(AEB_INTERFACES) */
typedef uint8 AEB_INTERFACES_OpMode;



#ifdef __cplusplus
}
#endif

#endif /* #if (GA_CFG_AEB_INTERFACES == 1) */

/*! @} end defgroup */

#endif /* #ifndef GA_AEB_INTERFACES_EXT_H_INCLUDED */
