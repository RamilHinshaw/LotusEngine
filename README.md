<p align="center"><img src="https://raw.githubusercontent.com/RamilHinshaw/lotusengine/master/logo/Logo%20Banner.png"/></p>

---
<p align="center">My work-in-progress hobby game engine primarily used for educational purposes.</p>

---

## Roadmap (Current Version: 0.1)

### Progress to 0.2
	- Virtual Resolution
	- Play Audio
	- Text Renderer
	- Lua Integration


### Progress to 0.3
	- Compile Dynamic Library for Engine
	- Simple Editor that interacts with dynamic library
	- Entity Component System
	- Pack/Read Files with zlib
	- LotusPlayer to read packed files

## Build Instructions

### Linux with gcc
- download:
	- libsdl2-dev
	- libglm-dev
	- liblua5.1-0-dev
	- libglew-dev
- git clone this project
- git submodule init & git submodule update
- cd into project and mkdir /build directory
- cd into /build and compile as cmake ..
- run make


### Windows with mingw32/mingw64
- download & add to path:
	- sdl2 source files
	- glm header file
	- lua 5.1
	- glew source files
- download mingw64 & sdl2 source files
- add to windows path (recommended to put near top to avoid conflicts)
- git clone this project
- git submodule init & git submodule update
- create build directory
- compile with " cmake.exe -G "MinGW Makefiles" % .. "
OR
- copy mingw32 into build then run "mingw32-make.exe .."

---
<p align="center">Copyright &copy; 2019-present Ramil Hinshaw</p>
<p align="center">My Original Source code under MIT & Images under CC BY-SA 4.0 License, Lotus Logo not included.</p>
