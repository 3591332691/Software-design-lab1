# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_BINARY_DIR = C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	"C:\Program Files\CMake\bin\ctest.exe" --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files\CMake\bin\cmake-gui.exe" -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\CMake\bin\cmake.exe" --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"gmock\" \"gtest\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	"C:\Program Files\CMake\bin\cmake.exe" -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	"C:\Program Files\CMake\bin\cmake.exe" -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	"C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\CMakeFiles C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\\CMakeFiles\progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\HUAWEI\Desktop\program\softwareDesign\lab1\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lab2

# Build rule for target.
lab2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 lab2
.PHONY : lab2

# fast build rule for target.
lab2/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/build
.PHONY : lab2/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Experimental.dir\build.make CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Nightly.dir\build.make CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Continuous.dir\build.make CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyMemoryCheck.dir\build.make CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyStart.dir\build.make CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyUpdate.dir\build.make CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyConfigure.dir\build.make CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyBuild.dir\build.make CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyTest.dir\build.make CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyCoverage.dir\build.make CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlyMemCheck.dir\build.make CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\NightlySubmit.dir\build.make CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalStart.dir\build.make CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalUpdate.dir\build.make CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalConfigure.dir\build.make CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalBuild.dir\build.make CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalTest.dir\build.make CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalCoverage.dir\build.make CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalMemCheck.dir\build.make CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ExperimentalSubmit.dir\build.make CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousStart.dir\build.make CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousUpdate.dir\build.make CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousConfigure.dir\build.make CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousBuild.dir\build.make CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousTest.dir\build.make CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousCoverage.dir\build.make CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousMemCheck.dir\build.make CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\ContinuousSubmit.dir\build.make CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named lab2tests

# Build rule for target.
lab2tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 lab2tests
.PHONY : lab2tests

# fast build rule for target.
lab2tests/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/build
.PHONY : lab2tests/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f third-party\gtest\googlemock\CMakeFiles\gmock.dir\build.make third-party/gtest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f third-party\gtest\googlemock\CMakeFiles\gmock_main.dir\build.make third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f third-party\gtest\googletest\CMakeFiles\gtest.dir\build.make third-party/gtest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles\Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f third-party\gtest\googletest\CMakeFiles\gtest_main.dir\build.make third-party/gtest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

main.obj: main.cpp.obj
.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/main.cpp.s
.PHONY : main.cpp.s

src/CommandParser/CommandParser.obj: src/CommandParser/CommandParser.cpp.obj
.PHONY : src/CommandParser/CommandParser.obj

# target to build an object file
src/CommandParser/CommandParser.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/CommandParser/CommandParser.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/CommandParser/CommandParser.cpp.obj
.PHONY : src/CommandParser/CommandParser.cpp.obj

src/CommandParser/CommandParser.i: src/CommandParser/CommandParser.cpp.i
.PHONY : src/CommandParser/CommandParser.i

# target to preprocess a source file
src/CommandParser/CommandParser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/CommandParser/CommandParser.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/CommandParser/CommandParser.cpp.i
.PHONY : src/CommandParser/CommandParser.cpp.i

src/CommandParser/CommandParser.s: src/CommandParser/CommandParser.cpp.s
.PHONY : src/CommandParser/CommandParser.s

# target to generate assembly for a file
src/CommandParser/CommandParser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/CommandParser/CommandParser.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/CommandParser/CommandParser.cpp.s
.PHONY : src/CommandParser/CommandParser.cpp.s

src/ContentsCommand/ContentsCommand.obj: src/ContentsCommand/ContentsCommand.cpp.obj
.PHONY : src/ContentsCommand/ContentsCommand.obj

# target to build an object file
src/ContentsCommand/ContentsCommand.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ContentsCommand/ContentsCommand.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ContentsCommand/ContentsCommand.cpp.obj
.PHONY : src/ContentsCommand/ContentsCommand.cpp.obj

src/ContentsCommand/ContentsCommand.i: src/ContentsCommand/ContentsCommand.cpp.i
.PHONY : src/ContentsCommand/ContentsCommand.i

