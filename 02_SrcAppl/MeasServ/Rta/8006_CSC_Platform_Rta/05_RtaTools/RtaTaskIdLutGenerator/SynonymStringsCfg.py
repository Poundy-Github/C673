
#This dictionary shall contain all synonym-SubStrings
# It is used to find matches in the RA_TasksIDs.h and to avoid quite similar names of taskIDs like 'SelfTest' and 'SelfTst'.
# Note: Underscores will be cut out of the taskNames. The matcher is not caseSensitive. 

SYNONYM_STRINGS = {
  'SelfTst'         : 'SelfTest',
  'SelfTstCyclic'   : 'SelfTest',
  'SelfTestCyclic'  : 'SelfTest',
  'ComCyclic'       : 'Com',
  'SafetyB'         : 'Safety',
  'RteTimingEvent'  : 'RteEvent',
  'RteTimerEvent'   : 'RteEvent',
  'RteTimeEvent'    : 'RteEvent',
}