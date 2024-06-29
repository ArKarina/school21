CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET1 = $(BUILDDIR)/Quest_1
TARGET2 = $(BUILDDIR)/Quest_2
TARGET3 = $(BUILDDIR)/Quest_3
SRC = state_sort.c state_search.c clear_state.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: state_sort state_search clear_state


state_sort: state_sort.o
	$(CC) $(CFLAGS) $< -o $(TARGET1)

state_search: state_search.o
	$(CC) $(CFLAGS) $< -o $(TARGET2)

clear_state: clear_state.o
	$(CC) $(CFLAGS) $< -o $(TARGET3)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET1) $(TARGET2) $(TARGET3)

rebuild: clean all
