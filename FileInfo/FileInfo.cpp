#include "FileInfo.h"
#include <sstream>
#include <string>

const SYSTEMTIME MOONG::FileInfo::getCreationTime(const HANDLE param_handle/* = NULL*/)
{
	SYSTEMTIME local_time = { 0 };

	HANDLE handle = NULL;

	if (param_handle == NULL)
	{
		// TODO: 현재 프로세스 핸들 얻기

		handle = CreateFileA("test.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (handle == INVALID_HANDLE_VALUE)
		{
			return local_time;
		}
	}
	else
	{
		handle = param_handle;
	}

	FILETIME creation_time = { 0 };
	FILETIME last_access_time = { 0 };
	FILETIME last_write_time = { 0 };

	GetFileTime(handle, &creation_time, &last_access_time, &last_write_time);

	SYSTEMTIME system_time = { 0 };
	FileTimeToSystemTime(&creation_time, &system_time);
	SystemTimeToTzSpecificLocalTime(NULL, &system_time, &local_time);

	return local_time;
}

const std::string MOONG::FileInfo::getFilePath(const HMODULE hModule/* = NULL*/)
{
	DWORD process_id = GetCurrentProcessId();
	HANDLE process_handle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, process_id);

	char file_path[MAX_PATH] = { 0 };
	DWORD buffer_size = sizeof(file_path);

	if (process_handle)
	{

		if (QueryFullProcessImageNameA(process_handle, 0, file_path, &buffer_size))
		{
			// 성공
		}

		CloseHandle(process_handle);
	}

	return file_path;
}

const std::string MOONG::FileInfo::getFileName()
{
	//char file_name
}