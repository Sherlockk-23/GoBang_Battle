# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/qinzk23/GoBang_Battle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qinzk23/GoBang_Battle/build

# Include any dependencies generated for this target.
include CMakeFiles/GoBang_Battle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GoBang_Battle.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GoBang_Battle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoBang_Battle.dir/flags.make

CMakeFiles/GoBang_Battle.dir/src/board.cpp.o: CMakeFiles/GoBang_Battle.dir/flags.make
CMakeFiles/GoBang_Battle.dir/src/board.cpp.o: ../src/board.cpp
CMakeFiles/GoBang_Battle.dir/src/board.cpp.o: CMakeFiles/GoBang_Battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoBang_Battle.dir/src/board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GoBang_Battle.dir/src/board.cpp.o -MF CMakeFiles/GoBang_Battle.dir/src/board.cpp.o.d -o CMakeFiles/GoBang_Battle.dir/src/board.cpp.o -c /home/qinzk23/GoBang_Battle/src/board.cpp

CMakeFiles/GoBang_Battle.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang_Battle.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinzk23/GoBang_Battle/src/board.cpp > CMakeFiles/GoBang_Battle.dir/src/board.cpp.i

CMakeFiles/GoBang_Battle.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang_Battle.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinzk23/GoBang_Battle/src/board.cpp -o CMakeFiles/GoBang_Battle.dir/src/board.cpp.s

CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o: CMakeFiles/GoBang_Battle.dir/flags.make
CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o: ../src/strategy.cpp
CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o: CMakeFiles/GoBang_Battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o -MF CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o.d -o CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o -c /home/qinzk23/GoBang_Battle/src/strategy.cpp

CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinzk23/GoBang_Battle/src/strategy.cpp > CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.i

CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinzk23/GoBang_Battle/src/strategy.cpp -o CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.s

CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o: CMakeFiles/GoBang_Battle.dir/flags.make
CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o: ../src/robot1.cpp
CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o: CMakeFiles/GoBang_Battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o -MF CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o.d -o CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o -c /home/qinzk23/GoBang_Battle/src/robot1.cpp

CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinzk23/GoBang_Battle/src/robot1.cpp > CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.i

CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinzk23/GoBang_Battle/src/robot1.cpp -o CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.s

CMakeFiles/GoBang_Battle.dir/src/player.cpp.o: CMakeFiles/GoBang_Battle.dir/flags.make
CMakeFiles/GoBang_Battle.dir/src/player.cpp.o: ../src/player.cpp
CMakeFiles/GoBang_Battle.dir/src/player.cpp.o: CMakeFiles/GoBang_Battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GoBang_Battle.dir/src/player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GoBang_Battle.dir/src/player.cpp.o -MF CMakeFiles/GoBang_Battle.dir/src/player.cpp.o.d -o CMakeFiles/GoBang_Battle.dir/src/player.cpp.o -c /home/qinzk23/GoBang_Battle/src/player.cpp

CMakeFiles/GoBang_Battle.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang_Battle.dir/src/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinzk23/GoBang_Battle/src/player.cpp > CMakeFiles/GoBang_Battle.dir/src/player.cpp.i

CMakeFiles/GoBang_Battle.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang_Battle.dir/src/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinzk23/GoBang_Battle/src/player.cpp -o CMakeFiles/GoBang_Battle.dir/src/player.cpp.s

CMakeFiles/GoBang_Battle.dir/src/game.cpp.o: CMakeFiles/GoBang_Battle.dir/flags.make
CMakeFiles/GoBang_Battle.dir/src/game.cpp.o: ../src/game.cpp
CMakeFiles/GoBang_Battle.dir/src/game.cpp.o: CMakeFiles/GoBang_Battle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/GoBang_Battle.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GoBang_Battle.dir/src/game.cpp.o -MF CMakeFiles/GoBang_Battle.dir/src/game.cpp.o.d -o CMakeFiles/GoBang_Battle.dir/src/game.cpp.o -c /home/qinzk23/GoBang_Battle/src/game.cpp

CMakeFiles/GoBang_Battle.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoBang_Battle.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/qinzk23/GoBang_Battle/src/game.cpp > CMakeFiles/GoBang_Battle.dir/src/game.cpp.i

CMakeFiles/GoBang_Battle.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoBang_Battle.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/qinzk23/GoBang_Battle/src/game.cpp -o CMakeFiles/GoBang_Battle.dir/src/game.cpp.s

# Object files for target GoBang_Battle
GoBang_Battle_OBJECTS = \
"CMakeFiles/GoBang_Battle.dir/src/board.cpp.o" \
"CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o" \
"CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o" \
"CMakeFiles/GoBang_Battle.dir/src/player.cpp.o" \
"CMakeFiles/GoBang_Battle.dir/src/game.cpp.o"

# External object files for target GoBang_Battle
GoBang_Battle_EXTERNAL_OBJECTS =

libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/src/board.cpp.o
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/src/strategy.cpp.o
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/src/robot1.cpp.o
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/src/player.cpp.o
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/src/game.cpp.o
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/build.make
libGoBang_Battle.so: CMakeFiles/GoBang_Battle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qinzk23/GoBang_Battle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libGoBang_Battle.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GoBang_Battle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoBang_Battle.dir/build: libGoBang_Battle.so
.PHONY : CMakeFiles/GoBang_Battle.dir/build

CMakeFiles/GoBang_Battle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GoBang_Battle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GoBang_Battle.dir/clean

CMakeFiles/GoBang_Battle.dir/depend:
	cd /home/qinzk23/GoBang_Battle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qinzk23/GoBang_Battle /home/qinzk23/GoBang_Battle /home/qinzk23/GoBang_Battle/build /home/qinzk23/GoBang_Battle/build /home/qinzk23/GoBang_Battle/build/CMakeFiles/GoBang_Battle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GoBang_Battle.dir/depend

