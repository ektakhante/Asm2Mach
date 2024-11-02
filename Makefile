# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = build

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable
MAIN_EXEC = $(BUILD_DIR)/assembler

# Default target
all: $(MAIN_EXEC)

# Rule to compile the main program
$(MAIN_EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)  # Create object directory if it doesn't exist
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)/*.o $(MAIN_EXEC)

# Run the main program
run: $(MAIN_EXEC)
	@read -p "Enter assembly file: " file; ./$(MAIN_EXEC) $$file

.PHONY: all clean run
