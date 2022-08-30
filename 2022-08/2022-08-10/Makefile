CC = gcc
FLAGS = -std=c99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  Graph trival_bank
printmsg: printmsg.c
	$(CC) $(FLAGS) -o $@ $^ -O3

CPP = g++
CPPFLAGS = -std=c++17 -Wall -Wextra -I.
Graph: Graph.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG)
helloworld: helloworld.cpp
bucketsort: bucketsort.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^ $(DBGFLAG)

draw:
	gnuplot draw.gp -p

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm $(BINS)