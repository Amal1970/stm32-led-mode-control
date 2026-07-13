# STM32 Bare-Metal Button Controlled LED

A bare-metal STM32F407 project demonstrating button-controlled LED operation using a Finite State Machine (FSM). This project was developed without STM32CubeIDE, HAL libraries, or an RTOS, using direct register programming in Embedded C.

The application cycles through different LED operating modes with each button press. Button presses are detected using software edge detection, providing a clean transition between states without relying on interrupts.

---

## Features

- Bare-metal Embedded C implementation
- Direct register programming
- GPIO input and output configuration
- Software edge detection
- Finite State Machine (FSM)
- Non-blocking LED blinking using SysTick
- Modular driver architecture
- GNU Make build system
- OpenOCD flashing support
- GDB debugging support
- Git version control throughout development

---

## Hardware

- STM32F407G Discovery Board
- USER Button (PA0)
- On-board Green LED (PD12)

---

## Project Structure

```
.
├── main.c
├── main.h
├── mode.c
├── mode.h
├── led.c
├── led.h
├── button.c
├── button.h
├── stm32_startup.c
├── stm32_ls.ld
├── Makefile
└── README.md
```

---

## Operating Modes

Each button press changes the LED operating mode.

```
OFF
 │
 ▼
ON
 │
 ▼
BLINK SLOW (500 ms)
 │
 ▼
BLINK FAST (100 ms)
 │
 ▼
OFF
```

---

## Finite State Machine

```
          Button Press

+------+     +------+     +-------------+     +-------------+
| OFF  | --> | ON   | --> | BLINK SLOW | --> | BLINK FAST |
+------+     +------+     +-------------+     +-------------+
    ^                                               |
    |_______________________________________________|
```

---

## Software Architecture

```
                 SysTick Interrupt
                        │
                        ▼
                  modes_update()
                        │
        ┌───────────────┴───────────────┐
        ▼                               ▼
 Edge Detection                  Mode State Machine
        │                               │
        └───────────────┬───────────────┘
                        ▼
                  LED Driver Layer
                        │
                        ▼
                 STM32 GPIO Registers
```

---

## Edge Detection

Instead of continuously acting while the button remains pressed, the application detects only the transition from **not pressed** to **pressed**.

```
Previous State    Current State    Event
----------------------------------------
0                 0               No
0                 1               Button Event
1                 1               No
1                 0               No
```

This ensures that one physical button press generates only one mode transition.

---

## Concepts Practiced

- Embedded C
- Bare-metal firmware development
- ARM Cortex-M4 GPIO programming
- SysTick timer
- Software timing
- Finite State Machines (FSM)
- Software edge detection
- Modular driver development
- GNU Make
- OpenOCD
- GDB debugging
- Git & GitHub workflow

---

## Building

```bash
make
```

---

## Flashing

```bash
make download
```

---

## Debugging

```bash
arm-none-eabi-gdb final.elf
```

Connect to OpenOCD:

```gdb
target remote localhost:3333
load
monitor reset init
continue
```

---

## Future Improvements

- External Interrupt (EXTI) based button handling
- Software debouncing
- Multiple button support
- Long press and double-click detection
- Low-power sleep mode with interrupt wake-up
- Event-driven application architecture

---

## Author

**Amalraj**

B.Tech Applied Electronics & Instrumentation Engineering

College of Engineering Trivandrum (CET)
