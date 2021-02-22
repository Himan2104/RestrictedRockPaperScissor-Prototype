#include<iostream>
#include"Utility.hpp"


class Debug
{
public:
    enum MessageType
    {
        INFO,
        MESSAGE,
        ERROR
    };
    static void log();
    static void log(std::string message, MessageType m_type = MessageType::MESSAGE);
};