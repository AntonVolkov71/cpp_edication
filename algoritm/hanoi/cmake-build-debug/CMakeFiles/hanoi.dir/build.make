# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Edication\3. cpp\algoritm\hanoi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/hanoi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hanoi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hanoi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hanoi.dir/flags.make

CMakeFiles/hanoi.dir/main.cpp.obj: CMakeFiles/hanoi.dir/flags.make
CMakeFiles/hanoi.dir/main.cpp.obj: D:/Edication/3.\ cpp/algoritm/hanoi/main.cpp
CMakeFiles/hanoi.dir/main.cpp.obj: CMakeFiles/hanoi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hanoi.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hanoi.dir/main.cpp.obj -MF CMakeFiles\hanoi.dir\main.cpp.obj.d -o CMakeFiles\hanoi.dir\main.cpp.obj -c "D:\Edication\3. cpp\algoritm\hanoi\main.cpp"

CMakeFiles/hanoi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/hanoi.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Edication\3. cpp\algoritm\hanoi\main.cpp" > CMakeFiles\hanoi.dir\main.cpp.i

CMakeFiles/hanoi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/hanoi.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Edication\3. cpp\algoritm\hanoi\main.cpp" -o CMakeFiles\hanoi.dir\main.cpp.s

# Object files for target hanoi
hanoi_OBJECTS = \
"CMakeFiles/hanoi.dir/main.cpp.obj"

# External object files for target hanoi
hanoi_EXTERNAL_OBJECTS =

hanoi.exe: CMakeFiles/hanoi.dir/main.cpp.obj
hanoi.exe: CMakeFiles/hanoi.dir/build.make
hanoi.exe: CMakeFiles/hanoi.dir/linkLibs.rsp
hanoi.exe: CMakeFiles/hanoi.dir/objects1.rsp
hanoi.exe: CMakeFiles/hanoi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hanoi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hanoi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hanoi.dir/build: hanoi.exe
.PHONY : CMakeFiles/hanoi.dir/build

CMakeFiles/hanoi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hanoi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hanoi.dir/clean

CMakeFiles/hanoi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Edication\3. cpp\algoritm\hanoi" "D:\Edication\3. cpp\algoritm\hanoi" "D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug" "D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug" "D:\Edication\3. cpp\algoritm\hanoi\cmake-build-debug\CMakeFiles\hanoi.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/hanoi.dir/depend

