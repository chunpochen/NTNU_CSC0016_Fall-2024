#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam");
MODULE_DESCRIPTION("Project 2 - Part I");
MODULE_VERSION("0.1");

static int __init list_tasks_init(void) {
	struct task_struct *task;
	
	printk(KERN_INFO "Loading module: listing tasks\n");
	
	for_each_process(task) {
		printk(KERN_INFO "Task: %s [PID = %d, State = %ld]\n",
			task->comm, task->pid, task->state);
	}

	return 0;
}

static void __exit list_tasks_exit(void) {
	printk(KERN_INFO "Removing module: tasks listing complete\n");
}

module_init(list_tasks_init);
module_exit(list_tasks_exit);
