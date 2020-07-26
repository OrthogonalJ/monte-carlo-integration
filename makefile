#### MACROS ####

CC=gcc
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
BUILD_DIR=build
TEST_DIR=test
EXE=$(BUILD_DIR)/mci.exe
STATIC_LIB=$(BUILD_DIR)/libmci.a
SHARED_LIB=$(BUILD_DIR)/libmci.so

DEPS=$(shell find $(SRC_DIR) -type f -name *.hpp -o -name *.h)
DEPS+=$(shell find $(INC_DIR) -type f -name *.hpp -o -name *.h)
OBJ=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(shell find $(SRC_DIR) -type f -name *.cpp))

#CXXTEST_DIR=/usr/include
TESTS=$(wildcard $(TEST_DIR)/*.h)
TEST_RUNNER=$(TEST_DIR)/.test_runner

CFLAGS= -std=c++14 -O3 -I$(INC_DIR) -fpic
#CFLAGS= -std=c++11 -ggdb -O0 -I$(INC_DIR)


#### RECIPIES ####

.PHONY: clean test all static-lib shared-lib

all: $(EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	mkdir -p $(dir $@)
	$(CC) -c -o $@ $(CFLAGS) $<

$(EXE): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $^ 
	
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

$(SHARED_LIB): $(OBJ)
	$(CC) -shared -o $@ $(CFLAGS) $^

static-lib: $(STATIC_LIB)

shared-lib: $(SHARED_LIB)

clean:
	rm -Rf $(OBJ_DIR)/* $(BUILD_DIR)/* $(TEST_RUNNER) $(TEST_RUNNER).cpp ./*.stackdump

test:
	@cxxtestgen --error-printer -o $(TEST_RUNNER).cpp $(TESTS)
	@$(CC) -o $(TEST_RUNNER) $(TEST_RUNNER).cpp $(CFLAGS)
	-@./$(TEST_RUNNER)
	@rm -f $(TEST_RUNNER) $(TEST_RUNNER).cpp
	
