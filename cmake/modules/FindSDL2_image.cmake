
find_path(SDL2_IMAGE_INCLUDE_DIR SDL2/SDL_image.h
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
	FIND_LIBRARY(SDL2_IMAGE_LIBRARY SDL2_image
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
	FIND_LIBRARY(SDL2_IMAGE_LIBRARY SDL2_image
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

find_package_handle_standard_args(SDL2_image DEFAULT_MSG SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)

mark_as_advanced(SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY)

set(SDL2_IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARY})
set(SDL2_IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIR})
