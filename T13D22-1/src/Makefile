CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET1 = $(BUILDDIR)/cipher
TARGET2 = $(BUILDDIR)/logging_cipher
SRC = cipher.c logger.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: cipher logging_cipher

cipher: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET1)

logging_cipher: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(TARGET2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TARGET1) $(TARGET2)

rebuild: clean all
