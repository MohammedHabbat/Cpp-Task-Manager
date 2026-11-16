# C++ Task Manager (Memo App)

## Overview
This project is a simple Command-Line Interface (CLI) Task Manager application written in C++. 
It allows users to manage their daily tasks efficiently through a clean terminal menu.

## Features
- **Add Task:** Add a new task with a custom description.
- **Delete Task:** Remove a specific task by its number.
- **Display Tasks:** View all tasks in order.
- **Reverse Display:** View all tasks from bottom to top.

## Data Structure Used
This project utilizes a **Doubly Linked List** to store tasks dynamically in memory. It uses pointers (`head`, `tail`, `next`, `prev`) to allow efficient insertion, deletion, and bidirectional traversal (which enables the reverse display feature).

## How to Run
1. Download the `.cpp` file from this repository.
2. Compile it using a C++ compiler (e.g., g++):
   ```bash
   g++ main.cpp -o TaskManager
