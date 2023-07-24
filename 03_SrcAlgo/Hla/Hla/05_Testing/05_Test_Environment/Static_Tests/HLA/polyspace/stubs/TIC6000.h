/* TI C6000 compiler predefined macros valid for C674x and C66xx */
#define __signed_chars__             1              /* Predefined */
#define __DATE__                     "Nov 28 2011"  /* Predefined */
#define __TIME__                     "16:57:59"     /* Predefined */
#define __STDC__                     1              /* Predefined */
#define __STDC_VERSION__             199409L        /* Predefined */
#define __TI_INT40_T__               1              /* Predefined */
#define __edg_front_end__            1              /* Predefined */
#define __EDG_VERSION__              303            /* Predefined */
#define __TI_COMPILER_VERSION__      7003001        /* Predefined */
#define __COMPILER_VERSION__         7003001        /* Predefined */
#define _TMS320C6X                   1              /* Predefined */
#define __TMS320C6X__                1              /* Predefined */
#define TMS320C67X                   1              /* Predefined */
#define _TMS320C6740                 1              /* Predefined */
#define _TMS320C6200                 1              /* Predefined */
#define _LITTLE_ENDIAN               1              /* Predefined */
#define __TI_40BIT_LONG__            1              /* Predefined */
#define __SIZE_T_TYPE__              unsigned       /* Predefined */
#define __PTRDIFF_T_TYPE__           int            /* Predefined */
#define __WCHAR_T_TYPE__             unsigned short /* Predefined */
#define __little_endian__            1              /* Predefined */
#define __int40_t                    long long      /* Predefined */
#define __TI_STRICT_ANSI_MODE__      1              /* Predefined */
#define __TI_WCHAR_T_BITS__          16             /* Predefined */
#define __TI_GNU_ATTRIBUTE_SUPPORT__ 1              /* Predefined */
#define __inline                     inline         /* Predefined */
#define __attribute__                _ignore_paren  /* Predefined */

/* Predefined TI C6000 qualifiers that need to be deleted for polyspace */
#define interrupt
#define far
#define restrict
#define __cregister
#define __intaddr__
#define __va_argref
#define __va_parmadr

/* Some C6000 intrinsics */
#define _memd8_const(x)   (*(x))
#define _memd8(x)         (*(x))
#define _mem4_const(ptr)  (*((const uint32 *) (ptr)))
#define _amem8(ptr)       (*((int64_ll *) (ptr)))

