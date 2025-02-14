cmake_minimum_required(VERSION 3.5.0)
project(Pong VERSION 0.1.0 LANGUAGES C CXX)

link_directories(vendor/SFML/lib)
include_directories(vendor/SFML/include source/include)



add_executable(Pong source/main.cpp)
target_link_libraries(Pong PUBLIC sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/vendor/SFML/bin $<TARGET_FILE_DIR:Pong>)