CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  Graph trival_bank
testchange: testchange.c bt.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
testlis: testlis.c bt.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG)

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)