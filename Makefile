CC = gcc
CXXC = g++
CFLAGS = -g -Wall -Wextra	# For Debugging
#CFLAGS = -O3 				 # For Build
SRC_DIR = src/
OBJ_DIR = bin/obj/
EXEC_DIR = bin/
NAME = bal
TARGET = out
LIBS = -lm

ARGS = test/test_files/basic.bl

#### DO NOT EDIT BELOW THIS LINE ####

EXEC = $(NAME).$(TARGET)
BUILD = $(EXEC_DIR)$(EXEC)
SRCS := $(wildcard src/**/**.c) $(wildcard src/*.c)
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(OBJS)
	@echo [INFO] Creating Binary Executable [$(TARGET)] ...
	@$(CC) -o $(BUILD) $^ $(LIBS)
	@echo [INFO] [$(EXEC)] Created!

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo [CC] $<
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $< -c -o $@

run: all
	@echo [INFO] Running ...
	@$(EXEC_DIR)./$(EXEC)
	@echo [EXEC] Done!

mem_check: all
	@echo [INFO] Debugging ...
	@valgrind --tool=memcheck --leak-check=full --track-origins=yes $(EXEC_DIR)./$(EXEC) $(ARGS)
	@echo [DEBUG] Done!

.PHONY: clean
clean:
	@echo [INFO] Removing Pre-compiled Object Files
	@rm -rf $(OBJ_DIR)*.o
	@rm -rf $(OBJ_DIR)**/**.o
	@echo [INFO] Removing Compiled Executables
	@rm -rf $(EXEC_DIR)*.$(TARGET)
