# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Applications/Homework/lab_2/Tests Vector"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Applications/Homework/lab_2/Tests Vector/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tests_Vector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tests_Vector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tests_Vector.dir/flags.make

CMakeFiles/Tests_Vector.dir/main.cpp.o: CMakeFiles/Tests_Vector.dir/flags.make
CMakeFiles/Tests_Vector.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Applications/Homework/lab_2/Tests Vector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tests_Vector.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests_Vector.dir/main.cpp.o -c "/Applications/Homework/lab_2/Tests Vector/main.cpp"

CMakeFiles/Tests_Vector.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests_Vector.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Applications/Homework/lab_2/Tests Vector/main.cpp" > CMakeFiles/Tests_Vector.dir/main.cpp.i

CMakeFiles/Tests_Vector.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests_Vector.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Applications/Homework/lab_2/Tests Vector/main.cpp" -o CMakeFiles/Tests_Vector.dir/main.cpp.s

CMakeFiles/Tests_Vector.dir/tests.cpp.o: CMakeFiles/Tests_Vector.dir/flags.make
CMakeFiles/Tests_Vector.dir/tests.cpp.o: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Applications/Homework/lab_2/Tests Vector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tests_Vector.dir/tests.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests_Vector.dir/tests.cpp.o -c "/Applications/Homework/lab_2/Tests Vector/tests.cpp"

CMakeFiles/Tests_Vector.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests_Vector.dir/tests.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Applications/Homework/lab_2/Tests Vector/tests.cpp" > CMakeFiles/Tests_Vector.dir/tests.cpp.i

CMakeFiles/Tests_Vector.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests_Vector.dir/tests.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Applications/Homework/lab_2/Tests Vector/tests.cpp" -o CMakeFiles/Tests_Vector.dir/tests.cpp.s

CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o: CMakeFiles/Tests_Vector.dir/flags.make
CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o: ../ProcessVector_7.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Applications/Homework/lab_2/Tests Vector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o -c "/Applications/Homework/lab_2/Tests Vector/ProcessVector_7.cpp"

CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Applications/Homework/lab_2/Tests Vector/ProcessVector_7.cpp" > CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.i

CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Applications/Homework/lab_2/Tests Vector/ProcessVector_7.cpp" -o CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.s

# Object files for target Tests_Vector
Tests_Vector_OBJECTS = \
"CMakeFiles/Tests_Vector.dir/main.cpp.o" \
"CMakeFiles/Tests_Vector.dir/tests.cpp.o" \
"CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o"

# External object files for target Tests_Vector
Tests_Vector_EXTERNAL_OBJECTS =

Tests_Vector: CMakeFiles/Tests_Vector.dir/main.cpp.o
Tests_Vector: CMakeFiles/Tests_Vector.dir/tests.cpp.o
Tests_Vector: CMakeFiles/Tests_Vector.dir/ProcessVector_7.cpp.o
Tests_Vector: CMakeFiles/Tests_Vector.dir/build.make
Tests_Vector: CMakeFiles/Tests_Vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Applications/Homework/lab_2/Tests Vector/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Tests_Vector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests_Vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tests_Vector.dir/build: Tests_Vector

.PHONY : CMakeFiles/Tests_Vector.dir/build

CMakeFiles/Tests_Vector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tests_Vector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tests_Vector.dir/clean

CMakeFiles/Tests_Vector.dir/depend:
	cd "/Applications/Homework/lab_2/Tests Vector/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Applications/Homework/lab_2/Tests Vector" "/Applications/Homework/lab_2/Tests Vector" "/Applications/Homework/lab_2/Tests Vector/cmake-build-debug" "/Applications/Homework/lab_2/Tests Vector/cmake-build-debug" "/Applications/Homework/lab_2/Tests Vector/cmake-build-debug/CMakeFiles/Tests_Vector.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tests_Vector.dir/depend

