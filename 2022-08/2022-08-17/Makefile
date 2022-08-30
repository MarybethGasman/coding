CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  testringbuffer
testringbuffer: testringbuffer.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG) -pthread

clean:
	rm $(BINS)