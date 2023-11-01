
ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m   := hello1.o hello2.o 
else
# normal makefile
KDIR := ~/repos/linux-stable
ccflags-y += -I$(PWD)/inc

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
