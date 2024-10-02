#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/list.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam");
MODULE_DESCRIPTION("Project 2 - Part II");
MODULE_VERSION("0.1");

void dfs_task_tree(struct task_struct *task) {
	struct task_struct *child;
	struct list_head *list;

	printk(KERN_INFO "Task: %s [PID = %d, State = %ld]\n",
		task->comm, task->pid, task->state);
	
	list_for_each(list, &task->children) {
		child = list_entry(list, struct task_struct, sibling);
		dfs_task_tree(child);
	}
}


static int __init list_tasks_dfs_init(void) {
	printk(KERN_INFO "Loading module: listing tasks with DFS\n");
	dfs_task_tree(&init_task);
	return 0;
}


static void __exit list_tasks_dfs_exit(void) {
	printk(KERN_INFO "Removing module: DFS task listing complete\n");
}

module_init(list_tasks_dfs_init);
module_exit(list_tasks_dfs_exit);

