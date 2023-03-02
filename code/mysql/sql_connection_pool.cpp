#include "sql_connection_pool.h"

connection_pool::connection_pool()
{
	m_curConn = 0;
	m_freeConn = 0;
}

void connection_pool::init(string url, string user, string password, string databaseName, int port, int maxConn, int close_log)
{
	m_url = url;
	m_port = port;
	m_user = user;
	m_password = password;
	m_databaseName = databaseName;
	m_close_log = close_log;

	for (int i = 0; i < maxConn; i++)
	{
		MYSQL* con = NULL;
		con = mysql_init(con);	

		if (con == NULL)
		{
			LOG_ERROR("MySQL Error");
			exit(1);
		}
		con = mysql_real_connect(con, url.c_str(), user.c_str(), password.c_str(), databaseName.c_str(), port, NULL, 0);

		if (con == NULL)
		{
			LOG_ERROR("MySQL Error");
			exit(1);
		}
		connList.push_back(con);
		++m_freeConn;
	}

	reserve = sem(m_freeConn);

	m_maxConn = m_freeConn;
}



MYSQL* connection_pool::getConnection()
{
	MYSQL *con = NULL;

	if (0 == connList.size())
		return NULL;

	reserve.wait();
	
	lock.lock();

	con = connList.front();
	connList.pop_front();

	--m_freeConn;
	++m_curConn;

	lock.unlock();
	return con;
}


bool connection_pool::ReleaseConnection(MYSQL *con)
{
	if (NULL == con)
		return false;

	lock.lock();

	connList.push_back(con);
	++m_freeConn;
	--m_curConn;

	lock.unlock();

	reserve.post();
	return true;
}


void connection_pool::DestroyPool()
{

	lock.lock();
	if (connList.size() > 0)
	{
		list<MYSQL *>::iterator it;
		for (it = connList.begin(); it != connList.end(); ++it)
		{
			MYSQL *con = *it;
			mysql_close(con);
		}
		m_curConn = 0;
		m_freeConn = 0;
		connList.clear();
	}

	lock.unlock();
}


int connection_pool::GetFreeConn()
{
	return this->m_freeConn;
}

connection_pool::~connection_pool()
{
	DestroyPool();
}

connectionRAII::connectionRAII(MYSQL** SQL, connection_pool* connPool){
	*SQL = connPool->getConnection();
	
	connRAII = *SQL;
	poolRAII = connPool;
}

connectionRAII::~connectionRAII(){
	poolRAII->ReleaseConnection(connRAII);
}
