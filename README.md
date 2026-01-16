# 🛠 HEX-Monitor System

## 🎯 Project Goal
This project represents a complete embedded system development cycle: from low-level driver implementation to non-blocking system architecture.
The device monitors a 4-bit DIP switch input and displays the hexadecimal value (0-F) on a 7-segment display using UART for debugging.

**Key Objective:** Transition from simple polling loops to a professional interrupt-based architecture.

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
- [ ] **Step 2.1: GPIO & Masking**
    - **Goal:** Read stable data from physical switches.
    - **Concepts:** Input Pull-ups (`PORTx`), Bitwise AND (`&`), Bit shifting (`>>`), Port Registers (`PINx`).

### Stage 3: Output Layer (7-Segment Display)
- [ ] **Step 3.1: Static Indication**
    - **Goal:** Display hex characters on the screen.
    - **Concepts:** Lookup Tables, Direct Port Manipulation (`DDRx`, `PORTx`), 7-seg encoding.

### Stage 4: System Core (Interrupts)
- [ ] **Step 4.1: Non-blocking Architecture**
    - **Goal:** Run display refresh and input polling in background.
    - **Concepts:** Timer1/Timer0 configuration, ISR (Interrupt Service Routines), Atomic operations.

---
## 📂 Project Structure
- `src/` - Main application logic (`main.cpp`)
- `src/drivers/` - Low-level hardware drivers (`uart.cpp`, `gpio.cpp`, `display.cpp`)
- `include/` - Header files (`uart.h`, `config.h`)
- `docs/` - Schematics, diagrams, and datasheets.