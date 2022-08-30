CC = gcc
FLAGS = -std=gnu99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  testrbtree
testrbtree: testrbtree.c rbtree.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)

clean:
	rm $(BINS)