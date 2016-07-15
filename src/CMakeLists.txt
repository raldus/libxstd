
set(Library_SOURCES xstd.cpp settings.cpp filename.cpp fileinfo.cpp directory.cpp datetime.cpp)
###file(GLOB Library_SOURCES *.cpp)

add_library(xstd        SHARED ${Library_SOURCES})
add_library(xstd-static STATIC ${Library_SOURCES})


set_property(TARGET xstd        PROPERTY SOVERSION ${PACKAGE_VERSION})
set_property(TARGET xstd-static PROPERTY SOVERSION ${PACKAGE_VERSION})


file(GLOB files "${PROJECT_SOURCE_DIR}/src/*.h")
install(FILES ${files} DESTINATION include/xstd)
# install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/" DESTINATION include/xstd
#         FILES_MATCHING PATTERN "*.h")
install(
    TARGETS xstd-static xstd
    LIBRARY DESTINATION lib${LIB_SUFFIX}
    ARCHIVE DESTINATION lib${LIB_SUFFIX}
)

add_subdirectory(examples)

