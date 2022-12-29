CC := gcc
CXX := g++
CXXFLAGS := -g -std=c++11 -Wall -pedantic
LDFLAGS :=
SRC_DIR := src
INC_DIR := src
OUT_DIR := bin

SRC := 									\
	$(SRC_DIR)/main.cpp 				\
	$(SRC_DIR)/question_one.cpp			\
	$(SRC_DIR)/question_two.cpp			\

DEP := 									\
	$(SRC_DIR)/matrix.h					\
	$(SRC_DIR)/questions.h				\

OBJ := $(SRC:.cpp=.o)
OBJ := $(subst $(SRC_DIR)/,$(OUT_DIR)/,$(OBJ))

.PHONY: all
all: $(OUT_DIR)/matrix

bin/matrix: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) -I $(INC_DIR)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP)
	mkdir -p bin/part_one
	mkdir -p bin/part_two
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS) -I $(INC_DIR) -c

.PHONY: clean
clean:
	rm bin -rf
