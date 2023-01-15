CFILES = my_device.c sub_driver.c

obj-m += hello.o
hello-objs := $(CFILES:.c=.o)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) V=1 modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

