# Compiler and flags
CC = gcc
CFLAGS = -fPIC -Wall -g -I$(LIBA_DIR) -I$(LIBB_DIR)
LDFLAGS = -shared

# Directories
LIBA_DIR = liba
LIBB_DIR = libb

# Output files
LIBA = liba.so
LIBB = libb.so
EXECUTABLE = main

# Source files
LIBA_SRC = $(LIBA_DIR)/*.c
LIBB_SRC = $(LIBB_DIR)/*.c
MAIN_SRC = main.c

# Header files
LIBA_HDR = $(LIBA_DIR)/liba.h
LIBB_HDR = $(LIBB_DIR)/libb.h

# Object files
LIBA_OBJ = $(LIBA_SRC:.c=.o)
LIBB_OBJ = $(LIBB_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Rules
all: $(EXECUTABLE)

# Build main executable, linking with dynamic libraries
# -Wl,-rpath=. for the binary to know where to find .so dynamic libraries
$(EXECUTABLE): $(LIBB) $(LIBA) $(MAIN_OBJ)
	$(CC) -o $@ $(MAIN_OBJ) -L. -la -lb -Wl,-rpath=.

# Build shared library liba
$(LIBA): $(LIBA_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(LIBA_OBJ)

# Build shared library libb
$(LIBB): $(LIBB_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(LIBB_OBJ)

# Compile main.c into main.o
$(MAIN_OBJ): $(MAIN_SRC) $(LIBA_HDR) $(LIBB_HDR)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $@

# Compile liba.c into liba.o
$(LIBA_OBJ): $(LIBB_HDR) $(LIBA_SRC) $(LIBA_HDR)
	$(CC) $(CFLAGS) -c $(LIBA_SRC) -o $@

# Compile libb.c into libb.o
$(LIBB_OBJ): $(LIBB_SRC) $(LIBB_HDR)
	$(CC) $(CFLAGS) -c $(LIBB_SRC) -o $@

# Clean up build artifacts
clean:
	rm -f $(LIBA_OBJ) $(LIBB_OBJ) $(MAIN_OBJ) $(LIBA) $(LIBB) $(EXECUTABLE)


.PHONY: all clean
