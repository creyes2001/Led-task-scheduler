#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*task_func_t)(void);

typedef struct
{
	task_func_t task;
	uint16_t period_ms;
	uint16_t last_run;
}scheduler_task_t;

void scheduler_int(void);
void scheduler_run(void);
void scheduler_tick(void);

#endif