# target to preprocess a source file
src/ContentsCommand/ContentsCommand.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ContentsCommand/ContentsCommand.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ContentsCommand/ContentsCommand.cpp.i
.PHONY : src/ContentsCommand/ContentsCommand.cpp.i

src/ContentsCommand/ContentsCommand.s: src/ContentsCommand/ContentsCommand.cpp.s
.PHONY : src/ContentsCommand/ContentsCommand.s

# target to generate assembly for a file
src/ContentsCommand/ContentsCommand.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ContentsCommand/ContentsCommand.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ContentsCommand/ContentsCommand.cpp.s
.PHONY : src/ContentsCommand/ContentsCommand.cpp.s

src/File/File.obj: src/File/File.cpp.obj
.PHONY : src/File/File.obj

# target to build an object file
src/File/File.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/File.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/File.cpp.obj
.PHONY : src/File/File.cpp.obj

src/File/File.i: src/File/File.cpp.i
.PHONY : src/File/File.i

# target to preprocess a source file
src/File/File.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/File.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/File.cpp.i
.PHONY : src/File/File.cpp.i

src/File/File.s: src/File/File.cpp.s
.PHONY : src/File/File.s

# target to generate assembly for a file
src/File/File.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/File.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/File.cpp.s
.PHONY : src/File/File.cpp.s

src/File/WorkSpace.obj: src/File/WorkSpace.cpp.obj
.PHONY : src/File/WorkSpace.obj

# target to build an object file
src/File/WorkSpace.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/WorkSpace.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/WorkSpace.cpp.obj
.PHONY : src/File/WorkSpace.cpp.obj

src/File/WorkSpace.i: src/File/WorkSpace.cpp.i
.PHONY : src/File/WorkSpace.i

# target to preprocess a source file
src/File/WorkSpace.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/WorkSpace.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/WorkSpace.cpp.i
.PHONY : src/File/WorkSpace.cpp.i

src/File/WorkSpace.s: src/File/WorkSpace.cpp.s
.PHONY : src/File/WorkSpace.s

# target to generate assembly for a file
src/File/WorkSpace.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/File/WorkSpace.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/File/WorkSpace.cpp.s
.PHONY : src/File/WorkSpace.cpp.s

src/FileCommand/FileCommand.obj: src/FileCommand/FileCommand.cpp.obj
.PHONY : src/FileCommand/FileCommand.obj

# target to build an object file
src/FileCommand/FileCommand.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/FileCommand/FileCommand.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/FileCommand/FileCommand.cpp.obj
.PHONY : src/FileCommand/FileCommand.cpp.obj

src/FileCommand/FileCommand.i: src/FileCommand/FileCommand.cpp.i
.PHONY : src/FileCommand/FileCommand.i

# target to preprocess a source file
src/FileCommand/FileCommand.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/FileCommand/FileCommand.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/FileCommand/FileCommand.cpp.i
.PHONY : src/FileCommand/FileCommand.cpp.i

src/FileCommand/FileCommand.s: src/FileCommand/FileCommand.cpp.s
.PHONY : src/FileCommand/FileCommand.s

# target to generate assembly for a file
src/FileCommand/FileCommand.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/FileCommand/FileCommand.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/FileCommand/FileCommand.cpp.s
.PHONY : src/FileCommand/FileCommand.cpp.s

src/Session/Session.obj: src/Session/Session.cpp.obj
.PHONY : src/Session/Session.obj

# target to build an object file
src/Session/Session.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/Session/Session.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/Session/Session.cpp.obj
.PHONY : src/Session/Session.cpp.obj

src/Session/Session.i: src/Session/Session.cpp.i
.PHONY : src/Session/Session.i

# target to preprocess a source file
src/Session/Session.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/Session/Session.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/Session/Session.cpp.i
.PHONY : src/Session/Session.cpp.i

src/Session/Session.s: src/Session/Session.cpp.s
.PHONY : src/Session/Session.s

# target to generate assembly for a file
src/Session/Session.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/Session/Session.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/Session/Session.cpp.s
.PHONY : src/Session/Session.cpp.s

