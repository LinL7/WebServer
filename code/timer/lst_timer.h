#ifndef LST_TIMER
#define LST_TIMER


class util_timer;

struct client_data
{
    sockaddr_in address;
    int sockfd;
    util_timer*
