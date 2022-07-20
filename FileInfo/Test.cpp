#include "FileInfo.h"

int main()
{
	SYSTEMTIME creationTime = MOONG::FileInfo::getCreationTime();
	std::cout << "Year[" << creationTime.wYear << "], month[" << creationTime.wMonth << "], day[" << creationTime.wDay << "], hour[" << creationTime.wHour << "], min[" << creationTime.wMinute << "], sec[" << creationTime.wSecond << "]\n" << std::endl;

	std::cout << "file path[" << MOONG::FileInfo::getFilePath().c_str() << "]\n" << std::endl;

	std::cout << "file name[" << MOONG::FileInfo::getFileName().c_str() << "]\n" << std::endl;

	std::cout << "file name without file extension[" << MOONG::FileInfo::getFileNameWithoutFileExtension().c_str() << "]\n" << std::endl;

	return 0;
}