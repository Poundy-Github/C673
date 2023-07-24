#
# $Id: Old12Pt.fs 1.1 2021/12/13 18:32:37CET Wang, David (Wangd3) none  $
#

proc tixSetFontset:12Point {} {
    global tixOption

    set tixOption(font)         -*-helvetica-medium-r-normal-*-12-*-*-*-*-*-*-*
    set tixOption(bold_font)    -*-helvetica-bold-r-normal-*-12-*-*-*-*-*-*-*
    set tixOption(menu_font)    -*-helvetica-bold-o-normal-*-12-*-*-*-*-*-*-*
    set tixOption(italic_font)  -*-helvetica-bold-o-normal-*-12-*-*-*-*-*-*-*
    set tixOption(fixed_font) -*-courier-medium-r-*-*-12-*-*-*-*-*-*-*
    set tixOption(border1)      1
}
