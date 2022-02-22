#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Lifecycle module.");
MODULE_LICENSE("GPL v2");

static int major;
struct cdev my_dev;

__init static int life_cycle_init(void)
{
	dev_t dev;
	major = alloc_chrdev_region(&dev, 42, 1, "life_cycle");

	if (major == 0) {
		printk(KERN_INFO "Error in major allocation");
	}

	return 0;
}
__exit static void life_cycle_exit(void)
{
	/* Clean up stuff... */
}
module_init(life_cycle_init);
module_exit(life_cycle_exit);
