BIN=main

SRC_DIR=src/
INC_DIR=inc/

CC=clang++
CFLAGS= -std=c++14 -Wall -I$(INC_DIR)

LIBS=-lpthread -lXrandr -lXi -ldl

SRCS=$(BIN).cpp $(wildcard $(SRC_DIR)*.c*)

default:
	$(CC) $(CFLAGS) $(LIBS) -o $(BIN) $(SRCS)

clean:
	rm -rf $(BIN)
