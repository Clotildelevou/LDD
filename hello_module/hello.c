#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Hello World module.");
MODULE_LICENSE("GPL v2");

__init static int hello_init(void)
{
	printk(KERN_ALERT "Hello World\n");
	return 0;
}
__exit static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye World\n");
}

module_init(hello_init);
module_exit(hello_exit);
