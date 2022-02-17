#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Printk exprotedmodule.");
MODULE_LICENSE("GPL v2");

int my_printk(void)
{
	printk(KERN_ALERT "Hello World\n");
	return 0;
}

EXPORT_SYMBOL(my_printk);
