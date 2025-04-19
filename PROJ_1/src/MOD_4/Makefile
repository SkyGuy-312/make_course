MODULE_NAME = mod4

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME).a	#precompiled static library
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

INC_DIR = ../../shared_headers

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -fPIC -Wall -Werror
LDFLAGS = -L$(TARGET_DIR) -l$(MODULE_NAME) -Wl,-rpath=$(TARGET_DIR)

$(TARGET): $(OBJ1)
	@echo "Linking $<"
	@ar rcs $@ $<

$(OBJ1): $(MODULE_NAME).cpp
	@echo "Compiling $<"
	@g++ $(CFLAGS) -c $< -o $@
	@echo "done"

TEST_MODULE_NAME = test_mod4

TEST_TARGET_DIR = ../../test_build
TEST_TARGET_NAME = $(TEST_MODULE_NAME)
TEST_TARGET = $(TEST_TARGET_DIR)/$(TEST_TARGET_NAME)

OBJ2 = $(OBJ_DIR)/$(TEST_MODULE_NAME).o

$(TEST_TARGET): $(OBJ2) $(TARGET)
	@echo "Linking $<"
	@g++ $< -o $@ $(LDFLAGS)

$(OBJ2): $(TEST_MODULE_NAME).cpp
	@echo "Compiling $<"
	@g++ $(CFLAGS) -c $< -o $@
	@echo "done"

install:
	@echo "installing $<"
	@cp $(MODULE_NAME).h $(INC_DIR)
	@echo "done"

.PHONY: clean test
#add clean target to remove all generated files
clean: $(TARGET) $(OBJ1) $(OBJ2) $(TEST_TARGET)
	@echo "removing files and directories"
	@rm -rf $^
	@echo "done"

test: $(TEST_TARGET)
	@echo "running test"
	@./$<
	@echo "done"