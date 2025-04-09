NAME = clox/clox
SRCS = $(shell find clox -name *.c)
OBJS = $(SRCS:.c=.o)
CC   = clang

all: build run

build: $(OBJS)
	$(CC) -Wall -O2 -o $(NAME) $(OBJS)

run:
	./clox/clox

.c.o:
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)
