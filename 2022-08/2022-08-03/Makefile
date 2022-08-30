CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

TARGET_MODULE := fibdrv
obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

BINS = testfib testbigadd fibdrv
testreverse: rnikg.c testreverse.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
analyzereverse: analyzereverse.c rnikg.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG) -std=gnu99 -O3
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)