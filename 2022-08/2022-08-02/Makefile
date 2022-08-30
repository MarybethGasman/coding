CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

TARGET_MODULE := fibdrv
obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

BINS = testfib testbigadd fibdrv
testfib: testfib.c fib.c
	$(CC) -lrt $(FLAGS) -o $@ $^ $(DBGFLAG) -std=gnu99
testbigadd: testbigadd.c fib.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
fibdrv: fibdrv.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules
testfibdrv: client.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
lseek: lseek.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)