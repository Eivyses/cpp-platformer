cmake_minimum_required (VERSION 3.8)

project("cpp_platformer_template")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libs/asciilibur)

add_executable(cpp_platformer "main.cpp" "domain/Movable.cpp" "domain/Player.cpp" "domain/Boundaries.cpp" "domain/Level1.cpp" "domain/Level.cpp")
target_link_libraries(cpp_platformer asciilibur)

