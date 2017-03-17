#Header Files which will export to public

set(PDC_HEADER_FILES ${PDC_HEADER_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/nothread/_PDCLIB_threadconfig.h
        PARENT_SCOPE)


set(PDC_THREAD_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/nothread/ CACHE STRING "thread include path")