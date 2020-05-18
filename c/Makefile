BIN=main

SRC_DIR=src/
INC_DIR=inc/

CC=gcc
CFLAGS=-Wall -I$(INC_DIR) -ansi -DLINUX -D_GNU_SOURCE

LIBS=-lpthread -lXrandr -lXi -ldl

SRCS=$(BIN).c $(wildcard $(SRC_DIR)*.c*)

default:
	$(CC) $(CFLAGS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN)
