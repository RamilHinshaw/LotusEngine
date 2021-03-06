
# SDL2_FOUND - System has SDL2
# SDL2_INCLUDE_DIRS - The SDL2 include directories
# SDL2_LIBRARIES - The libraries needed to use SDL2

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h
	HINTS
	${CMAKE_SOURCE_DIR}
	$ENV{SDL2_DIR}
	PATH_SUFFIXES 
	include/SDL2 
	include
	SDL2
	PATHS
	./lib/SDL2
	./lib/
	/usr/local
	/usr
	/opt
)

# 64 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_LIBRARY SDL2
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib64 
		lib
		lib/x64
		lib/x64/SDL2
		PATHS
		/opt
	)
# 32 bit
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_LIBRARY SDL2
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib
		lib/x86
		lib/x86/SDL2
		PATHS
		/opt
	)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

# 64 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_MAIN_LIBRARY SDL2main
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib64
		lib
		lib/x64
		lib/x64/SDL2
		PATHS
		/opt
		)
# 32 bit
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_MAIN_LIBRARY SDL2main
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib
		lib/x86
		lib/x86/SDL2_image
		PATHS
		/opt
		)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2 DEFAULT_MSG SDL2_LIBRARY SDL2_INCLUDE_DIR)

mark_as_advanced(SDL2_INCLUDE_DIR SDL2_LIBRARY SDL2_MAIN_LIBRARY)

set(SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2_MAIN_LIBRARY})
set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
