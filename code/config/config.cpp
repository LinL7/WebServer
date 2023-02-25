#include "config.h"

Config::Config(){
   
    LOGWrite = 0;   /* SYNC */

    close_log = 0;

}

void Config::parse_arg(int argc, char* argv[])
{
    int opt;
    const char *str = "l:c:";
    while((opt = getopt(argc, argv, str)) != -1)
    {
        switch(opt)
        {
        case 'l':
        {
            LOGWrite = atoi(optarg);           
            break;
        }
        case 'c':
        {
            close_log = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}
