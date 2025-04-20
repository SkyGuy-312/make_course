#There are 2 types of builds:
# 1. Debug build: This is the default build type. It includes debug symbols and is not optimized for performance.
# 2. Release build: This build type is optimized for performance and does not include debug symbols.
# The build type can be specified using the BUILD_TYPE variable. If not specified, it defaults to Debug.

# BUILD_TYPE = $(RELEASE)
BUILD_TYPE = $(DEBUG)

MODULE_NAME =
TARGET_NAME =

PROJEFCT_ROOT_PATH =
OBJ_DIR = $(PROJEFCT_ROOT_PATH)/objs/$(MODULE_NAME)		#separate folder for each module

# Build Timestamp
# BUILD_TIMESTAMP = $(shell date +%Y%m%d_%H%M%S) #or
BUILD_TIMESTAMP = $(shell date +'%d-%m-%Y %H:%M:%S.%N')

INSTALLATION_PATH = $(shell echo $$INSTALLATION_PATH)
# check if INSTALLATION_PATH is set
ifeq ($(INSTALLATION_PATH),)
	$(warning INSTALLATION_PATH is not set. Setting INSTALLATION_PATH to default project root path...)
	INSTALLATION_PATH = $(PROJEFCT_ROOT_PATH)
endif

# target directory
TARGET_DIR = $(INSTALLATION_PATH)/bins
TARGET = $(TARGET_DIR)/$(TARGET_NAME)

# include directory
LIBRARY_DIR = $(INSTALLATION_PATH)/libs

# C++ Compiler
CXX - $(shell echo $$CXX)
ifeq ($(CXX),)
	$(warning CXX is not set. Setting CXX to default g++) 
	CXX = g++
endif

# C++ Linker
LDXX = $(shell echo $$LDXX)
ifeq ($(LDXX),)
	$(warning LDXX is not set. Setting LDXX to default g++) 
	LDXX = g++
endif

# std flag
STDFLAG = -std=c++17

MAIN_OBJ = $(OBJ_DIR)/main.o

SOURCE1 = $(MODULE_NAME)
OBJ1 = $(OBJ_DIR)/$(SOURCE1).o
# SOURCE2 =
# OBJ2 = $(OBJ_DIR)/$(SOURCE2).o
# SOURCE3 =
# OBJ3 = $(OBJ_DIR)/$(SOURCE3).o

# May need to add more dependencies as per the project.\
	1. DON'T ADD EXTENSION C/CPP as it makes it easier to create the object files\
	2. Add *.o in ALL_OBJS\
	3. Add instruction to build target

ALL_OBJS = $(OBJ1) $(MAIN_OBJ)

# INC variable to shared headers
INC = -I./ -I$(PROJEFCT_ROOT_PATH)/shared_headers

# choose release/debug build
DEBUG = -pipe -g -Wall -W -fPIC
# RELEASE = -pipe -O3 -Wall -W -fPIC

#-D stands for define

DEFINES = -DBUILD_TIMESTAMP_STR=\"$(BUILD_TIMESTAMP)\"
			-DINSTALLATION_PATH_STR=\"$(INSTALLATION_PATH)"

# optimization flags
LD_OPT = -Wl, -O1

# warning flags
WARN = -Wall -Werror -Wextra -pedantic -Wwrite-strings -Wno-parantheses -Warray-bounds -Wno-unused-variable\
			-Wno-unused-function -Wno-unused-parameter -Wno-unused-result

# Compiler flags
CCFLAGS = $(STDFLAG) $(BUILD_TYPE) $(DEFINES) $(INC) $(WARN)

# Add dependency libraries here by separating them with spaces, example below adding libzmq, libm and libcustomlib
# Note: Add the "<path-to-library>  -llibraryname" by keeping space in between as shown below.\
if library is present in the current directrory, we can use path as "L."
#DEP_LIBS = -lzmq -lm -L$(LIBRARY_DIR) -lcustomlib -L. -lnewlibincurrentdir

# RPATH is used for linking libs in specific path
#RPATH = -Wl,-rpath=$(LIB_DIR)

#Linker flags
#LDFLAGS = $(DEP_LIBS) $(RPATH)

#build target
all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	@echo "Linking $<"
	@$(LDXX) $(LD_OPT) -o $@ $^ $(LDFLAGS)
	@echo "done"

$(MAIN_OBJ): main.cpp
	@echo "Compiling $<"
	@$(CXX) $(CCFLAGS) -c $< -o $@
	@echo "done"

$(OBJ1): $(SOURCE1).cpp
	@echo "Compiling $<"
	@$(CXX) $(CCFLAGS) -c $< -o $@
	@echo "done"

# $(OBJ2): $(SOURCE2).cpp
# 	@echo "Compiling $<"
# 	@$(CXX) $(CCFLAGS) -c $< -o $@
# 	@echo "done"

build_dir:
	@echo "Creating build directory..."
	@mkdir -p $(OBJ_DIR)
	@echo "done"

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET)
	@echo "done"

.PHONY: clean build_dir all
