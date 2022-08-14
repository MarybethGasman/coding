CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  Gratestknapsackph testlcs testllsort
testknapsack: testknapsack.c knapsack.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
testlcs: testlcs.c lcs.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
testllsort: testllsort.c llist.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG)

clean:
	rm $(BINS)