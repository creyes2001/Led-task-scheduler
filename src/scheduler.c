#include "scheduler.h"

static scheduler_task_t task_list[MAX_TASKS];
static uint8_t task_count = 0;

void scheduler_init(void)
{
	for(uint8_t i = 0; i < MAX_TASKS; i++)
	{
		task_list[i].task = 0;
		task_list[i].period_ms = 0;
		task_list[i].counter_ms = 0;
		task_list[i].ready = 0;
	}

	task_count = 0;
}

void scheduler_run(void)
{
	for(uint8_t i = 0; i < task_count; i++)
	{
		if(task_list[i].ready)
		{
			task_list[i].ready = 0;
			task_list[i].task();
		}
	}
}

void scheduler_tick(void)
{
	for(uint8_t i = 0; i < task_count; i++)
	{
		task_list[i].counter_ms++;

		if(task_list[i].counter_ms >= task_list[i].period_ms)
		{
			task_list[i].counter_ms = 0;
			task_list[i].ready = 1;
		}
	}
}

uint8_t scheduler_add_task(task_func_t task,uint16_t period_ms)
{
	if(task_count >= MAX_TASKS)
	{
		return 0;
	}

	task_list[task_count].task = task;	
	task_list[task_count].period_ms = period_ms;
	task_list[task_count].counter_ms = 0;
	task_list[task_count].ready = 0;

	task_count++;
	return 1;
}

