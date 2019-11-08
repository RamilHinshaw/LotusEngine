# VERY EARLY ALPHA!

## Build

### Linux
- download 
	- libsdl2-2.0-dev
	- libsdl2-image-2.0-dev
	- liblua-5.3-dev	
- git clone this project
- cd into project and mkdir /build directory
- cd into /build and compile as cmake ..
- run make


### Windows with mingw32/mingw64 (WIP)
- download & add to path
	- sdl2 source files
	- sdl2-image source files
	- lua5.3 source	
- download mingw64 & sdl2 source files
- add to windows path (recommended to put near top to avoid conflicts)
- create build directory
- compile with cmake .. -G "MinGW Makefiles"
- run mingw32-make.exe
