#
# $Id: TixGray.cs 1.1 2021/12/13 18:32:38CET Wang, David (Wangd3) none  $
#
proc tixSetScheme-Color {} {

    global tixOption

    set tixOption(bg)           lightgray
    set tixOption(fg)           black

    set tixOption(dark1_bg)     gray86
    set tixOption(dark1_fg)     black
    set tixOption(dark2_bg)     gray77
    set tixOption(dark2_fg)     black
    set tixOption(inactive_bg)  gray77
    set tixOption(inactive_fg)  black

    set tixOption(light1_bg)    gray92
    set tixOption(light1_fg)    white
    set tixOption(light2_bg)    gray95
    set tixOption(light2_fg)    white

    set tixOption(active_bg)    $tixOption(dark1_bg)
    set tixOption(active_fg)    $tixOption(fg)
    set tixOption(disabled_fg)  gray55

    set tixOption(input1_bg)    gray95
    set tixOption(input2_bg)    gray95
    set tixOption(output1_bg)   $tixOption(dark1_bg)
    set tixOption(output2_bg)   $tixOption(bg)

    set tixOption(select_fg)    black
    set tixOption(select_bg)    lightblue

    set tixOption(selector)	yellow
}
