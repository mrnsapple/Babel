# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oriol/Epitech_projects/2_C++/babel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oriol/Epitech_projects/2_C++/babel/build

# Include any dependencies generated for this target.
include server/CMakeFiles/babel_server.dir/depend.make

# Include the progress variables for this target.
include server/CMakeFiles/babel_server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/babel_server.dir/flags.make

server/CMakeFiles/babel_server.dir/main.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/main.cpp.o: ../server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object server/CMakeFiles/babel_server.dir/main.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/main.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/server/main.cpp

server/CMakeFiles/babel_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/main.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/server/main.cpp > CMakeFiles/babel_server.dir/main.cpp.i

server/CMakeFiles/babel_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/main.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/server/main.cpp -o CMakeFiles/babel_server.dir/main.cpp.s

server/CMakeFiles/babel_server.dir/main.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/main.cpp.o.requires

server/CMakeFiles/babel_server.dir/main.cpp.o.provides: server/CMakeFiles/babel_server.dir/main.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/main.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/main.cpp.o.provides

server/CMakeFiles/babel_server.dir/main.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/main.cpp.o


server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o: ../server/classes/Database/Database.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/server/classes/Database/Database.cpp

server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/classes/Database/Database.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/server/classes/Database/Database.cpp > CMakeFiles/babel_server.dir/classes/Database/Database.cpp.i

server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/classes/Database/Database.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/server/classes/Database/Database.cpp -o CMakeFiles/babel_server.dir/classes/Database/Database.cpp.s

server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.requires

server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.provides: server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.provides

server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o


server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o: ../GlobalClasses/Exceptions/Exceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Exceptions/Exceptions.cpp

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Exceptions/Exceptions.cpp > CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.i

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Exceptions/Exceptions.cpp -o CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.s

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.requires

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.provides: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.provides

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o


server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o: ../server/classes/Server/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/server/classes/Server/Server.cpp

server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/classes/Server/Server.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/server/classes/Server/Server.cpp > CMakeFiles/babel_server.dir/classes/Server/Server.cpp.i

server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/classes/Server/Server.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/server/classes/Server/Server.cpp -o CMakeFiles/babel_server.dir/classes/Server/Server.cpp.s

server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.requires

server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.provides: server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.provides

server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o


server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o: ../server/classes/Session/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/server/classes/Session/Session.cpp

server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/classes/Session/Session.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/server/classes/Session/Session.cpp > CMakeFiles/babel_server.dir/classes/Session/Session.cpp.i

server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/classes/Session/Session.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/server/classes/Session/Session.cpp -o CMakeFiles/babel_server.dir/classes/Session/Session.cpp.s

server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.requires

server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.provides: server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.provides

server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o


server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o: ../GlobalClasses/Serializer/Serializer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Serializer/Serializer.cpp

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Serializer/Serializer.cpp > CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.i

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Serializer/Serializer.cpp -o CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.s

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.requires

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.provides: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.provides

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o


server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o: server/CMakeFiles/babel_server.dir/flags.make
server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o: ../GlobalClasses/Request/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o -c /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Request/Request.cpp

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.i"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Request/Request.cpp > CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.i

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.s"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/babel/GlobalClasses/Request/Request.cpp -o CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.s

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.requires:

.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.requires

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.provides: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.requires
	$(MAKE) -f server/CMakeFiles/babel_server.dir/build.make server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.provides.build
.PHONY : server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.provides

server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.provides.build: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o


# Object files for target babel_server
babel_server_OBJECTS = \
"CMakeFiles/babel_server.dir/main.cpp.o" \
"CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o" \
"CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o" \
"CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o" \
"CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o" \
"CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o" \
"CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o"

# External object files for target babel_server
babel_server_EXTERNAL_OBJECTS =

bin/babel_server: server/CMakeFiles/babel_server.dir/main.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o
bin/babel_server: server/CMakeFiles/babel_server.dir/build.make
bin/babel_server: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.9.5
bin/babel_server: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
bin/babel_server: server/CMakeFiles/babel_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oriol/Epitech_projects/2_C++/babel/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/babel_server"
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/babel_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/babel_server.dir/build: bin/babel_server

.PHONY : server/CMakeFiles/babel_server.dir/build

server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/main.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/classes/Database/Database.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Exceptions/Exceptions.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/classes/Server/Server.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/classes/Session/Session.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Serializer/Serializer.cpp.o.requires
server/CMakeFiles/babel_server.dir/requires: server/CMakeFiles/babel_server.dir/__/GlobalClasses/Request/Request.cpp.o.requires

.PHONY : server/CMakeFiles/babel_server.dir/requires

server/CMakeFiles/babel_server.dir/clean:
	cd /home/oriol/Epitech_projects/2_C++/babel/build/server && $(CMAKE_COMMAND) -P CMakeFiles/babel_server.dir/cmake_clean.cmake
.PHONY : server/CMakeFiles/babel_server.dir/clean

server/CMakeFiles/babel_server.dir/depend:
	cd /home/oriol/Epitech_projects/2_C++/babel/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oriol/Epitech_projects/2_C++/babel /home/oriol/Epitech_projects/2_C++/babel/server /home/oriol/Epitech_projects/2_C++/babel/build /home/oriol/Epitech_projects/2_C++/babel/build/server /home/oriol/Epitech_projects/2_C++/babel/build/server/CMakeFiles/babel_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/babel_server.dir/depend

