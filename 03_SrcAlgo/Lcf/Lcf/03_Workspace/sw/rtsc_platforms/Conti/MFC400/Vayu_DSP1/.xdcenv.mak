#
_XDCBUILDCOUNT = 2
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = 
override XDCROOT = C:/ti/CCS5.4/xdctools_3_25_03_72
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/CCS5.4/xdctools_3_25_03_72/packages;..
HOSTOS = Windows
endif
