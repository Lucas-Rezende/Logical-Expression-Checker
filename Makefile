BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

EXEC = $(BIN_DIR)/tp1.out
LINK = tp1.out

CC = g++
CFLAGS = -Wall -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

all: $(EXEC) $(LINK)

$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

$(LINK):
	ln -sf $(EXEC) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC) $(OBJECTS) $(LINK)

testp1:
	./$(LINK) -a "0 | 1" 01
	./$(LINK) -a "0 | 1 & 2" 010
	./$(LINK) -a "~ (0 | 1) & 2" 101
	./$(LINK) -a "0 | 1 | (2 | 3 | (4 | 5) | 6)" 0000000
	./$(LINK) -a "~ (0 | 1 | (2 | 3 | (4 | 5) | 6))" 0000000
	./$(LINK) -a "0 | 1 | (2 | 3 | (4 | 5) | 6)" 1111111
	./$(LINK) -a "~ (0 | 1 | (2 | 3 | (4 | 5) | 6))" 1111111
	./$(LINK) -a "2 & 1 | 0 & 2" 010
testp2:
	./$(LINK) -s "0 | 1 & 2" 0e0
	./$(LINK) -s "0 | 1 & 2" e00
	./$(LINK) -s "0 | 1 & 2" e11
	./$(LINK) -s "(0 | 1)" ea
	./$(LINK) -a "~ ~ 0 | 1" 10
	./$(LINK) -s "0 | ~ ~ 1" ea
	./$(LINK) -a "~ ~ ~ 0 | 1" 10
	./$(LINK) -s "(0 & 1) | (2 & 3 & 4)" e0a11
	./$(LINK) -s "0 | 1 | 2" aae
	./$(LINK) -s "0 | 1 | 2" eaa