


add_executable(datetime datetime.cpp)
add_dependencies(datetime xstd)
target_link_libraries(datetime libxstd.so)

add_executable(directory directory.cpp)
add_dependencies(directory xstd)
target_link_libraries(directory libxstd.so)

add_executable(fileinfo fileinfo.cpp)
add_dependencies(fileinfo xstd)
target_link_libraries(fileinfo libxstd.so)

add_executable(filename filename.cpp)
add_dependencies(filename xstd)
target_link_libraries(filename libxstd.so)


