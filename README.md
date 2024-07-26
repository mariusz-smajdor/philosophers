# Philosophers

This project is part of the 42 School curriculum and involves implementing the classic "Dining Philosophers" problem using threads and synchronization techniques in C.
The objective is to ensure that no philosopher starves and that the program handles concurrency issues correctly.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)

## Overview

The Dining Philosophers problem is a classic synchronization problem.
It involves a certain number of philosophers who alternate between thinking, eating and sleeping.
Each philosopher needs two forks to eat, but there are only as many forks as philosophers.
The challenge is to design a system where philosophers can eat without causing a deadlock or starving.

## Project Structure

- `init_data/` - Directory containing data initialization code.
  - `index.c` - Functions that handle data initialization.
  - `inline_functions.c` - Utility functions for data initializaion.
- `start_sim/` - Directory containing functions to handle the philosophers' behavior and simulation logic.
  - `index.c` - Functions that initialize the simulation.
  - `monitor.c` - Routine functions that check the simulation state.
  - `philo_routine.c` - Routine functions to handle the philosophers' behavior and simulation logic.
- `Makefile` - File to build the project.
- `clear_data.c` - Functions to clear the data after the simulation is over.
- `philo.c` - Entry point of the program.
- `philo.h` - Header file with function prototypes and definitions.
- `utils.c` - Utility functions for handling timing and other helper tasks.

## Requirements

- A Unix-like operating system (Linux, macOS)
- GCC (GNU Compiler Collection)
- pthread library

## Installation

1. Clone the repository:
```bash
git clone https://github.com/mariusz-smajdor/philosophers.git && cd philosophers
```

2. Build the project:
```bash
make
```

## Usage

Run the program with following command:
```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die`: Time in milliseconds a philosopher can go without eating before dying.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation ends. If not specified, the simulation runs indefinitely.

Example:
```bash
./philosophers 5 800 200 200
```
