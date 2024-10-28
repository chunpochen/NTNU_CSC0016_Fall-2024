# Linux Kernel Process Information System Call Project

This project involves adding a custom system call to the Linux kernel to collect and display process information. The system call will gather details about the current process, including its state, priority, process IDs, CPU usage time, and other attributes, structured in the following format:

```c
struct prinfo {
    long state;                /* current state of process */
    long nice;                 /* process nice value */
    pid_t pid;                 /* process id */
    pid_t parent_pid;          /* process id of parent */
    pid_t youngest_child_pid;  /* pid of youngest child */
    unsigned long start_time;  /* process start time */
    long user_time;            /* CPU time spent in user mode */
    long sys_time;             /* CPU time spent in system mode */
    long uid;                  /* user id of process owner */
    char comm[16];             /* name of program executed */
};
```

## Project Requirements

- Implementation Steps: Sequentially record steps taken to implement the system call, including any modified files or code changes.
- Demonstration: Run the test program in user space under two different shells, and capture the output showing process information for each shell.
- Comments and Challenges: Document any challenges encountered during implementation and describe the solutions.
- References and Code: List any references used and include the full code in the appendix with a compact format.

## Tips

1. The implementations of the system calls `getuid()` and `getpid()` in the file `kernel/timer.c` can provide some guidance.
2. Almost all of the process information needed to fill in the `prinfo` structure can be found in the structure `task_struct`, defined in the file `include/linux/sched.h`.
3. The kernel file `include/asm/current.h` defines an inline function that returns the address of the `task_struct` of the current process.
4. Every system call must check the validity of arguments passed by a caller. The Linux kernel provides two functions, `copy_from_user()` and `copy_to_user()`, which not only check validity but also transfer information between kernel and user levels. Use them to move the process information.
