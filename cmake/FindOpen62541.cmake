# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

#.rst:
# FindOpen62541
# ---------
#
# Try to locate the open62541 library.
# If found, this will define the following variables:
#
# ``Open62541_FOUND``
#     True if the open62541 library is available
# ``Open62541_INCLUDE_DIRS``
#     The open62541 include directories
# ``Open62541_LIBRARIES``
#     The open62541 libraries for linking
#
# If ``Open62541_FOUND`` is TRUE, it will also define the following
# imported target:
#
# ``open62541``
#     The open62541 library

# first try to find the official open62541 CMake config files
find_package(open62541 NO_MODULE QUIET)
set(Open62541_FOUND ${open62541_FOUND})

if (NOT TARGET open62541::open62541)
    find_path(Open62541_INCLUDE_DIRS
        NAMES open62541.h
        HINTS "${OPEN62541_INCDIR}")

    find_library(Open62541_LIBRARIES
        NAMES open62541
        HINTS "${OPEN62541_LIBDIR}")
    mark_as_advanced(Open62541_INCLUDE_DIRS Open62541_LIBRARIES)
else()
  get_property(Open62541_INCLUDE_DIRS TARGET open62541::open62541 PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
  set(Open62541_LIBRARIES open62541::open62541)
endif()

if (NOT Open62541_FOUND AND NOT Open62541_INCLUDE_DIRS STREQUAL "Open62541_INCLUDE_DIRS-NOTFOUND" AND NOT Open62541_LIBRARIES STREQUAL "Open62541_LIBRARIES-NOTFOUND")
    set(Open62541_FOUND ON)
endif()

if (Open62541_FOUND)
    if(NOT TARGET open62541::open62541)
        add_library(open62541 UNKNOWN IMPORTED)
        set_target_properties(open62541 PROPERTIES
            IMPORTED_LOCATION "${Open62541_LIBRARIES}"
            INTERFACE_INCLUDE_DIRECTORIES "${Open62541_INCLUDE_DIRS}")

        if (WIN32)
            set_property(TARGET open62541 APPEND PROPERTY
                INTERFACE_LINK_LIBRARIES ws2_32)
        endif()
    else()
        add_library(open62541 ALIAS open62541::open62541)
    endif()
endif()


include(FeatureSummary)
set_package_properties(Open62541 PROPERTIES
    URL "https://open62541.org"
    DESCRIPTION "Open62541 OPC UA library")
