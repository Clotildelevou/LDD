#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Hello World module.");
MODULE_LICENSE("GPL v2");

static int num;
module_param(num, int, S_IRUGO);
//MODULE_PARAM_DESC(num, "Number of greets");

static char *greet;
module_param(greet, charp, S_IRUGO);
//MODULE_PARAM_DESC(greet, "The greet to repeat");

__init static int greet_init(void)
{
	int i = 0;
	for (; i < num; i++)
		printk(KERN_ALERT "%s\n", greet);
	return 0;
}
__exit static void greet_exit(void)
{
}

module_init(greet_init);
module_exit(greet_exit);
