#include <string>

#include "config/config.h"

int main(int argc, char* argv[])
{
    string user = "root";
    string passwd = "$Lin147258";
    string databaseName = "tinyWebServer_Database";

    Config config;
    config.parse_arg(argc, argv);
    
    WebServer server;

    server.init(config.LOGWrite, config.close_log, user, passwd, databaseName, config.sql_num);

    server.log_write();

    server.sql_pool();

    server.test();

    return 0;
}
