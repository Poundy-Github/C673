
#This list is used to shorten the localID literals in the localID enumerations.
#It defines pair of strings in which the left one is the 'origin' substring and the right one is 'new' substring.
#When ever a 'origin' substring is found in a literal name it will be replaced by the 'new' substring.
 
GENERIC_LOCAL_ID_SHORTEN_LIST = [
  ['MainFunction',      'Main'],
  ['Diagnostic',        'Diag'],
  ['Session',           'Sess'],
  ['Control',           'Ctrl'],
  ['EXECUTE',           'Exec'],
  ['DISABLED',          'Dis'],
  ['DISABLE',           'Dis'],
  ['ENABLED',           'En'],
  ['ENABLE',            'En'],
  ['Communication',     'Com'],
  ['Network',           'Net'],
  ['EXTENDED',          'Ext'],
  ['PROGRAMMING',       'Prog'],
  ['Power',             'Pwr'],
  ['SUPPLIER',          'Suppl'],
  ['Memory',            'Mem'],
  ['Monitors',          'Mon'],
  ['Monitor',           'Mon'],
  ['Signals',           'Sig'],
  ['Signal',            'Sig'],
  ['Output',            'Out'],
  ['Input',             'In'],
  ['OBJECT',            'Obj'],
  ['Vehicle',           'Veh'],
  ['PROCESSING',        'Process'],
  ['ReportCheckpoint',  'RepCp'],
  ['_v_',               '_'],
]
  