#include <avr/io.h>

#include "millis.h"
#include "scheduler.h"

#define LED_1_PIN 3
#define LED_2_PIN 4

void toggle_led_1(void) {
    PIND = (1 << LED_1_PIN);
}

void toggle_led_2(void) {
    PIND = (1 << LED_2_PIN);
}

void setup(void) {
    DDRD |= (1<<LED_1_PIN) | (1<<LED_2_PIN);

    millis_init();

    scheduler_init();
    scheduler_append_task(&toggle_led_1, 1000);
    scheduler_append_task(&toggle_led_2, 500);
}

int main(void) {
    setup();

    while(1) {
        scheduler_update(millis());
    }

    return 0;
}
