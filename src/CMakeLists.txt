set(DSA "DSA")
string(TOLOWER "${DSA}" DSA)

set(HEADERS "DSA/core.h"
            "DSA/utility.h"
            "DSA/linkedlist.h")

set(SOURCES "DSA/utility.c"
            "DSA/linkedlist.c")

add_library("${DSA}" STATIC "${HEADERS}" "${SOURCES}")

set(TARGET "main")

set(DRIVER "main.c")

add_executable("${TARGET}" "${DRIVER}")

target_link_libraries("${TARGET}" "${DSA}")
