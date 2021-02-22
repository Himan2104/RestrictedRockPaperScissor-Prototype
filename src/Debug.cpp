#include"../inc/Debug.hpp"

void Debug::log()
{
    std::cout << Utility::getCurrentTime() << " INFO : " << "Empty Log function called!" << std::endl;
}
void Debug::log(std::string message, MessageType m_type = MessageType::MESSAGE)
{
    std::string type;
    switch(m_type)
    {
        case INFO: type = " INFO : ";
            break;
        case MESSAGE: type = " MESSAGE : ";
            break;
        case ERROR: type = " ERROR : ";
            break;
        default: type = " UNKNOWN : ";
            break;
    }
    std::cout << Utility::getCurrentTime() << type << message << std::endl;
}