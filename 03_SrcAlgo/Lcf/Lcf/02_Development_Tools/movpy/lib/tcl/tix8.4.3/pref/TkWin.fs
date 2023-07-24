#
# $Id: TkWin.fs 1.1 2021/12/13 18:32:40CET Wang, David (Wangd3) none  $
#

proc tixSetFontset {} {

    global tixOption

    set tixOption(font)         "windows-message"
    set tixOption(bold_font)    "windows-status"
    set tixOption(menu_font)    "windows-menu"
    set tixOption(italic_font)  "windows-message"
    set tixOption(fixed_font)   "systemfixed"
    set tixOption(border1)      1
}

