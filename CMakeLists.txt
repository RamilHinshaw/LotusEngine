cmake_minimum_required(VERSION 2.8)

project(LotusEngine)

#Set the C++ version
set (CMAKE_CXX_STANDARD 17)

# Set Defualt build type to Release
# if(NOT CMAKE_BUILD_TYPE)
#   set(CMAKE_BUILD_TYPE Release)
# endif()

# Set Release/Debug Flags
# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

#Required dependencies:

	find_package(OpenGL REQUIRED)
	if(OPENGL_FOUND)
		include_directories(${OPENGL_INCLUDE_DIRS})
		message(STATUS "OpenGL Include Dir: " ${OPENGL_INCLUDE_DIRS})
	endif()
	
	find_package(GLEW REQUIRED)
	if(GLEW_FOUND)
		include_directories(${GLEW_INCLUDE_DIRS})
		message(STATUS "GLEW Include Dir: ${GLEW_INCLUDE_DIRS}")
	endif()

	# find_package(GLAD REQUIRED)
	# if(GLAD)
	# 	include_directories(${GLAD_INCLUDE_DIRS})
	# 	message(STATUS "GLAD Include Dir: ${GLAD_INCLUDE_DIRS}")
	# endif()

	find_package(SDL2 REQUIRED)
	if(SDL2_FOUND)
		include_directories(${SDL2_INCLUDE_DIRS})
		message(STATUS "SDL2 Include Dir: " ${SDL2_INCLUDE_DIRS})
		message(STATUS "SDL2 Lib Dir: " ${SDL2_LIBRARY})
		message(STATUS "SDL2Main Lib Dir: " ${SDL2_MAIN_LIBRARY})
	endif()

	# find_package(SDL2_ttf REQUIRED)
	# if(SDL2_ttf_FOUND)
	# 	include_directories(${SDL2_TTF_INCLUDE_DIRS})
	# 	message(STATUS "SDL2_ttf Include Dir: " ${SDL2_TTF_INCLUDE_DIRS})
	# endif()

	# find_package(SDL2_image REQUIRED)
	# if(SDL2_image_FOUND)
	# 	include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
	# 	message(STATUS "SDL2_image Include Dir: " ${SDL2_IMAGE_INCLUDE_DIRS})
	# endif()

	find_package(Lua REQUIRED)
	if(LUA_FOUND)
		include_directories(${LUA_INCLUDE_DIRS})
		message(STATUS "Lua Include Dir: " ${LUA_INCLUDE_DIRS})
	endif()



# Add global definitions
#Compiler Flags
if (UNIX)
	message(STATUS "Detected Unix!")
	add_definitions("-Wall -Wno-unused  -Wextra ") # -Werror -pedantic

elseif (WIN32)
	message(STATUS "Detected Windows!")
	#-IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o 01_hello_SDL
	# set(INCLUDE_PATHS "-IC:/MinGW/include/SDL2")
	# set(LIBRARY_PATHS "-LC:/MinGW/lib")

	# add_definitions("-w -Wl,-subsystem,windows") # THIS DOES NOt WORK THE WAY I THINK IT DOES!
endif()

# ToDo: USE RECURSION HERE TO KEEP UP WITH FOLDERS like this:
# https://stackoverflow.com/questions/6921695/how-can-i-build-a-c-project-with-multiple-interdependent-subdirectories

#Import all header files
file(GLOB src_files
	"src/*.c" 
	"src/*.cpp" 
	"src/engine/*.cpp"

	"src/engine/*.c"

	"src/graphics/*.cpp"
	"src/graphics/opengl/*.cpp"
	"src/input/*.cpp"
	"src/math/*.cpp"
	"src/physics/*.cpp"
	"src/core/*.cpp"
	"src/gui/*.cpp"
	"src/lua/*.cpp"

	# "src/thirdparty/glad/*.c"
)
message(STATUS "Sources: " ${src_files})

add_executable(${PROJECT_NAME} ${src_files})

# add_executable(${PROJECT_NAME} main.cpp Game.cpp)
# install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# add_subdirectory(thirdparty/glad)

#Linker
set(
	target_link_lib
	${OPENGL_LIBRARIES}
	${GLEW_LIBRARIES}
	${SDL2_LIBRARY} 

	# ${SDL2_TTF_LIBRARIES} 
	# ${SDL2_IMAGE_LIBRARIES}
	${LUA_LIBRARIES}
	# "lua5.3"   # HARD CODED FIX IN FindLua.cmake file
	)


# COMPILE
if (UNIX)
	target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} ${target_link_lib})
elseif (WIN32)
	target_link_libraries(${PROJECT_NAME} "-w -Wl,-subsystem,windows" "-static -lmingw32 -lSDL2main" ${target_link_lib})
endif()


#Copy Assets
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

