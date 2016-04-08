
set(Library_SOURCES xstd.cpp settings.cpp filename.cpp fileinfo.cpp directory.cpp datetime.cpp)
###file(GLOB Library_SOURCES *.cpp)

add_library(xstd        SHARED ${Library_SOURCES})
add_library(xstd-static STATIC ${Library_SOURCES})


 # Help CMake 2.6.x and lower (not necessary for 2.8 and above, but doesn't hurt):
set_target_properties(xstd        PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(xstd-static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

set_target_properties(xstd-static PROPERTIES OUTPUT_NAME "xstd")
#xstd-static(foo-static PROPERTIES PREFIX "lib")



file(GLOB files "${PROJECT_SOURCE_DIR}/src/*.h")
install(FILES ${files} DESTINATION include/xstd)
install(
    TARGETS xstd-static xstd
    LIBRARY DESTINATION lib${LIB_SUFFIX}
    ARCHIVE DESTINATION lib${LIB_SUFFIX}
)

add_subdirectory(examples)

