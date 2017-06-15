# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/silvy_n/projects/IndieStudio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/silvy_n/projects/IndieStudio

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/silvy_n/projects/IndieStudio/CMakeFiles /home/silvy_n/projects/IndieStudio/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/silvy_n/projects/IndieStudio/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named bomber

# Build rule for target.
bomber: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bomber
.PHONY : bomber

# fast build rule for target.
bomber/fast:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/build
.PHONY : bomber/fast

src/ecs/ContextManager.o: src/ecs/ContextManager.cpp.o

.PHONY : src/ecs/ContextManager.o

# target to build an object file
src/ecs/ContextManager.cpp.o:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/ecs/ContextManager.cpp.o
.PHONY : src/ecs/ContextManager.cpp.o

src/ecs/ContextManager.i: src/ecs/ContextManager.cpp.i

.PHONY : src/ecs/ContextManager.i

# target to preprocess a source file
src/ecs/ContextManager.cpp.i:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/ecs/ContextManager.cpp.i
.PHONY : src/ecs/ContextManager.cpp.i

src/ecs/ContextManager.s: src/ecs/ContextManager.cpp.s

.PHONY : src/ecs/ContextManager.s

# target to generate assembly for a file
src/ecs/ContextManager.cpp.s:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/ecs/ContextManager.cpp.s
.PHONY : src/ecs/ContextManager.cpp.s

src/indie/InputReceiver.o: src/indie/InputReceiver.cpp.o

.PHONY : src/indie/InputReceiver.o

# target to build an object file
src/indie/InputReceiver.cpp.o:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/InputReceiver.cpp.o
.PHONY : src/indie/InputReceiver.cpp.o

src/indie/InputReceiver.i: src/indie/InputReceiver.cpp.i

.PHONY : src/indie/InputReceiver.i

# target to preprocess a source file
src/indie/InputReceiver.cpp.i:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/InputReceiver.cpp.i
.PHONY : src/indie/InputReceiver.cpp.i

src/indie/InputReceiver.s: src/indie/InputReceiver.cpp.s

.PHONY : src/indie/InputReceiver.s

# target to generate assembly for a file
src/indie/InputReceiver.cpp.s:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/InputReceiver.cpp.s
.PHONY : src/indie/InputReceiver.cpp.s

src/indie/contexts/registerAllContexts.o: src/indie/contexts/registerAllContexts.cpp.o

.PHONY : src/indie/contexts/registerAllContexts.o

# target to build an object file
src/indie/contexts/registerAllContexts.cpp.o:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/contexts/registerAllContexts.cpp.o
.PHONY : src/indie/contexts/registerAllContexts.cpp.o

src/indie/contexts/registerAllContexts.i: src/indie/contexts/registerAllContexts.cpp.i

.PHONY : src/indie/contexts/registerAllContexts.i

# target to preprocess a source file
src/indie/contexts/registerAllContexts.cpp.i:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/contexts/registerAllContexts.cpp.i
.PHONY : src/indie/contexts/registerAllContexts.cpp.i

src/indie/contexts/registerAllContexts.s: src/indie/contexts/registerAllContexts.cpp.s

.PHONY : src/indie/contexts/registerAllContexts.s

# target to generate assembly for a file
src/indie/contexts/registerAllContexts.cpp.s:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/contexts/registerAllContexts.cpp.s
.PHONY : src/indie/contexts/registerAllContexts.cpp.s

src/indie/engine.o: src/indie/engine.cpp.o

.PHONY : src/indie/engine.o

# target to build an object file
src/indie/engine.cpp.o:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/engine.cpp.o
.PHONY : src/indie/engine.cpp.o

src/indie/engine.i: src/indie/engine.cpp.i

.PHONY : src/indie/engine.i

# target to preprocess a source file
src/indie/engine.cpp.i:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/engine.cpp.i
.PHONY : src/indie/engine.cpp.i

src/indie/engine.s: src/indie/engine.cpp.s

.PHONY : src/indie/engine.s

# target to generate assembly for a file
src/indie/engine.cpp.s:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/indie/engine.cpp.s
.PHONY : src/indie/engine.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/bomber.dir/build.make CMakeFiles/bomber.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... bomber"
	@echo "... edit_cache"
	@echo "... src/ecs/ContextManager.o"
	@echo "... src/ecs/ContextManager.i"
	@echo "... src/ecs/ContextManager.s"
	@echo "... src/indie/InputReceiver.o"
	@echo "... src/indie/InputReceiver.i"
	@echo "... src/indie/InputReceiver.s"
	@echo "... src/indie/contexts/registerAllContexts.o"
	@echo "... src/indie/contexts/registerAllContexts.i"
	@echo "... src/indie/contexts/registerAllContexts.s"
	@echo "... src/indie/engine.o"
	@echo "... src/indie/engine.i"
	@echo "... src/indie/engine.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

