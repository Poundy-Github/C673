
#The list of subStrings to be removed from the osTaskNames like 
# - prefixes (TASK, TSK)  
# - coreNames in multicoreOS  (A53_0, A53_1)
# This prefixes and coreNames are removed from osTaskNames to find a matching TaskName in the RTA_TasksIDs.h

SUB_STRINGS_TO_REMOVE = [
 'TASK',
 'TSK',
 'OsTask',
 'Core_0',
 'Core_1',
 'Core_2',
 'Core_3',
 'Core_4',
 'Core_5',
 'Core0',
 'Core1',
 'Core2',
 'Core3',
 'Core4',
 'Core5',
 'A53_0',
 'A53_1',
 'A53_2',
 'A53_3',
 'A53_4',
 'A53_5',
 'A57_0',
 'A57_1',
 'A57_2',
 'A57_3',
 'A57_4',
 'A57_5',
 'OsCore0',
 'OsCore1',
 'OsCore2',
 'OsCore3',
 'OsCore4',
 'OsCore5',
]

#The list of subStrings to be removed from the osTaskNames like
# - QM
# - BSW
# BUT these subStrings will only be removed in case we will not end up with two equal taskNames.
# If this would be the case the corresponding subString will not be removed.

SUB_STRINGS_TO_REMOVE_NO_DOUBLES = [
]

