# Makefile Documentation
# -----------------------
# A Makefile is a build automation tool used to compile and manage dependencies in software projects.
# It defines a set of rules to generate target files from source files.
#
# Basic Structure:
# ----------------
# 1. Targets: The file or action to be created or executed.
# 2. Dependencies: Files or prerequisites required to build the target.
# 3. Commands: Shell commands executed to build the target.
#
# Syntax:
# -------
# target: dependencies
# <TAB> command
#
# Common Targets:
# ---------------
# - `all`: Default target to build the entire project.
# - `clean`: Removes generated files (e.g., object files, binaries).
# - `install`: Installs the built software.
# - `test`: Runs tests for the project.
#
# Variables:
# ----------
# Variables can be defined and used to simplify the Makefile.
# Example:
# CC = gcc
# CFLAGS = -Wall -g
#
# Pattern Rules:
# --------------
# Used for defining generic build rules.
# Example:
# %.o: %.c
# <TAB> $(CC) $(CFLAGS) -c $< -o $@
#
# Phony Targets:
# --------------
# Targets that do not represent actual files.
# Declared using `.PHONY` to avoid conflicts with file names.
# Example:
# .PHONY: clean
#
# Example Usage:
# --------------
# Run `make` to execute the default target.
# Run `make <target>` to execute a specific target.

#example
# Target: dependencies
# 	@echo "use dependencies to build target, dependencies can be other targets, like this:"

# dependencies: Target3
# 	@echo "use Target3 to build Target2, Target3 can be another target, like this:"

# Target3:	
# #some command(but tabs before that)
# 	@echo "gcc dummy use"
# 	-gcc	
# # "-" means ignore errors, so the command will be executed even if there is an error

# #all target
# all: make_dir create_file
# 	@echo "all done"

# #creating 3 directories d1, d2, d3:
# make_dir:
# 	@echo "creating directories"
# 	mkdir -p d1 d2 d3
# 	@echo "done"

# #removing directories d1, d2, d3:
# remove_dir:
# 	@echo "removing directories"
# 	rm -rf d1 d2 d3
# 	@echo "done"

# #creating 3 files f1, f2, f3 in d1, d2, d3:
# create_file:
# 	@echo "creating files"
# 	touch d1/f1 d2/f2 d3/f3
# 	@echo "done"

# #removing files f1, f2, f3 in d1, d2, d3:
# remove_file:
# 	@echo "removing files"
# 	rm -f d1/f1 d2/f2 d3/f3
# 	@echo "done"

# #phony target example (unreal target)
# # will remove files and folders, make commands silent (doesn't show the command)
# clean:
# 	@echo "removing files and directories"
# 	rm -rf d1 d2 d3
# 	@echo "done"
	
# .PHONY: clean #some other phony target, .PHONY can take multiple targets

#default target
# default:
# 	g++ main.cpp -o ../../bins/MOD_1
# 	@echo "default target done"

#since ../../bins/MOD_1 is the target, we can have it as the target
# ../../bins/MOD_1: main.cpp
# 	g++ main.cpp -o ../../bins/MOD_1
# 	@echo "default target done"

#this isn't the best case, sense if we changed target name, we'd change it in 2 locations, so it is better to use a variable:
# OUTPUT = ../../bins/MOD_1
# $(OUTPUT): main.cpp
# 	g++ main.cpp -o $(OUTPUT)
# 	@echo "default target done"

#same goes for main.cpp, we can use a variable for it too
# OUTPUT = ../../bins/MOD_1
# INPUT = main.cpp
# $(OUTPUT): $(INPUT)
# 	g++ $(INPUT) -o $(OUTPUT)
# 	@echo "default target done"

#we can also use some operators that refer to dependencies, 
#like $^, which refers to all dependencies and $< which refers to the first dependency, 
#and $@ which refers to the target
# OUTPUT = ../../bins/MOD_1
# INPUT = main.cpp
# $(OUTPUT): $(INPUT)
# 	g++ $< -o $@

#usually, GCC chaing goes like this:
# 1. Preprocessing: The preprocessor handles directives (e.g., #include, #define) and generates an intermediate file.
# 2. Compilation: The compiler translates the preprocessed code into assembly language.
# 3. Assembly: The assembler converts the assembly code into machine code (object file).
# 4. Linking: The linker combines object files and libraries to create the final executable.
# 5. Optimization: The compiler may apply optimizations to improve performance.

# each of these steps can be done separately, for each step there is a command:
# 1. Preprocessing: `gcc -E main.cpp -o main.i`
# 2. Compilation: `gcc -S main.i -o main.s`
# 3. Assembly: `gcc -c main.s -o main.o`
# 4. Linking: `gcc main.o -o main`
# 5. Optimization: `gcc -O2 main.cpp -o main`

#for now, we will separate a new step between Input and Output, which is the object file, so we will have:
OUTPUT = ../../bins/MOD_1
INPUT = main.cpp
OBJ1 = ../../objs/MOD_1.o

$(OUTPUT): $(OBJ1)
	g++ $< -o $@

$(OBJ1): $(INPUT)
	gcc -c $< -o $@

