#pragma once
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <ctime>
class Logger
{
public:
	static void LogInformation(const char* log);
	static void LogWarning(const char* log);
	static void LogError(const char* log);
};

