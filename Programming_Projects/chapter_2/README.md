# Linux Kernel Module Project

## Project Overview

This project is designed to teach the fundamental concepts of working with Linux kernel modules and utilizing kernel-level data structures like linked lists. The project is divided into two main parts:

### Part I — Creating a Kernel Module

The first part focuses on building a basic Linux kernel module. A kernel module is a piece of code that can be loaded into the kernel to extend its functionality without needing to reboot or recompile the entire kernel. 

In this part, you will:
- Create a simple kernel module that prints log messages when it is loaded and removed from the kernel. These messages will be recorded in the kernel's log buffer and can be viewed using the `dmesg` command.
- You will use the `insmod` command to insert the compiled module into the running Linux kernel and the `rmmod` command to remove it. 
- The purpose of this part is to get familiar with the mechanics of interacting with kernel modules in Linux, including loading, unloading, and logging their activity in the kernel environment.

By the end of this section, you should have a basic understanding of how to:
- Write a kernel module.
- Compile the module using the provided `Makefile`.
- Load and unload the module from the Linux kernel using terminal commands.
- View kernel messages related to module loading and unloading using the `dmesg` command.

This part serves as an introduction to the kernel module lifecycle and provides insights into how modules can extend kernel functionality in a modular way.

### Part II — Kernel Data Structures (Linked List Implementation)

The second part of the project builds on the foundation from Part I by introducing kernel-level data structure management, specifically the use of linked lists.

In this part, you will:
- Modify the kernel module you created in Part I to manage a circular doubly linked list, a common data structure in the Linux kernel, using the `list_head` structure from the `<linux/list.h>` header.
- The list will store entries of a custom-defined `birthday` structure, which holds data such as the day, month, and year.
- You will insert, traverse, and delete nodes from this linked list within the kernel module. This will involve creating new entries, adding them to the list, iterating over the list to display its contents, and finally removing the elements and freeing the associated memory.

Key operations you will implement:
- **Insertion**: You will dynamically allocate memory for new elements using `kmalloc()` and link them into the list using the `list_add_tail()` macro.
- **Traversal**: Using the `list_for_each_entry()` macro, you will traverse the linked list to print out each element's data, which will be logged in the kernel buffer.
- **Deletion**: Finally, you will remove each element from the list using `list_del()`, and free the memory with `kfree()` to prevent memory leaks.

By the end of this section, you should understand:
- How to use kernel macros to manage linked lists within kernel space.
- The process of dynamically allocating and deallocating memory within a kernel module.
- How to avoid memory leaks by correctly managing memory allocation and freeing within the kernel environment.

### Key Learning Objectives

This project will provide you with:
1. **Familiarity with kernel modules**: You'll gain a working knowledge of how to write, load, and remove kernel modules in a Linux system.
2. **Understanding of kernel logging**: You will learn how to use `printk()` for kernel logging and how to view log messages with `dmesg`.
3. **Practical experience with kernel data structures**: You'll get hands-on experience in manipulating kernel-linked lists, a fundamental data structure used in many kernel subsystems.
4. **Memory management in the kernel**: You'll understand how dynamic memory allocation works in kernel space and how to properly free memory to avoid memory leaks.

### Summary of Commands and Tools

Throughout this project, you will use the following commands and tools:
- `insmod`: To load your kernel module into the running Linux kernel.
- `rmmod`: To remove your module from the kernel.
- `dmesg`: To view kernel logs and messages, including the ones printed by your module.
- Kernel programming tools, including `kmalloc()` for memory allocation and `kfree()` for memory deallocation.
