﻿/*
** Copyright (c) 2015, Xin YUAN, courses of Zhejiang University
** All rights reserved.
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the 2-Clause BSD License.
**
** Author contact information:
**   yxxinyuan@zju.edu.cn
**
*/

/*
This file contains functions.
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __COMPILE_SINGLE_FILE_H__
#define __COMPILE_SINGLE_FILE_H__
////////////////////////////////////////////////////////////////////////////////

#include "../process/SourceAnalyzer.h"

////////////////////////////////////////////////////////////////////////////////
namespace GKC {
////////////////////////////////////////////////////////////////////////////////

inline int compile_single_file(const StringS& strSrc, const StringS& strDest)
{
	CallResult cr;
	SourceAnalyzer sa;

	ConsoleHelper::WriteLine(DECLARE_TEMP_CONST_STRING(ConstStringS, _S("Initialize...")));
	//init
	cr = sa.Initialize(StringUtilHelper::To_ConstString(strSrc));
	if( cr.IsFailed() ) {
		ConsoleHelper::WriteLine(DECLARE_TEMP_CONST_STRING(ConstStringS, _S("Failed!")));
		return 0;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
