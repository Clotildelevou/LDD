KDIR := /usr/src/linux-headers-$(shell uname -r)
PWD := $(shell pwd)
obj-m := printk.o

modules:
	make -C $(KDIR) M=$(PWD) modules
modules_install:
	make -C $(KDIR) M=$(PWD) modules_install
clean:
	make -C $(KDIR) ML=$(PWD) clean
