# 🚦 STM32F407 Traffic Light Simulation

This project simulates a traffic light system using the **STM32F407 Discovery** board. It utilizes **Timer**, **GPIO**, and **Interrupts** to control light states and handle button inputs.

## 📌 Project Goals

- Use **Timer2** with periodic interrupts to control automatic traffic light transitions.
- Support **4 buttons** for manual light control:
  - `RED_BUTTON` → Turn on the red light
  - `GREEN_BUTTON` → Turn on the green light
  - `YELLOW_BUTTON` → Flash the yellow light (warning mode)
  - `RESET_BUTTON` → Reset to the initial state

## 🧱 Hardware Requirements

- STM32F407 Discovery board
- 3 LEDs for Red, Yellow, and Green lights (connected to `GPIOB`)
- 4 push buttons (connected to `GPIOD`)
- Pull-up resistors if necessary

## ⚙️ Timer2 Configuration

Timer2 is initialized with:
```
htim2.Init.Prescaler = 1599;
htim2.Init.Period = 99;
```
→ This triggers an interrupt roughly every 1ms and calls the runLight() function.

## 💡 Operating Logic

Default Mode: The system runs in automatic mode, cycling through lights with a timer.
Manual Mode:
- Pressing a button will override automatic mode and control a specific light.
- The yellow light can blink to simulate a caution/warning state.
- The reset button restores automatic mode.

## 🧩 Key Files

- main.c: Main loop, handles button reading and system initialization.
- timer.c / timer.h: (Custom implementation) Handles state transitions and light control.
  
## Key functions

- runLight()
- manual_light(RED|YELLOW|GREEN)
- reset_light()
- turn_off_light()

## 🧠 Concepts Covered

- STM32 GPIO Input/Output
- Timer-based Interrupts
- State machine programming
- Software-based button debounce

## ✍️ Author

Project by [Uri]
