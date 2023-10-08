# Makefile - Thomas Cholak
CC = g++
CFLAGS = -g -std=c++11
SOURCES = p0.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = P0

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
$(CC) $(CFLAGS) -o $@ $(OBJECTS)

%.o: %.cpp
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean
