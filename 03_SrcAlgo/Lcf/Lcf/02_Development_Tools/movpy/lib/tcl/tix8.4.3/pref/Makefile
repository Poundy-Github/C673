#
# $Id: Makefile 1.1 2021/12/13 18:32:36CET Wang, David (Wangd3) none  $
#
# WARNING
#
# This Makefile is NOT for installation purposes. Please read the file
# docs/Install.html for information about installing Tix.
#
#
#
#
#
#
# fs = font scheme source 
# cs = color scheme source 
#
# fsc = font scheme compiled
# csc = color scheme compiled
#


.SUFFIXES: .fs .cs .csc .fsc

all:: FONT_PREF COLOR_PREF

FONT_SRC = 14Point.fs 12Point.fs TK.fs TkWin.fs

FONT_PREF:: ${FONT_SRC:.fs=.fsc}

COLOR_SRC = Bisque.cs Blue.cs Gray.cs SGIGray.cs TixGray.cs TK.cs TkWin.cs

COLOR_PREF:: ${COLOR_SRC:.cs=.csc}

fresh::
	-rm -f ${COLOR_SRC:.cs=.csc} FONT_PREF:: ${FONT_SRC:.fs=.fsc}
	make

.cs.csc:
	tixmkpref -color $< > $@

.fs.fsc:
	tixmkpref -font  $< > $@

distclean:
	- rm -f *.a *.o core errs *~ \#* TAGS *.E a.out errors \
		*.ps

clean:: distclean
