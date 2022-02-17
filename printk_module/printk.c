#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Printk exprotedmodule.");
MODULE_LICENSE("GPL v2");

int my_printk(int a)
{
	printk(KERN_ALERT "%d\n", a);
	return 0;
}

EXPORT_SYMBOL(my_printk);
