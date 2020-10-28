#include "daemonize.c"

int main()
{
    skeleton_daemon();
    
    while (1)
    {
        //TODO: Insert daemon code here.
        syslog (LOG_NOTICE, "Keylogger started.");
        sleep (20);
        break;
    }
   
    syslog (LOG_NOTICE, "Keylogger terminated.");
    closelog();
    
    return EXIT_SUCCESS;
}