# making a shared library makefile
# the needed flags are:
# -shared: to create a shared library
# -fPIC: to create position independent code (used for C++ shared libraries)
# -Wall: to enable all warnings
# -Werror: to treat warnings as errors
# -o: to specify the output file
# -l: to link against a library
# -L: to specify the library path

MODULE_NAME = mod2

TARGET_DIR = ../../libs
TARGET_NAME = lib$(MODULE_NAME)
TARGET = $(TARGET_DIR)/$(TARGET_NAME).so

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

CFLAGS = -fPIC -Wall -Werror
LDFLAGS =

$(TARGET): $(OBJ1)
	@echo "Linking $>"
	@g++ -shared $< -o $@ $(LDFLAGS)

$(OBJ1): $(MODULE_NAME).cpp
	@echo "Compiling $<"
	@g++ $(CFLAGS) -c $< -o $@
	@echo "done"


# the test module data
TEST_MODULE_NAME = test_mod2
TEST_MODULE_TARGET_DIR = ../../test_build
TEST_MODULE_TARGET = $(TEST_MODULE_TARGET_DIR)/$(TEST_MODULE_NAME)

OBJ2 = $(OBJ_DIR)/$(TEST_MODULE_NAME).o

$(TEST_MODULE_TARGET): $(OBJ2) $(TARGET)
	@echo "Linking $<"
	@g++ $< -o $@ -L$(TARGET_DIR) -l$(MODULE_NAME) -Wl,-rpath=$(TARGET_DIR)

$(OBJ2): $(TEST_MODULE_NAME).cpp
	@echo "Compiling $<"
	@g++ $(CFLAGS) -c $< -o $@
	@echo "done"

# to make all of test work, just create a test target, it should be phony, because the target isn't real
# if a target matches a real file, make will check if it is prebuild, it may skip running the commands, so phony ensures to rerun the commands



.PHONY: clean test

#add clean target to remove all generated files
clean: $(TARGET) $(OBJ1) $(OBJ2) $(TEST_MODULE_TARGET)
	@echo "removing files and directories"
	@rm -rf $^
	@echo "done"
test: $(TEST_MODULE_TARGET)
	@echo "running test"
	@./$<
	@echo "done"