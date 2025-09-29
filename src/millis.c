#include "millis.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>

static volatile uint32_t ms = 0;
void (*callback)(void) = NULL;

ISR(TIMER0_COMPA_vect) {
    ms++;
    if (callback != NULL) {
        callback();
    }
}

// normal mode, prescaler 64, max value 249: exactly 1 interrupt per ms
void millis_init(void (*new_callback)(void)) {
    cli();
    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    TIMSK0 = (1 << OCIE0A);
    OCR0A = 249;
    sei();

    callback = new_callback;
}

uint32_t millis(void) {
    uint32_t ms_now;
    uint8_t sreg = SREG;

    cli();
    ms_now = ms;
    SREG = sreg;

    return ms_now;
}
