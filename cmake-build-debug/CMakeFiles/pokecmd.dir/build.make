# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.6183.77/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pokecmd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pokecmd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pokecmd.dir/flags.make

CMakeFiles/pokecmd.dir/main.cpp.o: CMakeFiles/pokecmd.dir/flags.make
CMakeFiles/pokecmd.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pokecmd.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pokecmd.dir/main.cpp.o -c /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/main.cpp

CMakeFiles/pokecmd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokecmd.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/main.cpp > CMakeFiles/pokecmd.dir/main.cpp.i

CMakeFiles/pokecmd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokecmd.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/main.cpp -o CMakeFiles/pokecmd.dir/main.cpp.s

CMakeFiles/pokecmd.dir/pokemon.cpp.o: CMakeFiles/pokecmd.dir/flags.make
CMakeFiles/pokecmd.dir/pokemon.cpp.o: ../pokemon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pokecmd.dir/pokemon.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pokecmd.dir/pokemon.cpp.o -c /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/pokemon.cpp

CMakeFiles/pokecmd.dir/pokemon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokecmd.dir/pokemon.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/pokemon.cpp > CMakeFiles/pokecmd.dir/pokemon.cpp.i

CMakeFiles/pokecmd.dir/pokemon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokecmd.dir/pokemon.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/pokemon.cpp -o CMakeFiles/pokecmd.dir/pokemon.cpp.s

CMakeFiles/pokecmd.dir/entry.cpp.o: CMakeFiles/pokecmd.dir/flags.make
CMakeFiles/pokecmd.dir/entry.cpp.o: ../entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pokecmd.dir/entry.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pokecmd.dir/entry.cpp.o -c /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/entry.cpp

CMakeFiles/pokecmd.dir/entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokecmd.dir/entry.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/entry.cpp > CMakeFiles/pokecmd.dir/entry.cpp.i

CMakeFiles/pokecmd.dir/entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokecmd.dir/entry.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/entry.cpp -o CMakeFiles/pokecmd.dir/entry.cpp.s

CMakeFiles/pokecmd.dir/human.cpp.o: CMakeFiles/pokecmd.dir/flags.make
CMakeFiles/pokecmd.dir/human.cpp.o: ../human.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pokecmd.dir/human.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pokecmd.dir/human.cpp.o -c /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/human.cpp

CMakeFiles/pokecmd.dir/human.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokecmd.dir/human.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/human.cpp > CMakeFiles/pokecmd.dir/human.cpp.i

CMakeFiles/pokecmd.dir/human.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokecmd.dir/human.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/human.cpp -o CMakeFiles/pokecmd.dir/human.cpp.s

# Object files for target pokecmd
pokecmd_OBJECTS = \
"CMakeFiles/pokecmd.dir/main.cpp.o" \
"CMakeFiles/pokecmd.dir/pokemon.cpp.o" \
"CMakeFiles/pokecmd.dir/entry.cpp.o" \
"CMakeFiles/pokecmd.dir/human.cpp.o"

# External object files for target pokecmd
pokecmd_EXTERNAL_OBJECTS =

pokecmd: CMakeFiles/pokecmd.dir/main.cpp.o
pokecmd: CMakeFiles/pokecmd.dir/pokemon.cpp.o
pokecmd: CMakeFiles/pokecmd.dir/entry.cpp.o
pokecmd: CMakeFiles/pokecmd.dir/human.cpp.o
pokecmd: CMakeFiles/pokecmd.dir/build.make
pokecmd: CMakeFiles/pokecmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable pokecmd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pokecmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pokecmd.dir/build: pokecmd

.PHONY : CMakeFiles/pokecmd.dir/build

CMakeFiles/pokecmd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pokecmd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pokecmd.dir/clean

CMakeFiles/pokecmd.dir/depend:
	cd /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug /home/alex/classwork/S2019/EEEE-346/pokecmd/pokecmd/cmake-build-debug/CMakeFiles/pokecmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pokecmd.dir/depend

