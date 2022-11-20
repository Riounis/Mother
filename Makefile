INCLUDE_DIR = include/
SRC_DIR = src/
BUILD_DIR = build/
OBJ_DIR = $(BUILD_DIR)obj/

CC = g++
INCLUDES = -I$(INCLUDE_DIR)

ifeq ($(BUILD_MODE),debug)
	CPPFLAGS += -D DEBUG_MODE
else ifeq ($(BUILD_MODE),test)
	CPPFLAGS += -D TEST_MODE
else
	BUILD_MODE=release
	CPPFLAGS += -O2
endif

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CPPFLAGS) $(INCLUDES)

$(BUILD_DIR)mother: $(OBJ_DIR)mother.o
	$(CC) -o $@ $^ $(CPPFLAGS) $(INCLUDES)
