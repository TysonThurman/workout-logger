#include "SessionLog.h"
#include <iostream>

SessionLog::SessionLog(std::string title, std::string notes, bool upper_body, bool lower_body, bool core, bool cardio)
: title{title}, notes{notes}, upper_body{upper_body}, lower_body{lower_body}, core{core}, cardio{cardio}
{
    std::cout << std::endl;
    std::cout << "*******************************" << std::endl; 
    std::cout << "Session Log Constructor called" << std::endl; 
    std::cout << "*******************************" << std::endl << std::endl;
}

SessionLog::~SessionLog()
{
    std::cout << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "Session Log Destructor called" << std::endl; 
    std::cout << "*******************************" << std::endl;
}

void SessionLog::display_timestamp(){
       char* date_time = ctime(&timestamp);
       std::cout << "Timestamp: " << date_time;
}
