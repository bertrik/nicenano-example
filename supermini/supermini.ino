#include <Arduino.h>
#include <Adafruit_TinyUSB.h>
#include <MiniShell.h>

static MiniShell shell(&Serial);

static int do_set(int argc, char *argv[])
{
    int pin = 15;
    int val = 0;

    if (argc < 2) {
        printf("Need more arguments!\n");
        return -1;
    }
    pin = atoi(argv[1]);
    if (argc > 2) {
        val = atoi(argv[2]);
        printf("Set pin %d to %d\n", pin, val);
        pinMode(pin, OUTPUT);
        digitalWrite(pin, val);
    } else {
        printf("Get pin %d: ", pin);
        pinMode(pin, INPUT);
        val = digitalRead(pin);
        printf("%d\n", val);
    }
    return 0;
}

static const cmd_t commands[] = {
    { "pin", do_set, "<pin> [val] get/set pin value" },
    { NULL, NULL, NULL }
};

void setup(void)
{
    Serial.begin(115200);
}

void loop(void)
{
    shell.process(">", commands);
}

