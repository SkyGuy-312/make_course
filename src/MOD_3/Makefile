MODULE_NAME = mod3
DEP_NAME = mod2

TARGET_DIR = ../../bins
TARGET_NAME = mod3_bin
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

DEP_DIR = ../MOD_2
INSTALL = $(DEP_DIR)/$(DEP_NAME).h

OBJ_DIR = ../../objs
OBJ1 = $(OBJ_DIR)/$(MODULE_NAME).o

#to get mod2.h location
INC_DIR = ../../shared_headers
WARN_FLAGS = -Wall -Werror
CFLAGS = -fPIC $(WARN_FLAGS) -I$(INC_DIR)


LIB_DIR = ../../libs

LDFLAGS = -L$(LIB_DIR) -l$(DEP_NAME) -Wl,-rpath=$(LIB_DIR)

$(TARGET): $(OBJ1)
	@echo "Linking $<"
	@g++ $< -o $@ $(LDFLAGS)

$(OBJ1):$(MODULE_NAME).cpp
	@echo "Compiling $<"
	@g++ $(CFLAGS) -c $< -o $@
	@echo "done"

.PHONY: clean install
#add clean target to remove all generated files
clean: $(TARGET) $(OBJ1)
	@echo "removing files and directories"
	@rm -rf $^
	@echo "done"

install: $(INSTALL)
	@echo "installing $<"
	@cp $< $(INC_DIR)
	@echo "done"