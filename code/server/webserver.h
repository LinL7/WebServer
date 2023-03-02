#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include <mysql/mysql.h>

#include "../log/log.h"
#include "../mysql/sql_connection_pool.h"

class WebServer
{
public:
    WebServer();
    ~WebServer();

    void init(int log_write, int close_log, string user, string password, string databaseName, int sql_num);
    
    void log_write();

    void sql_pool();

#if 1
    void test();
#endif
private:
    
public:
    int m_log_write;
    int m_close_log;

    connection_pool* m_connPool;
    string m_user;
    string m_password;
    string m_databaseName;
    int m_sql_num;
};

#endif

