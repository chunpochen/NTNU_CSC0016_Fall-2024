#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;	
};

static LIST_HEAD(birthday_list);

int simple_init(void) {
	struct birthday *person;
	struct birthday *ptr;
	int i;

	for(i = 0; i < 5; i++) {
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = i + 1;
		person->month = i + 1;
		person->year = 1995 + i;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}	
	printk(KERN_INFO "Module loaded, birthdays inserted\n");

	list_for_each_entry(ptr, &birthday_list, list) {
		printk(KERN_INFO "Birthday: %d-%d-%d\n", ptr->day, ptr->month, ptr->year);	
	}	
	return 0;
}

void simple_exit(void)
{
    struct birthday *ptr, *next;
    
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        printk(KERN_INFO "Removing birthday: %d-%d-%d\n", ptr->day, ptr->month, ptr->year);
        list_del(&ptr->list);
        kfree(ptr);
    }

    printk(KERN_INFO "Module removed, all birthdays removed\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module for Birthday Linked List");
MODULE_AUTHOR("CPCHEN");
