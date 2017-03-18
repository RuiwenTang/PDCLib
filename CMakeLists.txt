cmake_minimum_required(VERSION 3.6.0)

project(PDC_Library)

#source file to compile
set(PDC_SRC_FILES "")

# header file to include
set(PDC_HEADER_FILES "")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -fbuiltin -D_PDCLIB_EXTENSIONS")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffreestanding -fbuiltin -D_PDCLIB_EXTENSIONS")

include_directories(includes)
include_directories(internals)

add_subdirectory(includes)
add_subdirectory(internals)
add_subdirectory(platform)
add_subdirectory(opt)
add_subdirectory(functions)

include_directories(${PDC_PLATFORM_INCLUDE_PATH})
include_directories(${PDC_THREAD_INCLUDE_PATH})

add_library(pdc_library ${PDC_HEADER_FILES} ${PDC_SRC_FILES} ${PDC_PLATFORM_SRC_FILES} ${PDC_PLATFORM_HEADER_FILES})