src/SessionCommand/SessionCommand.obj: src/SessionCommand/SessionCommand.cpp.obj
.PHONY : src/SessionCommand/SessionCommand.obj

# target to build an object file
src/SessionCommand/SessionCommand.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/SessionCommand/SessionCommand.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/SessionCommand/SessionCommand.cpp.obj
.PHONY : src/SessionCommand/SessionCommand.cpp.obj

src/SessionCommand/SessionCommand.i: src/SessionCommand/SessionCommand.cpp.i
.PHONY : src/SessionCommand/SessionCommand.i

# target to preprocess a source file
src/SessionCommand/SessionCommand.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/SessionCommand/SessionCommand.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/SessionCommand/SessionCommand.cpp.i
.PHONY : src/SessionCommand/SessionCommand.cpp.i

src/SessionCommand/SessionCommand.s: src/SessionCommand/SessionCommand.cpp.s
.PHONY : src/SessionCommand/SessionCommand.s

# target to generate assembly for a file
src/SessionCommand/SessionCommand.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/SessionCommand/SessionCommand.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/SessionCommand/SessionCommand.cpp.s
.PHONY : src/SessionCommand/SessionCommand.cpp.s

src/ShowCommand/ShowCommand.obj: src/ShowCommand/ShowCommand.cpp.obj
.PHONY : src/ShowCommand/ShowCommand.obj

# target to build an object file
src/ShowCommand/ShowCommand.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ShowCommand/ShowCommand.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ShowCommand/ShowCommand.cpp.obj
.PHONY : src/ShowCommand/ShowCommand.cpp.obj

src/ShowCommand/ShowCommand.i: src/ShowCommand/ShowCommand.cpp.i
.PHONY : src/ShowCommand/ShowCommand.i

# target to preprocess a source file
src/ShowCommand/ShowCommand.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ShowCommand/ShowCommand.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ShowCommand/ShowCommand.cpp.i
.PHONY : src/ShowCommand/ShowCommand.cpp.i

src/ShowCommand/ShowCommand.s: src/ShowCommand/ShowCommand.cpp.s
.PHONY : src/ShowCommand/ShowCommand.s

# target to generate assembly for a file
src/ShowCommand/ShowCommand.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/ShowCommand/ShowCommand.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/ShowCommand/ShowCommand.cpp.s
.PHONY : src/ShowCommand/ShowCommand.cpp.s

src/tool/tool.obj: src/tool/tool.cpp.obj
.PHONY : src/tool/tool.obj

# target to build an object file
src/tool/tool.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/tool/tool.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/tool/tool.cpp.obj
.PHONY : src/tool/tool.cpp.obj

src/tool/tool.i: src/tool/tool.cpp.i
.PHONY : src/tool/tool.i

# target to preprocess a source file
src/tool/tool.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/tool/tool.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/tool/tool.cpp.i
.PHONY : src/tool/tool.cpp.i

src/tool/tool.s: src/tool/tool.cpp.s
.PHONY : src/tool/tool.s

# target to generate assembly for a file
src/tool/tool.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/src/tool/tool.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/src/tool/tool.cpp.s
.PHONY : src/tool/tool.cpp.s

test.obj: test.cpp.obj
.PHONY : test.obj

# target to build an object file
test.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/test.cpp.obj
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/test.cpp.obj
.PHONY : test.cpp.obj

test.i: test.cpp.i
.PHONY : test.i

# target to preprocess a source file
test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/test.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/test.cpp.i
.PHONY : test.cpp.i

test.s: test.cpp.s
.PHONY : test.s

# target to generate assembly for a file
test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2.dir\build.make CMakeFiles/lab2.dir/test.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/test.cpp.s
.PHONY : test.cpp.s

tests/test1.obj: tests/test1.cpp.obj
.PHONY : tests/test1.obj

# target to build an object file
tests/test1.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test1.cpp.obj
.PHONY : tests/test1.cpp.obj

tests/test1.i: tests/test1.cpp.i
.PHONY : tests/test1.i

