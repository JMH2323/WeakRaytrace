# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "D:\11Code\CLion 2023.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\11Code\CLion 2023.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\11Code\C++\WeakRaytrace\WeakRaytrace

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WeakRaytrace.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/WeakRaytrace.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/WeakRaytrace.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WeakRaytrace.dir/flags.make

CMakeFiles/WeakRaytrace.dir/main.cpp.obj: CMakeFiles/WeakRaytrace.dir/flags.make
CMakeFiles/WeakRaytrace.dir/main.cpp.obj: D:/11Code/C++/WeakRaytrace/WeakRaytrace/main.cpp
CMakeFiles/WeakRaytrace.dir/main.cpp.obj: CMakeFiles/WeakRaytrace.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WeakRaytrace.dir/main.cpp.obj"
	"D:\11Code\CLion 2023.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/WeakRaytrace.dir/main.cpp.obj -MF CMakeFiles\WeakRaytrace.dir\main.cpp.obj.d -o CMakeFiles\WeakRaytrace.dir\main.cpp.obj -c D:\11Code\C++\WeakRaytrace\WeakRaytrace\main.cpp

CMakeFiles/WeakRaytrace.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/WeakRaytrace.dir/main.cpp.i"
	"D:\11Code\CLion 2023.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\11Code\C++\WeakRaytrace\WeakRaytrace\main.cpp > CMakeFiles\WeakRaytrace.dir\main.cpp.i

CMakeFiles/WeakRaytrace.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/WeakRaytrace.dir/main.cpp.s"
	"D:\11Code\CLion 2023.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\11Code\C++\WeakRaytrace\WeakRaytrace\main.cpp -o CMakeFiles\WeakRaytrace.dir\main.cpp.s

# Object files for target WeakRaytrace
WeakRaytrace_OBJECTS = \
"CMakeFiles/WeakRaytrace.dir/main.cpp.obj"

# External object files for target WeakRaytrace
WeakRaytrace_EXTERNAL_OBJECTS =

WeakRaytrace.exe: CMakeFiles/WeakRaytrace.dir/main.cpp.obj
WeakRaytrace.exe: CMakeFiles/WeakRaytrace.dir/build.make
WeakRaytrace.exe: CMakeFiles/WeakRaytrace.dir/linkLibs.rsp
WeakRaytrace.exe: CMakeFiles/WeakRaytrace.dir/objects1.rsp
WeakRaytrace.exe: CMakeFiles/WeakRaytrace.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WeakRaytrace.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WeakRaytrace.dir\link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Generate image.ppm"
	D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug\WeakRaytrace.exe > image.ppm

# Rule to build all files generated by this target.
CMakeFiles/WeakRaytrace.dir/build: WeakRaytrace.exe
.PHONY : CMakeFiles/WeakRaytrace.dir/build

CMakeFiles/WeakRaytrace.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WeakRaytrace.dir\cmake_clean.cmake
.PHONY : CMakeFiles/WeakRaytrace.dir/clean

CMakeFiles/WeakRaytrace.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\11Code\C++\WeakRaytrace\WeakRaytrace D:\11Code\C++\WeakRaytrace\WeakRaytrace D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug D:\11Code\C++\WeakRaytrace\WeakRaytrace\cmake-build-debug\CMakeFiles\WeakRaytrace.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/WeakRaytrace.dir/depend

