#source Files

# _PDCLIB source files
set(PDC_SRC_FILES ${PDC_SRC_FILES}
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
            )

# ctype source files
set(PDC_SRC_FILES ${PDC_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isalnum.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isalpha.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isblank.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/iscntrl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isdigit.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isgraph.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/islower.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isprint.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/ispunct.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isspace.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isupper.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/isxdigit.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/tolower.c
        ${CMAKE_CURRENT_SOURCE_DIR}/ctype/toupper.c
        )

#ERRNO
set(PDC_SRC_FILES ${PDC_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/errno/errno.c
        )

#inttypes
set(PDC_SRC_FILES ${PDC_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/inttypes/imaxabs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/inttypes/imaxdiv.c
        ${CMAKE_CURRENT_SOURCE_DIR}/inttypes/strtoimax.c
        ${CMAKE_CURRENT_SOURCE_DIR}/inttypes/strtoumax.c
        )
#local
set(PDC_SRC_FILES ${PDC_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/_PDCLIB_mb_cur_max.c
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/_PDCLIB_unicodedata.c
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/freelocale.c
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/localeconv.c
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/setlocale.c
        ${CMAKE_CURRENT_SOURCE_DIR}/locale/uselocale.c
        )

#signal
set(PDC_SRC_FILES ${PDC_SRC_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/signal/raise.c
        ${CMAKE_CURRENT_SOURCE_DIR}/signal/signal.c
        )

set(PDC_SRC_FILES ${PDC_SRC_FILES} PARENT_SCOPE)

