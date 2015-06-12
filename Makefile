PROJECT = lab4
TARGET = lab4

SRC_FILES = \
  Makefile \
  lab4.cpp

OBJ_FILES = \
  lab4.o \

CC = g++
CXXFLAGS=-O3 -std=c++0x -pg -D_DEBUG -g -c -Wall

$(TARGET):  	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@

clean:
		rm -f $(TARGET) *.o *~

lab4.o:		lab4.cpp

