#include "Logger.h"
#pragma warning(disable : 4996) // disables ctime deprecation error
void Logger::LogInformation(const char* log)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "[Information | " << strtok(std::ctime(&currentTime), "\n") << "]: " << log << std::endl;
}

void Logger::LogWarning(const char* log)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "[Warning | " << strtok(std::ctime(&currentTime), "\n") << "]: " << log << std::endl;
}

void Logger::LogError(const char* log)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "[Error | " << strtok(std::ctime(&currentTime), "\n") << "]: " << log << std::endl;
}
