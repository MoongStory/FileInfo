#include "FileInfo.h"
#include <sstream>
#include <string>

#include <Psapi.h>	// GetProcessImageFileNameA() 사용 위해서 필요.
#pragma comment(lib, "Psapi.lib")

#pragma comment(lib, "Comdlg32.lib")	// GetFileTitle() 사용 위해서 필요.

const SYSTEMTIME MOONG::FileInfo::GetCreationTime(const HANDLE handle/* = NULL*/)
{
	SYSTEMTIME local_time = { 0 };

	HANDLE process_handle = NULL;

	if (handle == NULL)
	{
		process_handle = CreateFileA(MOONG::FileInfo::GetFileName().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		if (process_handle == INVALID_HANDLE_VALUE)
		{
			return local_time;
		}
	}
	else
	{
		process_handle = handle;
	}

	FILETIME creation_time = { 0 };
	FILETIME last_access_time = { 0 };
	FILETIME last_write_time = { 0 };

	GetFileTime(process_handle, &creation_time, &last_access_time, &last_write_time);

	SYSTEMTIME system_time = { 0 };
	FileTimeToSystemTime(&creation_time, &system_time);
	SystemTimeToTzSpecificLocalTime(NULL, &system_time, &local_time);

	return local_time;
}

const std::string MOONG::FileInfo::GetFilePath(const HANDLE handle/* = NULL*/)
{
	DWORD process_id = GetCurrentProcessId();
	HANDLE process_handle = NULL;
	
	if (handle == NULL)
	{
#if _MSC_VER > 1200
		process_handle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, process_id);
#else
		process_handle = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, process_id);
#endif
	}
	else
	{
		process_handle = handle;
	}

	char file_path[MAX_PATH] = { 0 };
	DWORD buffer_size = sizeof(file_path);

	if (process_handle)
	{
#if _MSC_VER > 1200
		if (QueryFullProcessImageNameA(process_handle, 0, file_path, &buffer_size))
#else
		if (GetProcessImageFileNameA(process_handle, file_path, buffer_size))
#endif
		{
			// 성공
		}

		CloseHandle(process_handle);
	}

	return file_path;
}

const std::string MOONG::FileInfo::GetFileName(const HANDLE handle/* = NULL*/)
{
#if _MSC_VER > 1200
	char drive[_MAX_DRIVE] = { 0 };
	char dir[_MAX_DIR] = { 0 };
	char file_name[_MAX_FNAME] = { 0 };
	char file_extension[_MAX_EXT] = { 0 };

	_splitpath_s(MOONG::FileInfo::GetFilePath(handle).c_str(), drive, sizeof(drive), dir, sizeof(dir), file_name, sizeof(file_name), file_extension, sizeof(file_extension));

	return std::string(file_name) + std::string(file_extension);
#else
	char file_name[MAX_PATH] = {0};
	
	GetFileTitleA(MOONG::FileInfo::getFilePath(handle).c_str(), file_name, sizeof(file_name));

	return file_name;
#endif
}

const std::string MOONG::FileInfo::GetFileNameWithoutFileExtension(const HANDLE handle/* = NULL*/)
{
#if _MSC_VER > 1200
	char drive[_MAX_DRIVE] = { 0 };
	char dir[_MAX_DIR] = { 0 };
	char file_name[_MAX_FNAME] = { 0 };
	char file_extension[_MAX_EXT] = { 0 };

	_splitpath_s(MOONG::FileInfo::GetFilePath(handle).c_str(), drive, sizeof(drive), dir, sizeof(dir), file_name, sizeof(file_name), file_extension, sizeof(file_extension));

	return file_name;
#else
	std::string file_name = MOONG::FileInfo::getFileName();

	return file_name.substr(0, file_name.find('.'));
#endif
}