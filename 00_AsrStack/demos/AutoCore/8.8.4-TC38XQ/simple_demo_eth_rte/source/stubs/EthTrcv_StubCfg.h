/* --------{ EB Automotive C Source File }-------- */

#if (!defined ETHTRCV_STUBCFG_H)
#define ETHTRCV_STUBCFG_H

/*
   Configuration file for the EthTrcv code stub
   The following symbols have the potential to change the behavior of the stub:
   ============================================================================

   - EBSTUBS_FUNCTION_TRACE_ETHTRCV
        Values: STD_ON (default)/STD_OFF
        En-/Disables function tracing feature module-wide if the more specific
        symbols for the single API functions are not defined.
        Also defines the default values for the following symbols if they are not set.
        If function tracing is disabled on global level this symbol has no effect.

   - EBSTUBS_FUNCTION_TRACE_ETHTRCV_[fctname]
        Values: STD_ON/STD_OFF Default: EBSTUBS_FUNCTION_TRACE_ETHTRCV
        En-/Disables function tracing feature for a single API function.
        If function tracing is disabled on global level this symbol has no effect.
        Defining a value overrules the behavior set by the module-wide symbol.
        In detail the symbols are:
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETBAUDRATE
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETDUPLEXMODE
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETLINKSTATE
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETTRANSCEIVERMODE
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_GETVERSIONINFO
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_INIT
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_SETTRANSCEIVERMODE
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_STARTAUTONEGOTIATION
      * EBSTUBS_FUNCTION_TRACE_ETHTRCV_TRANSCEIVERINIT

   Note: A function is only written to the function tracing buffer if:
         The global symbol EBSTUBS_FUNCTION_TRACE is enabled AND
         the symbol of the relevant function EBSTUBS_FUNCTION_TRACE_[fctname] is enabled.

     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

   - EBSTUBS_FUNCENABLED_ETHTRCV
        Values: STD_ON (default)/STD_OFF
        En-/Disables all API functions of a single code stub at pre-compile time.
        Also defines the default values for the following symbols if they are not set.

   - EBSTUBS_FUNCENABLED_ETHTRCV_[fctname]
        Values: STD_ON/STD_OFF Default: EBSTUBS_FUNCENABLED_ETHTRCV
        En-/Disables a single API function at pre-compile time.
        Defining a value overrules the behavior set by the module-wide symbol.
        In detail the symbols are:
      * EBSTUBS_FUNCENABLED_ETHTRCV_GETBAUDRATE
      * EBSTUBS_FUNCENABLED_ETHTRCV_GETDUPLEXMODE
      * EBSTUBS_FUNCENABLED_ETHTRCV_GETLINKSTATE
      * EBSTUBS_FUNCENABLED_ETHTRCV_GETTRANSCEIVERMODE
      * EBSTUBS_FUNCENABLED_ETHTRCV_GETVERSIONINFO
      * EBSTUBS_FUNCENABLED_ETHTRCV_INIT
      * EBSTUBS_FUNCENABLED_ETHTRCV_SETTRANSCEIVERMODE
      * EBSTUBS_FUNCENABLED_ETHTRCV_STARTAUTONEGOTIATION
      * EBSTUBS_FUNCENABLED_ETHTRCV_TRANSCEIVERINIT

     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

   - EBSTUBS_MAX_CALLS_ETHTRCV
        Values: [numeric value] Default: 1
        Defines the number of API calls for which the code stubs can store the function arguments.
        Also defines the default values for the following symbols if they are not set.

   - EBSTUBS_MAX_CALLS_ETHTRCV_[fctname]
        Values: [numeric value] Default: EBSTUBS_MAX_CALLS_ETHTRCV
        Defines the number of API calls for which a specific function can.
        store the function arguments.
        Defining a value overrules the behavior set by the module-wide symbol.
        In detail the symbols are:
      * EBSTUBS_MAX_CALLS_ETHTRCV_GETBAUDRATE
      * EBSTUBS_MAX_CALLS_ETHTRCV_GETDUPLEXMODE
      * EBSTUBS_MAX_CALLS_ETHTRCV_GETLINKSTATE
      * EBSTUBS_MAX_CALLS_ETHTRCV_GETTRANSCEIVERMODE
      * EBSTUBS_MAX_CALLS_ETHTRCV_GETVERSIONINFO
      * EBSTUBS_MAX_CALLS_ETHTRCV_INIT
      * EBSTUBS_MAX_CALLS_ETHTRCV_SETTRANSCEIVERMODE
      * EBSTUBS_MAX_CALLS_ETHTRCV_STARTAUTONEGOTIATION
      * EBSTUBS_MAX_CALLS_ETHTRCV_TRANSCEIVERINIT
*/

#endif /* !defined ETHTRCV_STUBCFG_H */
