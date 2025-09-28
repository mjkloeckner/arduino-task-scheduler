#ifndef _TIMER_H_
#define _TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void millis_init(void);
uint32_t millis(void);

#ifdef __cplusplus
}
#endif

#endif // _TIMER_H_
