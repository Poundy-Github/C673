#! /usr/bin/python
#coding: utf-8

#----- MKS request timouts (seconds) -----
TIMEOUT_SEARCH_ISSUES     = 10  # Timeout for searching issues with integration flag
TIMEOUT_INTEGRITY_ITEM    = 10  # Timeout for Import Issue or RO
TIMEOUT_LIST_CP           = 10  # Timeout for Changepackag list request (to get the change packages which are related to a RO, an extra request is neccessary)
TIMEOUT_VIEW_CP           = 60  # Timeout for Changepackage import
TIMEOUT_CHECKPOINT_IMPORT = 200 # Timeout for Checkpoint import
