# -*-mode: tcl; fill-column: 75; tab-width: 8; coding: iso-latin-1-unix -*-
#
#	$Id: WmDefault.cs 1.1 2021/12/13 18:32:41CET Wang, David (Wangd3) none  $
#

proc tixSetScheme-Color {} {
    global tixOption

    package require wm_default
    if {![info exists ::wm_default::wm]} {
	wm_default::setup
	wm_default::addoptions
    }

    set tixOption(bg)           $::wm_default::background
    set tixOption(fg)           $::wm_default::foreground

    set tixOption(dark1_bg)     #808080

    set tixOption(inactive_bg)  $::wm_default::disabledbackground
    set tixOption(inactive_fg)  black; # unused

    # light1 was used for listbox widgets and trough colors
    set tixOption(light1_bg)    $::wm_default::scrollbars
    set tixOption(light1_fg)    white; # unused

    # text is now used for listbox widgets
    set tixOption(list_bg)   	$::wm_default::textbackground

    set tixOption(active_bg)    $::wm_default::activebackground
    set tixOption(active_fg)    $::wm_default::activeforeground

    set tixOption(disabled_fg)  $::wm_default::disabledforeground
    # new
    set tixOption(disabled_bg)  $::wm_default::disabledtextbackground

    set tixOption(input1_bg)    $::wm_default::textbackground
    set tixOption(input1_fg)    $::wm_default::textforeground

    set tixOption(select_fg)    $::wm_default::selectforeground
    set tixOption(select_bg)    $::wm_default::selectbackground
	
    set tixOption(selector)	$::wm_default::selectcolor

}
