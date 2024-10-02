# Linux Kernel Module Project

## Project Overview

This project consists of two main parts, both focused on developing and managing Linux kernel modules. The aim is to provide an understanding of how kernel modules are created, loaded, and managed in the Linux environment. Additionally, it will explore how to manipulate kernel data structures, specifically linked lists, within a kernel module.

### Part I — Creating a Kernel Module

In this part, you will learn how to create a simple Linux kernel module that outputs messages when it is loaded and unloaded. You will also explore how to compile, insert, and remove the module from the kernel. Basic kernel commands such as `insmod`, `rmmod`, and `dmesg` will be used to interact with the module and check kernel log messages.

### Part II — Kernel Data Structures

In the second part of the project, the kernel module will be expanded to use a linked list data structure. You will define a custom structure containing information (such as a birthday) and use Linux's `list_head` to manage a circular doubly-linked list. You will implement functions to insert elements into the list, traverse the list, and safely delete elements, ensuring memory is properly freed. The linked list will be manipulated using kernel macros and functions such as `list_for_each_entry` and `list_del`.

The goal of this part is to enhance your understanding of how kernel modules can manage complex data structures and interact with the system's memory management.
