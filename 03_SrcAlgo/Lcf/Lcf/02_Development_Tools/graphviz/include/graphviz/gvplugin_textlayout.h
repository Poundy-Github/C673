/* $Id: gvplugin_textlayout.h 1.1 2021/12/13 18:07:03CET Wang, David (Wangd3) none  $ $Revision: 1.1 $ */
/* vim:set shiftwidth=4 ts=8: */

/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#ifndef GVPLUGIN_TEXTLAYOUT_H
#define GVPLUGIN_TEXTLAYOUT_H

#include "types.h"
#include "gvplugin.h"
#include "gvcjob.h"
#include "gvcommon.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct gvtextlayout_engine_s {
	boolean (*textlayout) (textpara_t *para, char** fontpath);
    };

#ifdef __cplusplus
}
#endif
#endif				/* GVPLUGIN_TEXTLAYOUT_H */
