#include "SessionLog.h"
#include <iostream>

SessionLog::SessionLog(std::string title, std::string notes)
: title{title}, notes{notes}
{
}

SessionLog::~SessionLog()
{
}

void SessionLog::display_timestamp() const{
       char* date_time = ctime(&timestamp);
       std::cout << "Log Date: " << date_time;
}
