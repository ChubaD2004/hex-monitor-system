# 🛠 HEX-Monitor System
It reads a 4-bit physical input from a DIP-switch and displays the value in a user-friendly **Decimal format (00-15)** on a dual-digit 7-segment display.

### 🌟 Key Achievements:
- **Non-blocking Architecture:** System logic is entirely driven by **Timer1 interrupts (100Hz)**, freeing up the CPU for background tasks.
- **Hardware Multiplexing:** Implemented a manual bus for segment pins to drive two digits using only 9 GPIOs instead of 14-Metal AVR.

**Status:** ✅ Project Completed (February 2026)

---

## 🧠 Engineering Principles
During development, the following professional embedded standards were applied:

1. **Layered Architecture:** Clear separation between hardware drivers (`drivers/`) and application logic (`system.cpp`).
2. **Direct Register Debug Interface:** A custom low-level UART driver provides real-time system status and boot logs without conflicting with the display Manipulation:** Zero reliance on Arduino's `digitalWrite` or `delay`. All I/O is handled via `PORT hardware.

---

## 🌟 Project Overview
This project is a high-level simulation of a professional embedded system development cycle. It transforms a simple 4-bit DIP-switch input into a stable, non-blocking dual-digit decimal display (00-15) using an ATmega328P microcontroller.

### 🚀 Key Results & Features
- **Non-blocking Architecture:** System logic runs entirely on Timer1 interrupts.
- **Conflict Resolution:** Successfully resolved hardware resource contention between the UART (Serial) and the Display by implementing customISR), keeping the CPU free for background tasks.
- **Hardware Multiplexing:** Implemented a shared 7-segment data bus for two digits bitwise shifting logic.
- **Modular Driver Design:** Created independent, reusable drivers for GPIO, UART, and , controlled via high-speed switching (100Hz) to utilize the Persistence of Vision (POV) effect.
- **Decimal Logic:** Real-time mathematical conversion from binary input to human-readable decimal format (Tens/Units).
- **UART7-Segment displays.

---

## 🏗 Core Engineering Principles
During development, the following professional practices were implemented:
1. **Layered Architecturex`, `DDRx`, and `PINx` for maximum speed and minimum binary size.
3. **Memory:** Clear separation between hardware drivers (`drivers/`) and application logic (`system.cpp`).
2. **Direct Register Safety:** Use of the `volatile` keyword for shared data between ISR and the main loop to prevent compiler optimization bugs.
4. **Ghosting Prevention Manipulation:** No high-level Arduino libraries used for core functions. All I/O, Timers, and UART are configured at:** Implemented a "Disable -> Update -> Enable" sequence in the multiplexing logic to ensure a crystal-clear display output the bit level.
3. **Resource Conflict Resolution:** Successfully resolved a hardware pin conflict between UART (RX/TX) and the display.

---

## 📂 Project Structure
- `src/` - Main application entry point.
- `src/system bus through port re-mapping and bit-shifting logic.
4. **Memory Safety:** Use of `volatile` keyword for.cpp` - System Core (ISR, Task management).
- `src/drivers/` - Low-level drivers (`uart.cpp`, `dip_switch.cpp`, `segment.cpp`).
- `include/` - Public header files and shared data between ISR and main loop, and bitmasking for "surgical" port updates.

---

## 🗺 Learning interfaces.
- `schematic/` - KiCad schematics and hardware datasheets.

---

## 🗺 Learning Roadmap & Progress

The development is divided into logical stages based on the "Layered Architecture" principle.

### Stage 1: Infrastructure & UART Debugging
- [X] **Step 1.1: Project Setup**
    - **Goal:** Initialize repository, folder structure, and version control.
    - **Concepts:** Git Flow, PlatformIO Structure, Modular Design.

- [X] **Step 1.2: UART Driver Implementation**
    - **Goal:** Create a communication channel for debugging.
    - **Concepts:** Baud Rate calculations (`UBRR0`), Control Registers (`UCSR0B`), Buffer handling.

### Stage 2: Input Layer (DIP-Switch)
- [X] **Step 2.1: GPIO & Masking**
    - **Goal:** Read stable data from physical switches.
    - **Concepts:** Input Pull-ups (`PORTx`), Bitwise AND (`&`), Bit shifting (`>>`), Port Registers (`PINx`).

### Stage 3: Output Layer (7-Segment Display)
- [X] **Step 3.1: Static Indication**
    - **Goal:** Display hex characters on the screen.
    - **Concepts:** Lookup Tables, Direct Port Manipulation (`DDRx`, `PORTx`), 7-seg encoding.

### Stage 4: System Core (Interrupts)
- [X] **Step 4.1: Non-blocking Architecture**
    - **Goal:** Run display refresh and input polling in background.
    - **Concepts:** Timer1/Timer0 configuration, ISR (Interrupt Service Routines), Atomic operations.

---