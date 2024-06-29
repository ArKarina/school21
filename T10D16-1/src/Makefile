CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../build
TARGET1 = $(BUILDDIR)/Quest_1
TARGET2 = $(BUILDDIR)/Quest_2
TARGET3 = $(BUILDDIR)/Quest_3
TARGET4 = $(BUILDDIR)/Quest_4
TARGET5 = $(BUILDDIR)/Quest_5
TARGET6 = $(BUILDDIR)/Quest_6
TARGET7 = $(BUILDDIR)/Quest_7
TARGET8 = $(BUILDDIR)/Quest_8
SRC = s21_string.c s21_string_test.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean rebuild

all: strlen_tests

strlen_tests: CFLAGS += -DSTRLEN_TEST
strlen_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET1)

strcmp_tests: CFLAGS += -DSTRCMP_TEST
strcmp_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET2)

strcpy_tests: CFLAGS += -DSTRCPY_TEST
strcpy_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET3)

strcat_tests: CFLAGS += -DSTRCAT_TEST
strcat_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET4)

strchr_tests: CFLAGS += -DSTRCHR_TEST
strchr_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET5)

strstr_tests: CFLAGS += -DSTRSTR_TEST
strstr_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET6)

strtok_tests: CFLAGS += -DSTRTOK_TEST
strtok_tests: clean_o $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET7)

text_processor: text_processor.o s21_string.o
	$(CC) $(CFLAGS) $^ -o $(TARGET8)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) $(OBJ)

clean_o: 
	rm -rf $(OBJ)

rebuild: clean all
