#ifndef _CONNECTION_POOL_
#define _CONNECTION_POOL_

#include <stdio.h>
#include <mysql/mysql.h>
#include <list>
#include <string>

#include "../utils/locker.h"
#include "../log/log.h"

using namespace std;

class connection_pool
{
public:
    MYSQL* getConnection();
    bool ReleaseConnection(MYSQL* conn);
    int GetFreeConn();
    void DestroyPool();

    static connection_pool* get_instance()
    {
        static connection_pool instance;
        return &instance;
    }
    void init(string url, string user, string password, string databaseName, int port, int maxConn, int close_log);

private:
    connection_pool();
    ~connection_pool();

private:
    int m_maxConn;              
    int m_curConn;
    int m_freeConn;
    locker lock;
    list<MYSQL*> connList;  /* conn pool */
    sem reserve;            

public:
    string m_url;           /* host address */
    string m_port;
    string m_user;
    string m_password;
    string m_databaseName;
    int m_close_log;
};

class connectionRAII
{
public:
    connectionRAII(MYSQL** SQL, connection_pool* connPool);
    ~connectionRAII();

public:
    MYSQL* connRAII;
    connection_pool* poolRAII;
};

#endif
