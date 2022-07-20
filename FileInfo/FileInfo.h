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
		static const SYSTEMTIME getCreationTime(const HANDLE param_handle = NULL);
		static const std::string getFilePath(const HMODULE hModule = NULL);
		static const std::string getFileName(const HMODULE hModule = NULL);
	protected:
	private:
	};
}
#endif	// _FILE_INFO_H_