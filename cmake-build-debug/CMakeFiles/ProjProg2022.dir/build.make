# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "D:\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2022.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ProjProg2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ProjProg2022\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjProg2022.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjProg2022.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjProg2022.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjProg2022.dir/flags.make

CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj: ../src/Camera.cpp
CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Camera.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Camera.cpp.obj -c D:\ProjProg2022\src\Camera.cpp

CMakeFiles/ProjProg2022.dir/src/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Camera.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Camera.cpp > CMakeFiles\ProjProg2022.dir\src\Camera.cpp.i

CMakeFiles/ProjProg2022.dir/src/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Camera.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Camera.cpp -o CMakeFiles\ProjProg2022.dir\src\Camera.cpp.s

CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj: ../src/Entities/DamageableEntity.cpp
CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Entities\DamageableEntity.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Entities\DamageableEntity.cpp.obj -c D:\ProjProg2022\src\Entities\DamageableEntity.cpp

CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Entities\DamageableEntity.cpp > CMakeFiles\ProjProg2022.dir\src\Entities\DamageableEntity.cpp.i

CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Entities\DamageableEntity.cpp -o CMakeFiles\ProjProg2022.dir\src\Entities\DamageableEntity.cpp.s

CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj: ../src/Entities/DynamicEntity.cpp
CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Entities\DynamicEntity.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Entities\DynamicEntity.cpp.obj -c D:\ProjProg2022\src\Entities\DynamicEntity.cpp

CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Entities\DynamicEntity.cpp > CMakeFiles\ProjProg2022.dir\src\Entities\DynamicEntity.cpp.i

CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Entities\DynamicEntity.cpp -o CMakeFiles\ProjProg2022.dir\src\Entities\DynamicEntity.cpp.s

CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj: ../src/Entities/Entity.cpp
CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Entities\Entity.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Entities\Entity.cpp.obj -c D:\ProjProg2022\src\Entities\Entity.cpp

CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Entities\Entity.cpp > CMakeFiles\ProjProg2022.dir\src\Entities\Entity.cpp.i

CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Entities\Entity.cpp -o CMakeFiles\ProjProg2022.dir\src\Entities\Entity.cpp.s

CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj: ../src/Entities/Player.cpp
CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Entities\Player.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Entities\Player.cpp.obj -c D:\ProjProg2022\src\Entities\Player.cpp

CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Entities\Player.cpp > CMakeFiles\ProjProg2022.dir\src\Entities\Player.cpp.i

CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Entities\Player.cpp -o CMakeFiles\ProjProg2022.dir\src\Entities\Player.cpp.s

CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj: ../src/Image.cpp
CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Image.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Image.cpp.obj -c D:\ProjProg2022\src\Image.cpp

CMakeFiles/ProjProg2022.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Image.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Image.cpp > CMakeFiles\ProjProg2022.dir\src\Image.cpp.i

CMakeFiles/ProjProg2022.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Image.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Image.cpp -o CMakeFiles\ProjProg2022.dir\src\Image.cpp.s

CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj: ../src/Input.cpp
CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Input.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Input.cpp.obj -c D:\ProjProg2022\src\Input.cpp

CMakeFiles/ProjProg2022.dir/src/Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Input.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Input.cpp > CMakeFiles\ProjProg2022.dir\src\Input.cpp.i

CMakeFiles/ProjProg2022.dir/src/Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Input.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Input.cpp -o CMakeFiles\ProjProg2022.dir\src\Input.cpp.s

CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj: ../src/Maths/Timer.cpp
CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Maths\Timer.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Maths\Timer.cpp.obj -c D:\ProjProg2022\src\Maths\Timer.cpp

CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Maths\Timer.cpp > CMakeFiles\ProjProg2022.dir\src\Maths\Timer.cpp.i

CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Maths\Timer.cpp -o CMakeFiles\ProjProg2022.dir\src\Maths\Timer.cpp.s

CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj: ../src/Maths/Vec2.cpp
CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Maths\Vec2.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Maths\Vec2.cpp.obj -c D:\ProjProg2022\src\Maths\Vec2.cpp

CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Maths\Vec2.cpp > CMakeFiles\ProjProg2022.dir\src\Maths\Vec2.cpp.i

CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Maths\Vec2.cpp -o CMakeFiles\ProjProg2022.dir\src\Maths\Vec2.cpp.s

CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj: ../src/Renderer.cpp
CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Renderer.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Renderer.cpp.obj -c D:\ProjProg2022\src\Renderer.cpp

CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Renderer.cpp > CMakeFiles\ProjProg2022.dir\src\Renderer.cpp.i

CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Renderer.cpp -o CMakeFiles\ProjProg2022.dir\src\Renderer.cpp.s

CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj: ../src/Rooms/ClosedDoor.cpp
CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Rooms\ClosedDoor.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Rooms\ClosedDoor.cpp.obj -c D:\ProjProg2022\src\Rooms\ClosedDoor.cpp

CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Rooms\ClosedDoor.cpp > CMakeFiles\ProjProg2022.dir\src\Rooms\ClosedDoor.cpp.i

CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Rooms\ClosedDoor.cpp -o CMakeFiles\ProjProg2022.dir\src\Rooms\ClosedDoor.cpp.s

CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj: ../src/Rooms/Collision.cpp
CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Rooms\Collision.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Rooms\Collision.cpp.obj -c D:\ProjProg2022\src\Rooms\Collision.cpp

CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Rooms\Collision.cpp > CMakeFiles\ProjProg2022.dir\src\Rooms\Collision.cpp.i

CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Rooms\Collision.cpp -o CMakeFiles\ProjProg2022.dir\src\Rooms\Collision.cpp.s

CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj: ../src/Rooms/Door.cpp
CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Rooms\Door.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Rooms\Door.cpp.obj -c D:\ProjProg2022\src\Rooms\Door.cpp

CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Rooms\Door.cpp > CMakeFiles\ProjProg2022.dir\src\Rooms\Door.cpp.i

CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Rooms\Door.cpp -o CMakeFiles\ProjProg2022.dir\src\Rooms\Door.cpp.s

CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj: ../src/Rooms/Room.cpp
CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Rooms\Room.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Rooms\Room.cpp.obj -c D:\ProjProg2022\src\Rooms\Room.cpp

CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Rooms\Room.cpp > CMakeFiles\ProjProg2022.dir\src\Rooms\Room.cpp.i

CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Rooms\Room.cpp -o CMakeFiles\ProjProg2022.dir\src\Rooms\Room.cpp.s

CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj: ../src/Rooms/Wall.cpp
CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\Rooms\Wall.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\Rooms\Wall.cpp.obj -c D:\ProjProg2022\src\Rooms\Wall.cpp

CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\Rooms\Wall.cpp > CMakeFiles\ProjProg2022.dir\src\Rooms\Wall.cpp.i

CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\Rooms\Wall.cpp -o CMakeFiles\ProjProg2022.dir\src\Rooms\Wall.cpp.s

CMakeFiles/ProjProg2022.dir/src/World.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/World.cpp.obj: ../src/World.cpp
CMakeFiles/ProjProg2022.dir/src/World.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/ProjProg2022.dir/src/World.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/World.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\World.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\World.cpp.obj -c D:\ProjProg2022\src\World.cpp

CMakeFiles/ProjProg2022.dir/src/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/World.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\World.cpp > CMakeFiles\ProjProg2022.dir\src\World.cpp.i

CMakeFiles/ProjProg2022.dir/src/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/World.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\World.cpp -o CMakeFiles\ProjProg2022.dir\src\World.cpp.s

CMakeFiles/ProjProg2022.dir/src/main.cpp.obj: CMakeFiles/ProjProg2022.dir/flags.make
CMakeFiles/ProjProg2022.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/ProjProg2022.dir/src/main.cpp.obj: CMakeFiles/ProjProg2022.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/ProjProg2022.dir/src/main.cpp.obj"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ProjProg2022.dir/src/main.cpp.obj -MF CMakeFiles\ProjProg2022.dir\src\main.cpp.obj.d -o CMakeFiles\ProjProg2022.dir\src\main.cpp.obj -c D:\ProjProg2022\src\main.cpp

CMakeFiles/ProjProg2022.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProjProg2022.dir/src/main.cpp.i"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ProjProg2022\src\main.cpp > CMakeFiles\ProjProg2022.dir\src\main.cpp.i

CMakeFiles/ProjProg2022.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProjProg2022.dir/src/main.cpp.s"
	"D:\CLion 2022.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ProjProg2022\src\main.cpp -o CMakeFiles\ProjProg2022.dir\src\main.cpp.s

# Object files for target ProjProg2022
ProjProg2022_OBJECTS = \
"CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/World.cpp.obj" \
"CMakeFiles/ProjProg2022.dir/src/main.cpp.obj"

# External object files for target ProjProg2022
ProjProg2022_EXTERNAL_OBJECTS =

ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Camera.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Entities/DamageableEntity.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Entities/DynamicEntity.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Entities/Entity.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Entities/Player.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Image.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Input.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Maths/Timer.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Maths/Vec2.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Renderer.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Rooms/ClosedDoor.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Rooms/Collision.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Rooms/Door.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Rooms/Room.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/Rooms/Wall.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/World.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/src/main.cpp.obj
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/build.make
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/linklibs.rsp
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/objects1.rsp
ProjProg2022.exe: CMakeFiles/ProjProg2022.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ProjProg2022\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable ProjProg2022.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjProg2022.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjProg2022.dir/build: ProjProg2022.exe
.PHONY : CMakeFiles/ProjProg2022.dir/build

CMakeFiles/ProjProg2022.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjProg2022.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjProg2022.dir/clean

CMakeFiles/ProjProg2022.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ProjProg2022 D:\ProjProg2022 D:\ProjProg2022\cmake-build-debug D:\ProjProg2022\cmake-build-debug D:\ProjProg2022\cmake-build-debug\CMakeFiles\ProjProg2022.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjProg2022.dir/depend

