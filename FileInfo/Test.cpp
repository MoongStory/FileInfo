#include "FileInfo.h"

int main()
{
	SYSTEMTIME creationTime = MOONG::FileInfo::GetFileCreationTime();
	std::cout << "Year[" << creationTime.wYear << "], month[" << creationTime.wMonth << "], day[" << creationTime.wDay << "], hour[" << creationTime.wHour << "], min[" << creationTime.wMinute << "], sec[" << creationTime.wSecond << "]\n" << std::endl;

	std::cout << "file path[" << MOONG::FileInfo::GetFilePath().c_str() << "]\n" << std::endl;

	std::cout << "file name[" << MOONG::FileInfo::GetFileName().c_str() << "]\n" << std::endl;

	std::cout << "file name without file extension[" << MOONG::FileInfo::GetFileNameWithoutFileExtension().c_str() << "]\n" << std::endl;

	std::cout << "file version[" << MOONG::FileInfo::GetFileVersion().c_str() << "]\n" << std::endl;

	std::cout << "folder name[" << MOONG::FileInfo::GetFolderName().c_str() << "]\n" << std::endl;

	return 0;
}