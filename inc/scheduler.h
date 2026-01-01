#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#define MAX_TASKS 5

typedef void (*task_func_t)(void);


typedef struct
{
	task_func_t task;
	uint16_t period_ms;
	uint16_t counter_ms;
	uint8_t ready;
}scheduler_task_t;

void scheduler_init(void);
void scheduler_run(void);
void scheduler_tick(void);
uint8_t scheduler_add_task(task_func_t task, uint16_t period_ms);

#endif
