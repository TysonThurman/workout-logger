#ifndef SESSIONLOG_H
#define SESSIONLOG_H
#include <string>

class SessionLog
{
private:
    time_t timestamp {time(0)};
    std::string title{};
    std::string notes {};
public:
    SessionLog(std::string title, std::string notes);
    ~SessionLog();
    std::string get_notes(){return this->notes;}
    std::string get_title(){return this->title;}
    void display_timestamp();
};

#endif // SESSIONLOG_H
