# Compiler and Flags
CC = gcc
CFLAGS = -Wall -g -Iinclude
LDFLAGS =

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Source Files
SRC = $(SRC_DIR)/main.c
OBJ = $(OBJ_DIR)/main.o

# Executable
EXEC = $(BIN_DIR)/asm2mach

# Targets
all: $(EXEC)

# Rule to link the object files into the executable
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)  # Ensure bin directory exists
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Rule to compile the source file to an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Ensure obj directory exists
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)

run: $(MAIN_EXEC)
	./$(EXEC)

# Phony targets
.PHONY: all clean
