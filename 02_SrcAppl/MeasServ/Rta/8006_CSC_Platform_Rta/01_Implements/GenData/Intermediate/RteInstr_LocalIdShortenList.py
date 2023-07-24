
# This list is used to shorten the localID literals in the localID enumerations.
# It applies only to the generated enumeration for the localIds of all runnables in the RTE.
# Background: In case of too long literals they overlap the statistic data in the RtaVisuMo

# It defines pairs of strings in which the left one is the 'origin' substring and the right one is the 'desired' substring.
# When ever a 'origin' subString is found in a literal name it will be replaced by the 'desired' subString.
# This feature is not case sensitiv -> 'main' is considered as the same like 'MAIN'

# The 'desired' subString can also completely empty. In this case the origin subString is just removed.

# It is up to the project to use the project specific shortenList or not.
# If it shall not be used just leave it empty.

# The generator it self has already a generic shortenList, which is located in that file:
# ..\03_Design\03_Code_Generation\Generic\RTA\RteStandardRtaInstrGenerator\LocalIdsShortenList.py

# !!!!!!!!! PLEASE DO NOT CHANGE THE GENERIC SHORTEN LIST AS IT INFLUENCES ALL ALL PROJECTS! !!!!!!!!! 

# The internal shortenList can be overruled by the project specific one. 
# In case the project specific shortenList has an entry with the same 'desired' subString - again not case sensitive - 
# then the 'origin' subString is substituted by the 'desired' subString of the project specific shortenList and not by that one of the generic shortenList.

# It is important that the file is syntactially OK. 
# In case there is any syntax error in the file, the generator just overwrites it with a new one and all entries are gone. 


PROJECT_LOCAL_ID_SHORTEN_LIST = [
#  ['originSubString',   'desiredSubString'  ],
#  ['originSubString_2', 'desiredSubString_2'],
]
  