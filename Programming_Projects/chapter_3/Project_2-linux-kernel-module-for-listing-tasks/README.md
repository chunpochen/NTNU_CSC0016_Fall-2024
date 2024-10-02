# Project 2 - Linux Kernel Module for Listing Tasks
This project implements a Linux kernel module that lists all current tasks in the system. The module consists of two parts:
1. **Linear Task Iteration**: Iterates over all tasks in the system and logs each task's name, state, and PID.
2. **Depth-First Search (DFS) Task Iteration**: Recursively traverses the task hierarchy starting from the `init` task, logging similar information for each task.

## Features
- **Part I**: Uses `for_each_process` to list all tasks linearly.
- **Part II**: Uses DFS to iterate through tasks, starting from the `init` task.

## Usage
1. Load the module:
    ```bash
    sudo insmod XXX.ko

2. View task output:  
    ```bash
    dmesg

3. Remove the module:
    ```bash
    sudo rmmod XXX.ko
