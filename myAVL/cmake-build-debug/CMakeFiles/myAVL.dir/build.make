# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Mycodes\ds\myAVL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Mycodes\ds\myAVL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/myAVL.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/myAVL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myAVL.dir/flags.make

CMakeFiles/myAVL.dir/main.cpp.obj: CMakeFiles/myAVL.dir/flags.make
CMakeFiles/myAVL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Mycodes\ds\myAVL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myAVL.dir/main.cpp.obj"
	D:\dev\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\myAVL.dir\main.cpp.obj -c D:\Mycodes\ds\myAVL\main.cpp

CMakeFiles/myAVL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myAVL.dir/main.cpp.i"
	D:\dev\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Mycodes\ds\myAVL\main.cpp > CMakeFiles\myAVL.dir\main.cpp.i

CMakeFiles/myAVL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myAVL.dir/main.cpp.s"
	D:\dev\Dev-Cpp\MinGW64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Mycodes\ds\myAVL\main.cpp -o CMakeFiles\myAVL.dir\main.cpp.s

# Object files for target myAVL
myAVL_OBJECTS = \
"CMakeFiles/myAVL.dir/main.cpp.obj"

# External object files for target myAVL
myAVL_EXTERNAL_OBJECTS =

myAVL.exe: CMakeFiles/myAVL.dir/main.cpp.obj
myAVL.exe: CMakeFiles/myAVL.dir/build.make
myAVL.exe: CMakeFiles/myAVL.dir/linklibs.rsp
myAVL.exe: CMakeFiles/myAVL.dir/objects1.rsp
myAVL.exe: CMakeFiles/myAVL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Mycodes\ds\myAVL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myAVL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\myAVL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myAVL.dir/build: myAVL.exe
.PHONY : CMakeFiles/myAVL.dir/build

CMakeFiles/myAVL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\myAVL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/myAVL.dir/clean

CMakeFiles/myAVL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Mycodes\ds\myAVL D:\Mycodes\ds\myAVL D:\Mycodes\ds\myAVL\cmake-build-debug D:\Mycodes\ds\myAVL\cmake-build-debug D:\Mycodes\ds\myAVL\cmake-build-debug\CMakeFiles\myAVL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myAVL.dir/depend

