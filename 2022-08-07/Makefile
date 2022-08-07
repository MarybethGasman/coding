CC = gcc
FLAGS = -std=c99 -Wall -Wconversion -Wsign-conversion -Wextra -I.
DBGFLAG = -g

TARGET_MODULE := fibdrv
obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

BINS =  Graph trival_bank
testfork: testfork.c
	$(CC) $(FLAGS) -o $@ $^ -O3 -g

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG) -DUNDIRECTED

draw:
	gnuplot draw.gp -p

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)