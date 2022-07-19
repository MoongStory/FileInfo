#include "FileInfo.h"
#include <sstream>
#include <string>

const SYSTEMTIME MOONG::FileInfo::getCreationTime(HANDLE param_handle/* = NULL*/)
{
	SYSTEMTIME localTime = { 0 };

	HANDLE handle = NULL;

	if (param_handle == NULL)
	{
		// TODO: 현재 프로세스 핸들 얻기
		handle = CreateFileA("test.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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