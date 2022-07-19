#include "FileInfo.h"
#include <sstream>
#include <string>

const SYSTEMTIME MOONG::FileInfo::getCreationTime(HANDLE param_handle/* = NULL*/)
{
	SYSTEMTIME localTime = { 0 };

	HANDLE handle = NULL;

	if (param_handle == NULL)
	{
		// TODO: 파일 이름 동적으로 자기 자신의 이름을 얻도록 수정
		handle = CreateFileA("FileInfo.exe", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (handle == INVALID_HANDLE_VALUE)
		{
			return localTime;
		}
	}
	else
	{
		handle = param_handle;
	}

	FILETIME creationTime = { 0 };
	FILETIME lastAccessTime = { 0 };
	FILETIME lastWriteTime = { 0 };

	GetFileTime(handle, &creationTime, &lastAccessTime, &lastWriteTime);

	SYSTEMTIME systemTime = { 0 };
	FileTimeToSystemTime(&creationTime, &systemTime);
	SystemTimeToTzSpecificLocalTime(NULL, &systemTime, &localTime);

	return localTime;
}