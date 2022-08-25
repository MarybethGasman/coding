include config.mak
COMMON_CFLAGS += -Wall -Wwrite-strings -Wclobbered -Wempty-body -Wuninitialized
COMMON_CFLAGS += -Wignored-qualifiers -Wunused-but-set-parameter
COMMON_CFLAGS += -Wmissing-prototypes
# -Wstrict-prototypes
COMMON_CFLAGS += -Werror -Wno-unused-result

FLAGS = -std=c99 -Wextra -I.
DBGFLAG = -g

BINS =  iqsort
iqsort: iqsort.c
	$(CC) $(COMMON_CFLAGS) $(FLAGS) -o $@ $^ $(DBGFLAG)

clean:
	rm -f $(BINS)