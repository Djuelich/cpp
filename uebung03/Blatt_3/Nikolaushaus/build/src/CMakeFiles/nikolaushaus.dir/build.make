# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build

# Include any dependencies generated for this target.
include src/CMakeFiles/nikolaushaus.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/nikolaushaus.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/nikolaushaus.dir/flags.make

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o: src/CMakeFiles/nikolaushaus.dir/flags.make
src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o: ../src/nikolaushaus.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o"
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o   -c /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/src/nikolaushaus.c

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/nikolaushaus.dir/nikolaushaus.c.i"
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/src/nikolaushaus.c > CMakeFiles/nikolaushaus.dir/nikolaushaus.c.i

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/nikolaushaus.dir/nikolaushaus.c.s"
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/src/nikolaushaus.c -o CMakeFiles/nikolaushaus.dir/nikolaushaus.c.s

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.requires:
.PHONY : src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.requires

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.provides: src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.requires
	$(MAKE) -f src/CMakeFiles/nikolaushaus.dir/build.make src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.provides.build
.PHONY : src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.provides

src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.provides.build: src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o

# Object files for target nikolaushaus
nikolaushaus_OBJECTS = \
"CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o"

# External object files for target nikolaushaus
nikolaushaus_EXTERNAL_OBJECTS =

src/nikolaushaus: src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o
src/nikolaushaus: src/CMakeFiles/nikolaushaus.dir/build.make
src/nikolaushaus: /usr/lib/i386-linux-gnu/libSDL2main.a
src/nikolaushaus: /usr/lib/i386-linux-gnu/libSDL2.so
src/nikolaushaus: src/CMakeFiles/nikolaushaus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable nikolaushaus"
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nikolaushaus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/nikolaushaus.dir/build: src/nikolaushaus
.PHONY : src/CMakeFiles/nikolaushaus.dir/build

src/CMakeFiles/nikolaushaus.dir/requires: src/CMakeFiles/nikolaushaus.dir/nikolaushaus.c.o.requires
.PHONY : src/CMakeFiles/nikolaushaus.dir/requires

src/CMakeFiles/nikolaushaus.dir/clean:
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src && $(CMAKE_COMMAND) -P CMakeFiles/nikolaushaus.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/nikolaushaus.dir/clean

src/CMakeFiles/nikolaushaus.dir/depend:
	cd /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/src /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src /home/joker/Schreibtisch/christian03-assignments/uebung03/Blatt_3/Nikolaushaus/build/src/CMakeFiles/nikolaushaus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/nikolaushaus.dir/depend
