
# GLAD_FOUND - System has GLAD
# GLAD_INCLUDE_DIRS - GLAD include directories
# GLAD_LIBRARIES - Libraries needed to use GLAD

find_path(GLAD_INCLUDE_DIR glad.h
	HINTS
	${CMAKE_SOURCE_DIR}
	$ENV{GLAD_DIR}
	PATH_SUFFIXES 
	include/GL 
	include
	GL
	PATHS
	./thirdparty/glad
    ./lib/
	/usr/local
	/usr
	/opt
)

# 64 bit
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "GLAD target is 64 bit")
        find_library(GLAD_LIBRARY
		NAMES GLAD32 GLAD32s GLAD GLAD
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{GLAD_DIR}
		PATH_SUFFIXES
		./thirdparty/glad
		lib64
		lib
		lib/x64
		lib/x64/GLAD
		PATHS
		/opt
	)
# 32 bit
else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "GLAD target is 32 bit")
        find_library(GLAD_LIBRARY
		NAMES GLAD32 GLAD32s GLAD GLAD
		HINTS
		${CMAKE_SOURCE_DIR}
		$ENV{GLAD_DIR}
		PATH_SUFFIXES
		./thirdparty/glad
		lib32
		lib
		lib/x86
		lib/x86/GLAD
		PATHS
		/opt
	)
endif(CMAKE_SIZEOF_VOID_P EQUAL 8)

# include(FindPackageHandleStandardArgs)

# find_package_handle_standard_args(GLAD DEFAULT_MSG GLAD_LIBRARY GLAD_INCLUDE_DIR)

mark_as_advanced(GLAD_INCLUDE_DIR GLAD_LIBRARY)

set(GLAD_LIBRARIES ${GLAD_LIBRARY})
set(GLAD_INCLUDE_DIRS ${GLAD_INCLUDE_DIR})
