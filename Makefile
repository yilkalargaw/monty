CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(wildcard *.h)

monty: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean

clean:
	rm -f $(OBJS) monty
