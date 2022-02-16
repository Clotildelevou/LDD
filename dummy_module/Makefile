# Au choix :
# Sources de mon kernel

KDIR := /lib/modules/$(shell uname -r)/build
# OU headers spécifiques

KDIR := /usr/src/linux-headers-$(shell uname -r)

PWD := $(shell pwd)

obj-m := dumbest.o

clean modules_install modules:
	make -C $(KDIR) M=$(PWD) $@
