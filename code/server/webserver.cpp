#include "webserver.h"

WebServer::WebServer()
{
    
}

WebServer::~WebServer()
{

}

void WebServer::init(int log_w, int close_log, string user, string password, string databaseName, int sql_num)
{
    m_log_write = log_w;
    m_close_log = close_log;

    m_user = user;
    m_password = password;
    m_databaseName = databaseName;
    m_sql_num = sql_num;
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

void WebServer::sql_pool()
{
    m_connPool = connection_pool::get_instance();
    m_connPool->init("localhost", m_user, m_password, m_databaseName, 3306, m_sql_num, m_close_log);

    /* TODO: httpconn */
}

#if 1
void WebServer::test()
{
    /* test LOG */
    LOG_DEBUG("%s", "just a debug test");
    LOG_INFO("%s", "just a debug test");
    LOG_WARN("%s", "just a debug test");
    LOG_ERROR("%s", "just a debug test");

    /* test sqlconn */
    MYSQL *mysql = NULL;    
    connectionRAII mysqlcon(&mysql, m_connPool);
    if (mysql_query(mysql, "SELECT username,passwd FROM user"))        
    {
        LOG_ERROR("SELECT error:%s\n", mysql_error(mysql));
    }
    MYSQL_RES *result = mysql_store_result(mysql);
    while (MYSQL_ROW row = mysql_fetch_row(result))        
    {
        string temp1(row[0]);                        
        string temp2(row[1]);                                
        LOG_INFO("%s : %s", temp1.c_str(), temp2.c_str());                                        
    }
}
#endif
