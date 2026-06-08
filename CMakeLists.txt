cmake_minimum_required(VERSION 3.20)

project(opengl-donut LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)


file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

message(STATUS "Sources: ${SOURCES}")

add_executable(opengl-donut 
    ${SOURCES}
)

target_include_directories(opengl-donut PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)

target_link_directories(opengl-donut PRIVATE 
    lib/lib-mingw-w64
) 

target_link_libraries(opengl-donut PRIVATE 
    glfw3 
    opengl32 
    gdi32 
)
target_link_libraries(opengl-donut PRIVATE
    OpenGL::GL
)