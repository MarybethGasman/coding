CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

TARGET_MODULE := fibdrv
obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

BINS = dfaadd analyzereverse Graph
dfaadd: dfaadd.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
analyzereverse: analyzereverse.c rnikg.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG) -std=gnu99 -O3

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG)
draw:
	gnuplot draw.gp -p

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)