# -*-mode: tcl; fill-column: 75; tab-width: 8; coding: iso-latin-1-unix -*-
#
#	$Id: WmDefault.fs 1.1 2021/12/13 18:32:41CET Wang, David (Wangd3) none  $
#

proc tixSetFontset {} {
    global tixOption

    package require wm_default
    if {![info exists ::wm_default::wm]} {
	wm_default::setup
	wm_default::addoptions
    }

    set tixOption(font) 	$::wm_default::system_font
    set tixOption(bold_font)    [concat $::wm_default::system_font bold]
    set tixOption(menu_font)    $::wm_default::menu_font        
    set tixOption(italic_font)  [concat $::wm_default::system_font italic]
    set tixOption(fixed_font)   $::wm_default::fixed_font
    set tixOption(text_font)   $::wm_default::text_font
    set tixOption(border1)      $::wm_default::borderwidth

}
