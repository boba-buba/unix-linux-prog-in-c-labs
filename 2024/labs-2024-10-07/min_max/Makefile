# Root Makefile

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I$(LIBMIN_DIR) -I$(LIBMAX_DIR)
LDFLAGS = -L./build

# Directories
BUILD_DIR = build
LIBMIN_DIR = libmin
LIBMAX_DIR = libmax

# Output files
LIBmin = $(BUILD_DIR)/libmin.so
LIBmax = $(BUILD_DIR)/libmax.so
EXECUTABLE = $(BUILD_DIR)/main

# Source and object files
MAIN_SRC = main.c
MAIN_OBJ = $(BUILD_DIR)/main.o

# Rules
all: $(BUILD_DIR) libmin libmax $(EXECUTABLE)

# Build libmin by running its Makefile
libmin:
	cd $(LIBMIN_DIR) && $(MAKE)

# Build libmax by running its Makefile
libmax:
	cd $(LIBMAX_DIR) && $(MAKE)

# Build main executable, linking with dynamic libraries
$(EXECUTABLE): $(MAIN_OBJ) $(LIBmin) $(LIBmax)
	$(CC) -o $@ $(MAIN_OBJ) -L$(BUILD_DIR) -lmin -lmax -Wl,-rpath=.

# Compile main.c into main.o
$(MAIN_OBJ): $(MAIN_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build artifacts in all directories
clean:
	cd $(LIBMIN_DIR) && $(MAKE) clean
	cd $(LIBMAX_DIR) && $(MAKE) clean
	rm -f $(BUILD_DIR)/*
	rmdir $(BUILD_DIR)

.PHONY: all clean libmin libmax
