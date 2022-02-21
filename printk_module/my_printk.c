#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Printk exprotedmodule.");
MODULE_LICENSE("GPL v2");

void foo(int a)
{
	printk(KERN_INFO "foo: %d\n", a);
}

EXPORT_SYMBOL(foo);
