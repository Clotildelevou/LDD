#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/cdev.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("Lifecycle module.");
MODULE_LICENSE("GPL v2");

struct my_dev {
	struct cdev dev;
};

static int major;

static struct my_dev *new_dev;

const struct file_operations ops = {
	.owner = THIS_MODULE,
};

__exit static void life_cycle_exit(void)
{
	cdev_del(&new_dev->dev);
	unregister_chrdev_region(42, 1);
	kfree(new_dev);
}

__init static int life_cycle_init(void)
{
	dev_t dev;
	int ret;
	major = alloc_chrdev_region(&dev, 42, 1, "life_cycle");

	if (major == 0)
		printk(KERN_INFO "Error in major allocation");

	new_dev = kmalloc(sizeof(struct my_dev), GFP_KERNEL);
	cdev_init(&new_dev->dev, &ops);

	ret = cdev_add(&new_dev->dev, dev, 1);
	if (ret == -1)
		life_cycle_exit();

	return 0;
}

module_init(life_cycle_init);
module_exit(life_cycle_exit);
