[!/**
 * \file
 *
 * \brief AUTOSAR EcuC
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuC.
 *
 * \version 5.0.22
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */!][!//
[!NOCODE!]

[!MACRO "GuardedDefine", "Name", "Params"="''", "Comment"="''", "Indent"="''"!][!//
[!"$Indent"!]#ifdef [!"$Name"!]
[!"$Indent"!]  #error already defined: [!"$Name"!]
[!"$Indent"!]#endif
[!"$Indent"!]/** \brief [!"$Comment"!] */
[!"$Indent"!]#define [!"$Name"!][!"$Params"!][!WS!][!//
[!ENDMACRO!]

[!ENDNOCODE!][!//
