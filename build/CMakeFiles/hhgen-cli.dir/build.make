# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jerry/Development/projects/hhgen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jerry/Development/projects/hhgen/build

# Include any dependencies generated for this target.
include CMakeFiles/hhgen-cli.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hhgen-cli.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hhgen-cli.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hhgen-cli.dir/flags.make

CMakeFiles/hhgen-cli.dir/src/main.c.o: CMakeFiles/hhgen-cli.dir/flags.make
CMakeFiles/hhgen-cli.dir/src/main.c.o: /home/jerry/Development/projects/hhgen/src/main.c
CMakeFiles/hhgen-cli.dir/src/main.c.o: CMakeFiles/hhgen-cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hhgen-cli.dir/src/main.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hhgen-cli.dir/src/main.c.o -MF CMakeFiles/hhgen-cli.dir/src/main.c.o.d -o CMakeFiles/hhgen-cli.dir/src/main.c.o -c /home/jerry/Development/projects/hhgen/src/main.c

CMakeFiles/hhgen-cli.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hhgen-cli.dir/src/main.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerry/Development/projects/hhgen/src/main.c > CMakeFiles/hhgen-cli.dir/src/main.c.i

CMakeFiles/hhgen-cli.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hhgen-cli.dir/src/main.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerry/Development/projects/hhgen/src/main.c -o CMakeFiles/hhgen-cli.dir/src/main.c.s

CMakeFiles/hhgen-cli.dir/src/hhgen.c.o: CMakeFiles/hhgen-cli.dir/flags.make
CMakeFiles/hhgen-cli.dir/src/hhgen.c.o: /home/jerry/Development/projects/hhgen/src/hhgen.c
CMakeFiles/hhgen-cli.dir/src/hhgen.c.o: CMakeFiles/hhgen-cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hhgen-cli.dir/src/hhgen.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hhgen-cli.dir/src/hhgen.c.o -MF CMakeFiles/hhgen-cli.dir/src/hhgen.c.o.d -o CMakeFiles/hhgen-cli.dir/src/hhgen.c.o -c /home/jerry/Development/projects/hhgen/src/hhgen.c

CMakeFiles/hhgen-cli.dir/src/hhgen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hhgen-cli.dir/src/hhgen.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerry/Development/projects/hhgen/src/hhgen.c > CMakeFiles/hhgen-cli.dir/src/hhgen.c.i

CMakeFiles/hhgen-cli.dir/src/hhgen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hhgen-cli.dir/src/hhgen.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerry/Development/projects/hhgen/src/hhgen.c -o CMakeFiles/hhgen-cli.dir/src/hhgen.c.s

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o: CMakeFiles/hhgen-cli.dir/flags.make
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o: /home/jerry/Development/projects/hhgen/src/lib/jlib/jlib.c
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o: CMakeFiles/hhgen-cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o -MF CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o.d -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o -c /home/jerry/Development/projects/hhgen/src/lib/jlib/jlib.c

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerry/Development/projects/hhgen/src/lib/jlib/jlib.c > CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.i

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerry/Development/projects/hhgen/src/lib/jlib/jlib.c -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.s

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o: CMakeFiles/hhgen-cli.dir/flags.make
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o: /home/jerry/Development/projects/hhgen/src/lib/jlib/jio.c
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o: CMakeFiles/hhgen-cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o -MF CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o.d -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o -c /home/jerry/Development/projects/hhgen/src/lib/jlib/jio.c

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerry/Development/projects/hhgen/src/lib/jlib/jio.c > CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.i

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerry/Development/projects/hhgen/src/lib/jlib/jio.c -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.s

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o: CMakeFiles/hhgen-cli.dir/flags.make
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o: /home/jerry/Development/projects/hhgen/src/lib/jlib/jdate.c
CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o: CMakeFiles/hhgen-cli.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o -MF CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o.d -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o -c /home/jerry/Development/projects/hhgen/src/lib/jlib/jdate.c

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jerry/Development/projects/hhgen/src/lib/jlib/jdate.c > CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.i

CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jerry/Development/projects/hhgen/src/lib/jlib/jdate.c -o CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.s

# Object files for target hhgen-cli
hhgen__cli_OBJECTS = \
"CMakeFiles/hhgen-cli.dir/src/main.c.o" \
"CMakeFiles/hhgen-cli.dir/src/hhgen.c.o" \
"CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o" \
"CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o" \
"CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o"

# External object files for target hhgen-cli
hhgen__cli_EXTERNAL_OBJECTS =

hhgen-cli: CMakeFiles/hhgen-cli.dir/src/main.c.o
hhgen-cli: CMakeFiles/hhgen-cli.dir/src/hhgen.c.o
hhgen-cli: CMakeFiles/hhgen-cli.dir/src/lib/jlib/jlib.c.o
hhgen-cli: CMakeFiles/hhgen-cli.dir/src/lib/jlib/jio.c.o
hhgen-cli: CMakeFiles/hhgen-cli.dir/src/lib/jlib/jdate.c.o
hhgen-cli: CMakeFiles/hhgen-cli.dir/build.make
hhgen-cli: CMakeFiles/hhgen-cli.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jerry/Development/projects/hhgen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable hhgen-cli"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hhgen-cli.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hhgen-cli.dir/build: hhgen-cli
.PHONY : CMakeFiles/hhgen-cli.dir/build

CMakeFiles/hhgen-cli.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hhgen-cli.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hhgen-cli.dir/clean

CMakeFiles/hhgen-cli.dir/depend:
	cd /home/jerry/Development/projects/hhgen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jerry/Development/projects/hhgen /home/jerry/Development/projects/hhgen /home/jerry/Development/projects/hhgen/build /home/jerry/Development/projects/hhgen/build /home/jerry/Development/projects/hhgen/build/CMakeFiles/hhgen-cli.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hhgen-cli.dir/depend
