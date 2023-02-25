#include "config/config.h"

int main(int argc, char* argv[])
{
    
    Config config;
    config.parse_arg(argc, argv);
    
    WebServer server;

    server.init(config.LOGWrite, config.close_log);

    server.log_write();

    server.test();

    return 0;
}
