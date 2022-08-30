CC = gcc
FLAGS = -std=gnu99 -Wall -Wextra -I.
DBGFLAG = -g

BINS =  get_cpu_temp \
		get_file_size \
		get_time get_mac \
		member_size \
		file_opt \
		progress_bar \
		core
all: $(BINS)

get_cpu_temp: get_cpu_temp.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
get_file_size: get_file_size.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
get_time: get_time.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
get_mac: get_mac.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
member_size: member_size.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
file_opt: file_opt.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
progress_bar: progress_bar.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
core: core.c
	$(CC) $(FLAGS) -o $@ $^ $(DBGFLAG)
clean:
	rm -f $(BINS)