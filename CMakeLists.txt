cmake_minimum_required(VERSION 3.5.0)
project(Pong VERSION 0.1.0 LANGUAGES C CXX)

link_directories(vendor/SFML/lib)
include_directories(vendor/SFML/include source/include)

set(SRC_FILES 
                source/main.cpp
                source/Ball.cpp
                source/Paddle.cpp
                source/Game.cpp)

add_executable(Pong ${SRC_FILES})

target_link_libraries(Pong PUBLIC sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/vendor/SFML/bin $<TARGET_FILE_DIR:Pong>)

    add_custom_command(TARGET Pong POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resource $<TARGET_FILE_DIR:Pong>/resource)