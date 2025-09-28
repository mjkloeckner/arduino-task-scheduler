#include "scheduler.h"

#ifdef __cplusplus
extern "C" {
#endif

static scheduler_t scheduler = {0};

// update every 1 ms
void scheduler_update(uint32_t t_ms) {
    if ((t_ms - scheduler.t_ms_dt) < 1) {
        return;
    }

    scheduler.t_ms_dt = t_ms;

    for (uint8_t i = 0; i < scheduler.task_cnt; ++i) {
        if (scheduler.tasks[i].ticks > 1) {
            scheduler.tasks[i].ticks--;
            continue;
        }

        scheduler.tasks[i].ticks = scheduler.tasks[i].update_interval;
        scheduler.tasks[i].task_update();
    }
}

void scheduler_init(task_t *tasks, uint8_t task_count) {
    scheduler.tasks = tasks;
    scheduler.task_cnt = task_count;
}

#ifdef __cplusplus
}
#endif
