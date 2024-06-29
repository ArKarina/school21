CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
BUILDDIR = ../../build
TARGET = $(BUILDDIR)/Quest_3
TARGET4 = $(BUILDDIR)/Quest_4
TARGET5 = $(BUILDDIR)/Quest_5
TARGET6 = $(BUILDDIR)/Quest_6
SRC = main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJ = $(SRC:.c=.o)
STATIC_LIB = ../data_libs/libdata_stat.a
DINAMIC_LIB = ../data_module/libdata_process.so

.PHONY: all clean rebuild build_with_macro build_with_static build_with_dynamic

all: clean_o $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

$(TARGET4): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET4)

$(TARGET5): $(OBJ) $(STATIC_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET5) $(STATIC_LIB)
	
$(TARGET6): $(OBJ) $(STATIC_LIB) $(DINAMIC_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET6) -L../data_module -ldata_process $(STATIC_LIB) -Wl,-rpath,../data_module

$(STATIC_LIB): ../data_libs/data_stat.o
	ar rcs $@ $^

../data_libs/data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DINAMIC_LIB): ../data_module/data_process.o ../data_libs/data_stat.o
	$(CC) -shared -o $@ $^
 
../data_module/data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

../data_libs/data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(TARGET4) $(TARGET5) $(TARGET6) $(OBJ) $(STATIC_LIB) $(DINAMIC_LIB)

clean_o:
	rm -rf $(OBJ)

rebuild: clean all

build_with_macro: CFLAGS += -DMACRO_IO
build_with_macro: clean_o $(TARGET4)

build_with_static: clean_o $(TARGET5)

build_with_dynamic: clean_o $(TARGET6)
