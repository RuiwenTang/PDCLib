#source Files

# _PDCLIB source files
set(PDC_HEADER_FILES ${PDC_SRC_FILES}
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_ascii.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_atomax.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_closeall.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_digits.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_initclocale.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_latin1.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_seed.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_strtox_main.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_strtox_prelim.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/_PDCLIB_utf8.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/assert.c
            ${CMAKE_CURRENT_SOURCE_DIR}/_PDCLIB/stdarg.c
            PARENT_SCOPE)

# ctype source files