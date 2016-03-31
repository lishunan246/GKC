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
This file contains classes for source analyzer.
Author: Lijuan Mei
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __SOURCE_ANALYZER_H__
#define __SOURCE_ANALYZER_H__
////////////////////////////////////////////////////////////////////////////////

#include "../base/LdfTable.h"

////////////////////////////////////////////////////////////////////////////////
namespace GKC {
////////////////////////////////////////////////////////////////////////////////

// source analyzer

class SourceAnalyzer
{
public:
	SourceAnalyzer() throw()
	{
	}
	~SourceAnalyzer() throw()
	{
	}

	// init
	CallResult Initialize(const ConstStringS& strFileName) throw()
	{
		CallResult cr;

		TokenTable tokenTable;
		FsaTableInPool fsaTable;
		TokenTable actionTable;
		PdaTableInPool pdaTable;

		try {
			//process lex & gra file
			LdfTableAnalyzer lta;
			lta.Init();
			cr = lta.Process(DECLARE_TEMP_CONST_STRING(ConstStringS, _S("wlang.lex")),
							DECLARE_TEMP_CONST_STRING(ConstStringS, _S("wlang.gra")),
							tokenTable, fsaTable, actionTable, pdaTable);
		}
		catch(Exception& e) {
			//error

			return e.GetResult();
		}
		catch(...) {
			//error

		}

		return cr;
	}

	// parse
	void parse() throw()
	{
	}

private:
	void lexical() throw()
	{
	}
	void grammar() throw()
	{
	}
	void semantics() throw()
	{
	}

private:
	CplErrorBuffer m_errorBuffer;

private:
	//noncopyable
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif // __SOURCE_ANALYZER_H__
////////////////////////////////////////////////////////////////////////////////
