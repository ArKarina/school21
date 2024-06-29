CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET1 = $(BUILDDIR)/Quest_1
TARGET2 = $(BUILDDIR)/Quest_2
TARGET3 = $(BUILDDIR)/Quest_3
TARGET4 = $(BUILDDIR)/Quest_4
TARGET5 = $(BUILDDIR)/Quest_5
SRC = print_module.c main_module_entry_point.c documentation_module.c bst.c bst_create_test.c bst_insert_test.c bst_traverse_test.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: print_module.o main_module_entry_point.o documentation_module.o
	$(CC) $(CFLAGS) $^ -o $(TARGET1)

documentation_module: print_module.o main_module_entry_point.o documentation_module.o
	$(CC) $(CFLAGS) $^ -o $(TARGET2)

bst_create_test: bst.o bst_create_test.o
	$(CC) $(CFLAGS) $^ -o $(TARGET3)

bst_insert_test: bst.o bst_insert_test.o
	$(CC) $(CFLAGS) $^ -o $(TARGET4)

bst_traverse_test: bst.o bst_traverse_test.o
	$(CC) $(CFLAGS) $^ -o $(TARGET5)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)

rebuild: clean all
