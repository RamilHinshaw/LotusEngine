
# GLEW_FOUND - System has GLEW
# GLEW_INCLUDE_DIRS - GLEW include directories
# GLEW_LIBRARIES - Libraries needed to use GLEW

find_path(GLEW_INCLUDE_DIR GL/glew.h
	HINTS
	${CMAKE_SOURCE_DIR}
	$ENV{GLEW_DIR}
	PATH_SUFFIXES 
	include/GL 
	include
	GL
	PATHS
    ./lib/
	/usr/local
	/usr
	/opt
)

# 64 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "GLEW target is 64 bit")
        find_library(GLEW_LIBRARY
		NAMES glew32 glew32s glew GLEW
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{GLEW_DIR}
		PATH_SUFFIXES
		lib64
		lib
		lib/x64
		lib/x64/glew
		PATHS
		/opt
	)
# 32 bit
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "GLEW target is 32 bit")
        find_library(GLEW_LIBRARY
		NAMES glew32 glew32s glew GLEW
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{GLEW_DIR}
		PATH_SUFFIXES
		lib32
		lib
		lib/x86
		lib/x86/glew
		PATHS
		/opt
	)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GLEW DEFAULT_MSG GLEW_LIBRARY GLEW_INCLUDE_DIR)

mark_as_advanced(GLEW_INCLUDE_DIR GLEW_LIBRARY)

set(GLEW_LIBRARIES ${GLEW_LIBRARY})
set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
