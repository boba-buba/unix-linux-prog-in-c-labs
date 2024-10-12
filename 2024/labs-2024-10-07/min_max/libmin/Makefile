# libmin/Makefile

# Compiler and flags
CC = gcc
CFLAGS = -fPIC -Wall -g
LDFLAGS = -shared

# Output directory
BUILD_DIR = ../build

# Output file
libmin = $(BUILD_DIR)/libmin.so

# Source and object files
SRC = libmin.c
OBJ = $(BUILD_DIR)/libmin.o

# Header files
HDR = libmin.h

# Rules
all: $(libmin)

# Build shared library
$(libmin): $(OBJ) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

# Compile source file into object file
$(OBJ): $(SRC) $(HDR) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC) -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(libmin)

.PHONY: all clean
