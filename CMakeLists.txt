
cmake_minimum_required (VERSION 3.15)

project ("task5_shaked_vaknin")

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

add_executable (task5_shaked_vaknin)

add_subdirectory (include)
add_subdirectory (src)

target_sources(task5_shaked_vaknin
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Dog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/PriorityQueue.cpp
    )
