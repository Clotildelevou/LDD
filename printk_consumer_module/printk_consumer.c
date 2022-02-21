#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("printk consumer module.");
MODULE_LICENSE("GPL v2");

void foo(int a);

__init static int printk_consumer_init(void)
{
	foo(1);
	return 0;
}
__exit static void printk_consumer_exit(void)
{
	/* Clean up stuff... */
}

module_init(printk_consumer_init);
module_exit(printk_consumer_exit);
