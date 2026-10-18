cmake_minimum_required(VERSION 4.3.1 )
project(raylibtestgame)

set_property(GLOBAL PROPERTY USE_FOLDERS OFF)
set(CMAKE_SUPPRESS_REGENERATION ON)

set(CMAKE_CXX_STANDARD 20)

add_executable(raylibtestgame src/main.cpp
        src/assetManager.cpp
        src/assetManager.h
        src/gravity.cpp
        src/gravity.h)

target_include_directories(raylibtestgame PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)
target_link_directories(raylibtestgame PRIVATE ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(raylibtestgame raylibdll winmm)

set(OUT_DIR ${CMAKE_BINARY_DIR}/raylibtestgame)
set_target_properties(raylibtestgame PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<1:${OUT_DIR}>)

add_custom_command(TARGET raylibtestgame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/assets
        $<TARGET_FILE_DIR:raylibtestgame>/assets)

add_custom_command(TARGET raylibtestgame POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/lib/raylib.dll
        $<TARGET_FILE_DIR:raylibtestgame>)