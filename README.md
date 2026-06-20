# 🕹️ C++ Classical Tetris Engine

A fully interactive, native desktop implementation of the classical **Tetris** game architecture built using **C++** and low-level graphics processing frameworks. This project highlights fundamental structural engineering, real-time game loops, event handling, and algorithmic matrix grid state evaluation.

Developed individually as part of the **Programming Fundamentals (CS1002)** curriculum at **FAST-NUCES** (Fall 2022).

---

### 🎨 Key Core Engine Features

* **Dynamic State Processing & Game Loop:** Handles real-time positional rendering, continuous vertical gravity increments, and instant keyboard interrupt mapping (left, right, rotate, drop).
* **Matrix Grid Math:** Tracks collision detection thresholds, bounding box matrices, and instant structural grid parsing to calculate simultaneous multi-line clearances.
* **Predictive Shadow Blueprinting:** Features real-time projection matrix rendering to map a dynamic ghost shadow at the absolute terminal landing coordinate before a piece is dropped.
* **Algorithmic Disruption (The Bomb Mechanic):** Integrates randomized game-modifier drops featuring contextual metadata validation (destroying matching colors or clearing adjacent localized structures).
* **File I/O Persistence:** Manages high-score logging array cycles via reading and over-writing direct disk configurations (`highscores.txt`).
* **Context Preservation (Pause State Matrices):** Leverages structural nested menus allowing users to pause active game loops without losing active matrix parameters.

---

### 🕹️ Gameplay & Controls

* **Left / Right Arrows:** Shift Tetriminos along the horizontal axis.
* **Up Arrow / Rotation Trigger:** Matrix-transform rotation.
* **Down Arrow:** Manual velocity acceleration (Soft Drop).
* **P Key:** Triggers context menu pausing.

---

### 🛠️ Architecture & Core Dependencies

* **Language:** Pure C++ (OOP Fundamentals, Structured Array Compilations).
* **Rendering Engine:** Graphics assets managed via native framework canvas configurations.
* **Data Structures:** Fixed multi-dimensional arrays for piece patterns (I, O, L, J, S, Z, T patterns) and dynamic array shifts for structural ranking.
