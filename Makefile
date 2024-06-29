# Compiler settings
CC = gcc
CFLAGS = -march=native -mtune=native -Ofast -flto=auto
LDFLAGS = -lncurses

# Source and header files
SRCS = $(wildcard src/*.c)
HEADERS = $(wildcard src/*.h)

# Compiling files
OBJS = $(patsubst src/%.c, src/%.o, $(SRCS))
TARGET = lifesim

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
