# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build

# Utility rule file for NightlyBuild.

# Include any custom commands dependencies for this target.
include test/CMakeFiles/NightlyBuild.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/NightlyBuild.dir/progress.make

test/CMakeFiles/NightlyBuild:
	cd /d C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build\test && "C:\Program Files\CMake\bin\ctest.exe" -D NightlyBuild

NightlyBuild: test/CMakeFiles/NightlyBuild
NightlyBuild: test/CMakeFiles/NightlyBuild.dir/build.make
.PHONY : NightlyBuild

# Rule to build all files generated by this target.
test/CMakeFiles/NightlyBuild.dir/build: NightlyBuild
.PHONY : test/CMakeFiles/NightlyBuild.dir/build

test/CMakeFiles/NightlyBuild.dir/clean:
	cd /d C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build\test && $(CMAKE_COMMAND) -P CMakeFiles\NightlyBuild.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/NightlyBuild.dir/clean

test/CMakeFiles/NightlyBuild.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1 C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\test C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build\test C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\build\test\CMakeFiles\NightlyBuild.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/NightlyBuild.dir/depend

