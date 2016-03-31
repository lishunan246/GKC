﻿/*
** Copyright (c) 2013, Xin YUAN, courses of Zhejiang University
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
This file contains GkcSys helper classes.
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __GKC_SYS_H__
#define __GKC_SYS_H__
////////////////////////////////////////////////////////////////////////////////

#ifndef __GKC_DEF_H__
	#error GkcSys.h requires GkcDef.h to be included first.
#endif

////////////////////////////////////////////////////////////////////////////////

#include "_GkcSys.h"

////////////////////////////////////////////////////////////////////////////////
namespace GKC {
////////////////////////////////////////////////////////////////////////////////

// classes

// MemoryHelper

class MemoryHelper
{
public:
	static RefPtr<IMemoryManager> GetCrtMemoryManager() throw()
	{
		return RefPtr<IMemoryManager>(::_CrtMemoryManager_Get());
	}
};

// SharePtr<T>
template <typename T>
using SharePtr = _SharePtr<T>;

// WeakPtr<T>
template <typename T>
using WeakPtr = _WeakPtr<T>;

// SharePtrHelper
typedef _SharePtrHelper  SharePtrHelper;

// ShareCom<T>
template <class T>
using ShareCom = _ShareCom<T>;

// WeakCom<T>
template <class T>
using WeakCom = _WeakCom<T>;

// ShareComHelper
typedef _ShareComHelper  ShareComHelper;

// ShareArray<T>
template <typename T>
using ShareArray = _ShareArray<T>;

// WeakArray<T>
template <typename T>
using WeakArray = _WeakArray<T>;

// ShareArrayHelper
typedef _ShareArrayHelper  ShareArrayHelper;

// StringT<Tchar>
template <typename Tchar>
using StringT = _StringT<Tchar>;

// String*
typedef _StringA  StringA;
typedef _StringH  StringH;
typedef _StringL  StringL;
typedef _StringS  StringS;
typedef _StringW  StringW;

// StringCompareTrait<T>
template <class T>
using StringCompareTrait = _StringCompareTrait<T>;

// StringCaseIgnoreCompareTrait<T>
template <class T>
using StringCaseIgnoreCompareTrait = _StringCaseIgnoreCompareTrait<T>;

// StringHashTrait<T>
template <class T>
using StringHashTrait = _StringHashTrait<T>;

// StringCaseIgnoreHashTrait<T>
template <class T>
using StringCaseIgnoreHashTrait = _StringCaseIgnoreHashTrait<T>;

// StringHelper
typedef _StringHelper  StringHelper;

// StringUtilHelper
typedef _StringUtilHelper  StringUtilHelper;

// ComFactory<T>
template <class T>
using ComFactory = _ComFactory<T>;

// IByteSequentialStream
typedef _IByteSequentialStream  IByteSequentialStream;

#define GUID_IByteSequentialStream  GUID__IByteSequentialStream

// IByteStream
typedef _IByteStream  IByteStream;

#define GUID_IByteStream  GUID__IByteStream

// IFileUtility
typedef _IFileUtility  IFileUtility;

#define GUID_IFileUtility  GUID__IFileUtility

// IMemoryUtility
typedef _IMemoryUtility  IMemoryUtility;

#define GUID_IMemoryUtility  GUID__IMemoryUtility

// IBufferUtility
typedef _IBufferUtility  IBufferUtility;

#define GUID_IBufferUtility  GUID__IBufferUtility

// BOMTypes
typedef _BOMTypes  BOMTypes;

// ITextStream
typedef _ITextStream  ITextStream;

#define GUID_ITextStream  GUID__ITextStream

// StreamHelper

class StreamHelper
{
public:
	// file stream
	static CallResult CreateFileStream(const ConstStringS& strFile, int iOpenType, int iCreateType, ShareCom<IByteStream>& sp) throw()
	{
		CallResult cr;
		::_FileStream_Create(ConstArrayHelper::GetInternalPointer(strFile), iOpenType, iCreateType, sp, cr);
		return cr;
	}
	// memory stream
	static CallResult CreateMemoryStream(ShareCom<IByteStream>& sp) throw()
	{
		CallResult cr;
		::_MemoryStream_Create(sp, cr);
		return cr;
	}
	// buffer stream
	static CallResult CreateBufferStream(const uintptr pv, uintptr uBytes, ShareCom<IByteStream>& sp) throw()
	{
		CallResult cr;
		::_BufferStream_Create((const void*)pv, uBytes, sp, cr);
		return cr;
	}
	// text stream
	static CallResult CreateTextStream(ShareCom<ITextStream>& sp) throw()
	{
		CallResult cr;
		::_TextStream_Create(sp, cr);
		return cr;
	}
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif //__GKC_SYS_H__
////////////////////////////////////////////////////////////////////////////////
