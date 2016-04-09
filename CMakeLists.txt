cmake_minimum_required(VERSION 2.6)

project (XSTD CXX)

set(PACKAGE_NAME  "libxstd")
exec_program(git ARGS describe --abbrev=0 --tags OUTPUT_VARIABLE PACKAGE_VERSION)
set(PACKAGE_VERSION "${PACKAGE_VERSION}" CACHE STRING "Package Version")


set(CMAKE_BINARY_DIR      "${CMAKE_SOURCE_DIR}/bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH    ${CMAKE_BINARY_DIR})


# C++ version
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. \
                    Please use a different C++ compiler.")
endif()

# C++ flags
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")


IF (${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND
    ${CMAKE_SIZEOF_VOID_P} EQUAL "8")
  SET(LIB_SUFFIX "64")
ENDIF()
#set(LIB_SUFFIX "" CACHE STRING "Define suffix of library directory name (32/64)")


# doxygen target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file("${CMAKE_SOURCE_DIR}/files/doxyfile.in" "${CMAKE_SOURCE_DIR}/build/doxyfile" @ONLY)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} "${CMAKE_SOURCE_DIR}/build/doxyfile"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)


# uninstall target
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/build/CMakeModules)
configure_file(
    "${CMAKE_SOURCE_DIR}/files/uninstall.in"
    "${CMAKE_SOURCE_DIR}/build/uninstall"
    IMMEDIATE @ONLY)
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/build/uninstall)

######cat install_manifest.txt | xargs echo rm | sh


# cache-variables
# set(CACHE_VAR_CHECK CACHE STRING TestString)

link_directories("${LIBRARY_OUTPUT_PATH}")

include_directories("${PROJECT_SOURCE_DIR}/src")

add_subdirectory(src)

# output
message("--- Info ---")
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
