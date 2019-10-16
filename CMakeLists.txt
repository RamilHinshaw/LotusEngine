project(LotusEngine)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

#Required dependencies:

	# find_package(OpenGL REQUIRED)
	# if(OPENGL_FOUND)
	# 	include_directories(${OPENGL_INCLUDE_DIRS})
	# 	message(STATUS "OpenGL Include Dir: " ${OPENGL_INCLUDE_DIRS})
	# endif()
	# 
	# find_package(GLEW REQUIRED)
	# if(GLEW_FOUND)
	# 	include_directories(${GLEW_INCLUDE_DIRS})
	# 	message(STATUS "GLEW Include Dir: ${GLEW_INCLUDE_DIRS}")
	# endif()

	find_package(SDL2 REQUIRED)
	if(SDL2_FOUND)
		include_directories(${SDL2_INCLUDE_DIRS})
		message(STATUS "SDL2 Include Dir: " ${SDL2_INCLUDE_DIRS})
	endif()

	find_package(SDL2_ttf REQUIRED)
	if(SDL2_ttf_FOUND)
		include_directories(${SDL2_TTF_INCLUDE_DIRS})
		message(STATUS "SDL2_ttf Include Dir: " ${SDL2_TTF_INCLUDE_DIRS})
	endif()

	find_package(SDL2_image REQUIRED)
	if(SDL2_image_FOUND)
		include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
		message(STATUS "SDL2_image Include Dir: " ${SDL2_IMAGE_INCLUDE_DIRS})
	endif()

	#find_package(LuaREQUIRED)
	#if(LUA_FOUND)
	#	include_directories(${LUA_INCLUDE_DIRS})
	#	message(STATUS "Lua Include Dir: " ${LUA_INCLUDE_DIRS})
	#endif()



# Add global definitions
add_definitions("-Wall -Wno-unused -Werror -Wextra -pedantic -pthread")
include_directories(${SDL2_INCLUDE_DIR})
#Set the C++ version
set (CMAKE_CXX_STANDARD 11)

# #Compiler Flags
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") 
# if(WIN32)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -nologo -Gm- -EHa- -Od -Oi -WX -W4 -wd4100 -wd4189")
# add_definitions(-D_CRT_SECURE_NO_WARNINGS)
# else()
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic")
# endif()


# DO RECURSION HERE TO KEEP UP WITH FOLDERS like this:
# https://stackoverflow.com/questions/6921695/how-can-i-build-a-c-project-with-multiple-interdependent-subdirectories
#Import all source files
file(GLOB header_files 
	"src/*.h" 
	"src/*.hpp" 
	"src/engine/*.hpp"
)

#Import all header files
file(GLOB src_files
	"src/*.c" 
	"src/*.cpp" 
	"src/engine/*.cpp"
)

add_executable(${PROJECT_NAME} ${header_files} ${src_files})

# add_executable(${PROJECT_NAME} main.cpp Game.cpp)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

#Linker
set(
	target_link_lib
# 	${OPENGL_LIBRARIES}
# 	${GLEW_LIBRARIES}
	${SDL2_LIBRARIES} 
	${SDL2_TTF_LIBRARIES} 
	${SDL2_IMAGE_LIBRARIES}
	#${LUA_LIBRARIES}
	"lua5.3"   # HARD CODED FIX IN FindLua.cmake file
	)


target_link_libraries(${PROJECT_NAME} ${target_link_lib})

#Copy Assets
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)

