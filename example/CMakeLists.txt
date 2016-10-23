
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/example)
add_executable(example example.cpp)
target_link_libraries(example LINK_PUBLIC mesh)
