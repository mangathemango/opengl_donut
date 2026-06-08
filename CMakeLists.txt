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

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/include/*")
foreach(DIR ${INCLUDE_DIRS})
    if(IS_DIRECTORY ${DIR})
    include_directories(${DIR})
    endif()
endforeach()

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