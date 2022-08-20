#ifndef SESSIONLOG_H
#define SESSIONLOG_H
#include <string>

class SessionLog
{
private:
    std::string title{};
    std::string notes {};
public:
    time_t timestamp {time(0)};
    SessionLog(std::string title, std::string notes);
    ~SessionLog();
    std::string get_notes(){return this->notes;}
    std::string get_title(){return this->title;}
    void display_timestamp() const;
};

#endif // SESSIONLOG_H
