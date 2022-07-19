#include "FileInfo.h"

int main()
{
	SYSTEMTIME creationTime = MOONG::FileInfo::getCreationTime();
	std::cout << "Year[" << creationTime.wYear << "], month[" << creationTime.wMonth << "], day[" << creationTime.wDay << "], hour[" << creationTime.wHour << "], min[" << creationTime.wMinute << "], sec[" << creationTime.wSecond << "]" << std::endl;

	return 0;
}