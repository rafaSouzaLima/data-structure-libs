CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
AR = ar
ARFLAGS = rcs

SRC_DIR = src
BIN_DIR = bin

LIB = $(BIN_DIR)/liblist.a
LIB_OBJ = $(BIN_DIR)/list.o

TEST = $(BIN_DIR)/test
TEST_SRC = $(SRC_DIR)/test.c

LIST_SRC = $(SRC_DIR)/list.c
LIST_HDR = $(SRC_DIR)/list.h

.PHONY: all clean dirs

all: dirs $(LIB) $(TEST)

dirs:
	mkdir -p $(BIN_DIR)

$(LIB_OBJ): $(LIST_SRC) $(LIST_HDR) | dirs
	$(CC) $(CFLAGS) -c $(LIST_SRC) -o $(LIB_OBJ)

$(LIB): $(LIB_OBJ) | dirs
	$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJ)

$(TEST): $(TEST_SRC) $(LIB) | dirs
	$(CC) $(CFLAGS) $(TEST_SRC) -L$(BIN_DIR) -llist -o $(TEST)

clean:
	rm -rf $(BIN_DIR)