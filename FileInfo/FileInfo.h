// https://github.com/MoongStory/FileInfo

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _FILE_INFO_H_
#define _FILE_INFO_H_

#include <iostream>
#include <Windows.h>

namespace MOONG
{
	class FileInfo
	{
	public:
	protected:
	private:

	public:
		static const SYSTEMTIME GetFileCreationTime(const HANDLE handle = NULL);
		static const std::string GetFilePath(const HANDLE handle = NULL);
		static const std::string GetFileName(const HANDLE handle = NULL);
		// FIXME: 적당한 함수 이름 없나?
		static const std::string GetFileNameWithoutFileExtension(const HANDLE handle = NULL);
	protected:
	private:
	};
}
#endif	// _FILE_INFO_H_