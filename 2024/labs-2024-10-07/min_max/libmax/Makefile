# libmax/Makefile

# Compiler and flags
CC = gcc
CFLAGS = -fPIC -Wall -g
LDFLAGS = -shared

# Output directory
BUILD_DIR = ../build

# Output file
libmax = $(BUILD_DIR)/libmax.so

# Source and object files
SRC = libmax.c
OBJ = $(BUILD_DIR)/libmax.o

# Header files
HDR = libmax.h

# Rules
all: $(libmax)

# Build shared library
$(libmax): $(OBJ) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

# Compile source file into object file
$(OBJ): $(SRC) $(HDR) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(libmax)

.PHONY: all clean