# target to preprocess a source file
tests/test1.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test1.cpp.i
.PHONY : tests/test1.cpp.i

tests/test1.s: tests/test1.cpp.s
.PHONY : tests/test1.s

# target to generate assembly for a file
tests/test1.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test1.cpp.s
.PHONY : tests/test1.cpp.s

tests/test2.obj: tests/test2.cpp.obj
.PHONY : tests/test2.obj

# target to build an object file
tests/test2.cpp.obj:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test2.cpp.obj
.PHONY : tests/test2.cpp.obj

tests/test2.i: tests/test2.cpp.i
.PHONY : tests/test2.i

# target to preprocess a source file
tests/test2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test2.cpp.i
.PHONY : tests/test2.cpp.i

tests/test2.s: tests/test2.cpp.s
.PHONY : tests/test2.s

# target to generate assembly for a file
tests/test2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles\lab2tests.dir\build.make CMakeFiles/lab2tests.dir/tests/test2.cpp.s
.PHONY : tests/test2.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... install
	@echo ... install/local
	@echo ... install/strip
	@echo ... list_install_components
	@echo ... rebuild_cache
	@echo ... test
	@echo ... Continuous
	@echo ... ContinuousBuild
	@echo ... ContinuousConfigure
	@echo ... ContinuousCoverage
	@echo ... ContinuousMemCheck
	@echo ... ContinuousStart
	@echo ... ContinuousSubmit
	@echo ... ContinuousTest
	@echo ... ContinuousUpdate
	@echo ... Experimental
	@echo ... ExperimentalBuild
	@echo ... ExperimentalConfigure
	@echo ... ExperimentalCoverage
	@echo ... ExperimentalMemCheck
	@echo ... ExperimentalStart
	@echo ... ExperimentalSubmit
	@echo ... ExperimentalTest
	@echo ... ExperimentalUpdate
	@echo ... Nightly
	@echo ... NightlyBuild
	@echo ... NightlyConfigure
	@echo ... NightlyCoverage
	@echo ... NightlyMemCheck
	@echo ... NightlyMemoryCheck
	@echo ... NightlyStart
	@echo ... NightlySubmit
	@echo ... NightlyTest
	@echo ... NightlyUpdate
	@echo ... gmock
	@echo ... gmock_main
	@echo ... gtest
	@echo ... gtest_main
	@echo ... lab2
	@echo ... lab2tests
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... src/CommandParser/CommandParser.obj
	@echo ... src/CommandParser/CommandParser.i
	@echo ... src/CommandParser/CommandParser.s
	@echo ... src/ContentsCommand/ContentsCommand.obj
	@echo ... src/ContentsCommand/ContentsCommand.i
	@echo ... src/ContentsCommand/ContentsCommand.s
	@echo ... src/File/File.obj
	@echo ... src/File/File.i
	@echo ... src/File/File.s
	@echo ... src/File/WorkSpace.obj
	@echo ... src/File/WorkSpace.i
	@echo ... src/File/WorkSpace.s
	@echo ... src/FileCommand/FileCommand.obj
	@echo ... src/FileCommand/FileCommand.i
	@echo ... src/FileCommand/FileCommand.s
	@echo ... src/Session/Session.obj
	@echo ... src/Session/Session.i
	@echo ... src/Session/Session.s
	@echo ... src/SessionCommand/SessionCommand.obj
	@echo ... src/SessionCommand/SessionCommand.i
	@echo ... src/SessionCommand/SessionCommand.s
	@echo ... src/ShowCommand/ShowCommand.obj
	@echo ... src/ShowCommand/ShowCommand.i
	@echo ... src/ShowCommand/ShowCommand.s
	@echo ... src/tool/tool.obj
	@echo ... src/tool/tool.i
	@echo ... src/tool/tool.s
	@echo ... test.obj
	@echo ... test.i
	@echo ... test.s
	@echo ... tests/test1.obj
	@echo ... tests/test1.i
	@echo ... tests/test1.s
	@echo ... tests/test2.obj
	@echo ... tests/test2.i
	@echo ... tests/test2.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

