CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g
BINS = dfa testbitmap testcasegenerator analyzequickselect testpartition debugquickselect
dfa: simpleDFA.c
	$(CC) $(FLAGS) -o $@ $^ bitmap.c
testbitmap: bitmap.c testbitmap.c
	$(CC) $(FLAGS) -o $@ $^
testpartition: quickselect.c testpartition.c
	$(CC) $(FLAGS) -o $@ $^
debugquickselect: debugquickselect.c quickselect.c
	$(CC) $(FLAGS) $(DBGFLAG) -o $@ $^
analyzequickselect: analyzequickselect.c quickselect.c
	$(CC) $(FLAGS) $(DBGFLAG) -o $@ $^
testcasegenerator: testcasegenerator.c
	$(CC) $(FLAGS) $(DBGFLAG) -o $@ $^
clean:
	rm $(BINS)