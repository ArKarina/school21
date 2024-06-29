CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET1 = $(BUILDDIR)/Quest_1
TARGET2 = $(BUILDDIR)/Quest_2
TARGET3 = $(BUILDDIR)/Quest_3
SRC = dmanager_module.c list.c list_test.c stack_test.c stack.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: door_struct list_test stack_test

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) $^ -o $(TARGET1)

list_test: list.o list_test.o
	$(CC) $(CFLAGS) $^ -o $(TARGET2)

stack_test: stack.o stack_test.o
	$(CC) $(CFLAGS) $^ -o $(TARGET3)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET1) $(TARGET2) $(TARGET3)

rebuild: clean all
