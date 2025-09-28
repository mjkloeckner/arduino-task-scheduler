#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
    void (*task_update)(void);
    uint16_t update_interval;
    uint8_t task_id;
    uint16_t ticks;
} task_t;

typedef struct {
    uint32_t t_ms_dt;
    uint8_t task_cnt;
    task_t *tasks;
} scheduler_t;

void scheduler_init(task_t *tasks, uint8_t task_count);
void scheduler_update(uint32_t t_ms);

#ifdef __cplusplus
}
#endif

#endif // _SCHEDULER_H_
