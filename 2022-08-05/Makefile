CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

TARGET_MODULE := fibdrv
obj-m := $(TARGET_MODULE).o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

BINS =  Graph trival_bank
trival_bank: trival_bank.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3
incorrect_peterson: incorrect_peterson.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3
correct_peterson: correct_peterson.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3
testspinlock: testspinlock.c spinlock.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3
rrprint: rrprint.c spinlock.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3
correctrrprint: correctrrprint.c
	$(CC) $(FLAGS) -o $@ $^ -pthread -O3

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG) -DUNDIRECTED

draw:
	gnuplot draw.gp -p

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)