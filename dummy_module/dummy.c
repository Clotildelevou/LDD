#include <linux/module.h>

MODULE_AUTHOR("Clotilde Levesque");
MODULE_DESCRIPTION("World's dumbest module.");
MODULE_LICENSE("GPL v2");

/* Pas de license = propriétaire */
__init static int dumb_init(void)
{
	/* Prepare stuff... */
	return 0;
}
__exit static void dumb_exit(void)
{
	/* Clean up stuff... */
}
module_init(dumb_init);
module_exit(dumb_exit);
