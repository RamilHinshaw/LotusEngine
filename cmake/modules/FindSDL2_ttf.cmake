
# SDL2_TTF_FOUND - System has SDL2_ttf
# SDL2_TTF_INCLUDE_DIRS - The SDL2_ttf include directories
# SDL2_TTF_LIBRARIES - The libraries needed to use SDL2_ttf

find_path(SDL2_TTF_INCLUDE_DIR SDL2/SDL_ttf.h
	HINTS
	${CMAKE_SOURCE_DIR}
	$ENV{SDL2_DIR}
	PATH_SUFFIXES
	include/SDL2
	include
	SDL2
	PATHS
	./lib/
	/usr/local
	/usr
	/opt
)

# 64 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib64 
		lib
		lib/x64
		PATHS
		/opt
	)

# 32 bit
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
	FIND_LIBRARY(SDL2_TTF_LIBRARY SDL2_ttf
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{SDL2_DIR}
		PATH_SUFFIXES 
		lib
		lib/x86
		PATHS
		/opt
	)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2_ttf DEFAULT_MSG SDL2_TTF_LIBRARY SDL2_TTF_INCLUDE_DIR)

mark_as_advanced(SDL2_TTF_INCLUDE_DIR SDL2_TTF_LIBRARY)

set(SDL2_TTF_LIBRARIES ${SDL2_TTF_LIBRARY})
set(SDL2_TTF_INCLUDE_DIRS ${SDL2_TTF_INCLUDE_DIR})
