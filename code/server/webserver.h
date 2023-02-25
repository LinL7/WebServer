#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "../log/log.h"

class WebServer
{
public:
    WebServer();
    ~WebServer();

    void init(int log_write, int close_log);
    
    void log_write();
    
#if 1
    void test();
#endif
private:
    
public:
    int m_log_write;
    int m_close_log;
};

#endif

