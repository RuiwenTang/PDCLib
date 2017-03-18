
#functions
set(PDC_PLATFORM_SRC_FILES ${PDC_PLATFORM_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_allocpages.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_Exit.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_fileops.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_freepages.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_open.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_rename.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/_PDCLIB/_PDCLIB_stdinit.c
        )

#stdio
set(PDC_PLATFORM_SRC_FILES ${PDC_PLATFORM_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/stdio/remove.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/stdio/tmpfile.c
        )

#stdlib
set(PDC_PLATFORM_SRC_FILES ${PDC_PLATFORM_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/stdlib/getenv.c
        ${CMAKE_CURRENT_SOURCE_DIR}/functions/stdlib/system.c
        )


set(PDC_PLATFORM_SRC_FILES ${PDC_PLATFORM_SRC_FILES} PARENT_SCOPE)

set(PDC_PLATFORM_HEADER_FILES ${PDC_PLATFORM_HEADER_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/internals/_PDCLIB_config.h
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/signal.h
        )

set(PDC_PLATFORM_HEADER_FILES ${PDC_PLATFORM_HEADER_FILES} PARENT_SCOPE)

set(PDC_PLATFORM_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/internals/ CACHE STRING "internal include path")