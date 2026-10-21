cmake_minimum_required(VERSION 3.28)
project(tutorial C)

set(CMAKE_C_STANDARD 23)

# 定义 PROJECT_SOURCES 是 src/ 下所有 .c 文件
file(GLOB_RECURSE PROJECT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/src/*.c
)

# 定义 PROJECT_INCLUDE 是 include/
set(PROJECT_INCLUDE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

# 添加目标 hello，源文件是 PROJECT_SOURCES
add_executable(hello
        ${PROJECT_SOURCES}
)

# 为 hello 添加头文件路径为 PROJECT_INCLUDE
target_include_directories(hello
        PRIVATE ${PROJECT_INCLUDE}
)
