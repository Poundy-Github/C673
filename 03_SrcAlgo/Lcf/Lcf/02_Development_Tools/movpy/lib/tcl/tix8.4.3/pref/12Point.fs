#
# $Id: 12Point.fs 1.1 2021/12/13 18:32:34CET Wang, David (Wangd3) none  $
#

proc tixSetFontset {} {
    global tixOption tcl_platform

    switch -- $tcl_platform(platform) "windows" {
	# This should be Tahoma for Win2000/XP
	set font "MS Sans Serif"
	set fixedfont "Courier New"
    } unix {
	set font "helvetica"
	set fixedfont "courier"
    }

    set tixOption(font)         [list $font -12]
    set tixOption(bold_font)    [list $font -12 bold]
    set tixOption(menu_font)    [list $font -12]
    set tixOption(italic_font)  [list $font -12 bold italic]
    set tixOption(fixed_font)   [list $fixedfont -12]
    set tixOption(border1)      1
}
