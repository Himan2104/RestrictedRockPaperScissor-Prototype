#include<iostream>
#include<chrono>
#include<sstream>
#include<time.h>
#include<string>
#include<iomanip>

namespace Utility
{
    static std::string getCurrentTime(const char* format = "[%Y-%m-%d|%X]")
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), format);
        return ss.str();
    }
};