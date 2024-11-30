# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和语言
project(Test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项（可选）
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# 包含头文件目录
include_directories(../Base ../Layers)

# 添加源文件
file(GLOB BASE_SOURCES ../Base/*.cpp)  # Base 目录下的源文件
file(GLOB LAYERS_SOURCES ../Layers/*.cpp)  # Layers 目录下的源文件
file(GLOB TEST_SOURCES ../Test/main.cpp)  # Test 目录下的主文件

# 合并所有源文件
list(APPEND SOURCES ${BASE_SOURCES} ${LAYERS_SOURCES} ${TEST_SOURCES})

# 定义可执行文件
add_executable(Test ${SOURCES})

# 如果有需要链接的库，可以通过 target_link_libraries 来指定
# target_link_libraries(MyProject PRIVATE <library_name>)
