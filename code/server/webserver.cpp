#include "webserver.h"

WebServer::WebServer()
{
    
}

WebServer::~WebServer()
{

}

void WebServer::init(int log_w, int close_log)
{
    m_log_write = log_w;
    m_close_log = close_log;
}

void WebServer::log_write()
{
    if(0 == m_close_log)
    {
        if(1 == m_log_write)
        {
            Log::get_instance()->init("ServerLog", m_close_log, 2000, 800000, 800);
        }
        else
        {
            Log::get_instance()->init("ServerLog", m_close_log, 2000, 800000, 0);
        }
    }
}

#if 1
void WebServer::test()
{
    LOG_DEBUG("%s", "just a debug test");
    LOG_INFO("%s", "just a debug test");
    LOG_WARN("%s", "just a debug test");
    LOG_ERROR("%s", "just a debug test");
}
#endif
