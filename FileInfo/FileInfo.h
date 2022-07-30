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
		// handle 값을 NULL을 넘기면 현재 프로세스의 핸들로 동작.
		static const SYSTEMTIME GetFileCreationTime(const HANDLE handle = NULL);
		static const std::string GetFilePath(const HANDLE handle = NULL);
		static const std::string GetFileName(const HANDLE handle = NULL);
		static const std::string GetFileNameWithoutFileExtension(const HANDLE handle = NULL);

		// file_path를 빈 문자열을 넘기면 현재 프로세스의 버전을 얻음.
		static const std::string GetFileVersion(const std::string param_file_path = "");
	protected:
	private:
	};
}
#endif	// _FILE_INFO_H_