cmake_minimum_required(VERSION 3.6.0)

project(PDC_Library)

#source file to compile
set(PDC_SRC_FILES "")

# header file to include
set(PDC_HEADER_FILES "")

include_directories(includes)
include_directories(internals)

add_subdirectory(includes)
add_subdirectory(internals)
add_subdirectory(platform)
add_subdirectory(functions)

add_library(pdc_library ${PDC_HEADER_FILES} ${PDC_SRC_FILES})