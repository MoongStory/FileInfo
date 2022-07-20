#include "FileInfo.h"
#include <sstream>
#include <string>

const SYSTEMTIME MOONG::FileInfo::getCreationTime(const HANDLE handle/* = NULL*/)
{
	SYSTEMTIME local_time = { 0 };

	HANDLE process_handle = NULL;

	if (handle == NULL)
	{
		process_handle = CreateFileA(MOONG::FileInfo::getFileName().c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

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

const std::string MOONG::FileInfo::getFilePath(const HANDLE handle/* = NULL*/)
{
	DWORD process_id = GetCurrentProcessId();
	HANDLE process_handle = NULL;
	
	if (handle == NULL)
	{
		process_handle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, process_id);
	}
	else
	{
		process_handle = handle;
	}

	char file_path[MAX_PATH] = { 0 };
	DWORD buffer_size = sizeof(file_path);

	if (process_handle)
	{
		if (QueryFullProcessImageNameA(process_handle, 0, file_path, &buffer_size))
		{
			// ¼º°ø
		}

		CloseHandle(process_handle);
	}

	return file_path;
}

const std::string MOONG::FileInfo::getFileName(const HANDLE handle/* = NULL*/)
{
	char drive[_MAX_DRIVE] = { 0 };
	char dir[_MAX_DIR] = { 0 };
	char file_name[_MAX_FNAME] = { 0 };
	char file_extension[_MAX_EXT] = { 0 };

	_splitpath_s(MOONG::FileInfo::getFilePath(handle).c_str(), drive, sizeof(drive), dir, sizeof(dir), file_name, sizeof(file_name), file_extension, sizeof(file_extension));

	return std::string(file_name) + std::string(file_extension);
}

const std::string MOONG::FileInfo::getFileNameWithoutFileExtension(const HANDLE handle/* = NULL*/)
{
	char drive[_MAX_DRIVE] = { 0 };
	char dir[_MAX_DIR] = { 0 };
	char file_name[_MAX_FNAME] = { 0 };
	char file_extension[_MAX_EXT] = { 0 };

	_splitpath_s(MOONG::FileInfo::getFilePath(handle).c_str(), drive, sizeof(drive), dir, sizeof(dir), file_name, sizeof(file_name), file_extension, sizeof(file_extension));

	return file_name;
}