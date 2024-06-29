CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET = $(BUILDDIR)/graph
SRC = graph.c stack.c tokenize.c rpn.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET)

rebuild: clean all
