#ifndef CONFIG_H
#define CONFIG_H

#include <unistd.h>
#include "../server/webserver.h"

using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char* argv[]);

    int LOGWrite;

    int close_log;
    
    int sql_num;
};

#endif
