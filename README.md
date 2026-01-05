# LED Task Scheduler – PIC18F4550

##  Overview

This project implements a **simple cooperative task scheduler** for a PIC18F4550 microcontroller. The scheduler is driven by a **1 ms system tick generated using Timer0** and is used to execute periodic tasks, demonstrated through multiple LED blinking tasks.

The goal of this project is to demonstrate **bare‑metal embedded C development**, focusing on timing, interrupts, task scheduling, and clean software architecture.

---

##  Project Objectives

* Implement a 1 ms system tick using Timer0
* Design a cooperative (non‑preemptive) task scheduler
* Execute periodic tasks without blocking delays
* Maintain clear separation between HAL, scheduler, and application logic
* Demonstrate scalable task addition

---

##  Architecture

The project is divided into three logical layers:

###  Hardware Abstraction Layer (HAL)

* GPIO configuration and control
* Direct register access using bitwise operations
* No application logic

###  Scheduler Layer

* Timer0 interrupt generates a 1 ms tick
* `scheduler_tick()` updates task timing (ISR‑safe)
* Tasks are executed in the main loop
* No blocking delays or application logic inside the scheduler

###  Application Layer

* LED tasks implemented as periodic functions
* Each task has its own period and state
* Easy to add or remove tasks without modifying scheduler core

---

##  Scheduler Design

* **Type:** Cooperative scheduler
* **Tick source:** Timer0 interrupt (1 ms)
* **Task execution:** Main loop
* **Task structure includes:**

  * Function pointer
  * Period (ms)
  * Delay counter
  

This design ensures deterministic behavior and predictable timing.

---

##  Implemented Tasks

* LED blink task (500ms)
* LED blink task (200ms)

Additional tasks can be added by registering them with the scheduler without modifying its internal logic.

---

##  Tools & Environment

* **MCU:** PIC18F4550
* **Clock:** 20 MHz
* **Compiler:** XC8
* **Programmer:** PICkit (pk2cmd)
* **Development OS:** Linux
* **Language:** C (bare‑metal)

---

##  How to Build & Flash

```bash
make all
make flash
```

---

##  Project Structure

```
project/
├── inc/
│ ├── config.h # Global configuration macros and system settings
│ ├── gpio.h # GPIO hardware abstraction
│ ├── scheduler.h # Task scheduler interface
│ └── led_tasks.h # Application task declarations
├── src/
│ ├── gpio.c # GPIO implementation
│ ├── scheduler.c # Cooperative scheduler logic
│ └── led_tasks.c # LED task implementations
├── main.c # System initialization and main loop
├── Makefile
└── README.md
```


---

##  Author

**Cristopher Reyes Ramírez**
Embedded Software / Electronics Engineer

