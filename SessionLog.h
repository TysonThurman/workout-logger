#ifndef SESSIONLOG_H
#define SESSIONLOG_H
#include <string>
#include <iostream>

class SessionLog
{
private:
    //date time field for Log Entry Time - set to right now
    //date field for Workout Date
    std::string title{};
    std::string notes {};
    bool upper_body {0};
    bool lower_body {0};
    bool core {0};
    bool cardio {0};
public:
    SessionLog(std::string title, std::string notes, bool upper_body, bool lower_body, bool core, bool cardio);
    ~SessionLog();
    std::string get_notes(){return this->notes;}
    std::string get_title(){return this->title;}
    bool get_upper_body(){return this->upper_body;}
    bool get_lower_body(){return this->lower_body;}
    bool get_core(){return this->core;}
    bool get_cardio(){return this->cardio;}
};

#endif // SESSIONLOG_H
