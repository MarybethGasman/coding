CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  printmsg
printmsg: printmsg.c
	$(CC) $(FLAGS) -o $@ $^ -O3 -g

clean:
	rm $(BINS)