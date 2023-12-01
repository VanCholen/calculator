cmake_minimum_required(VERSION 3.12)
add_definitions(-std=c++2a) # 指定采用c++20进行编译（spdlog需要c++11）

add_subdirectory(common)
add_subdirectory(add)
add_subdirectory(calculator)

# 第三方库
add_subdirectory(external/spdlog)
add_subdirectory(external/fmt)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE calculator)
target_link_libraries(main PRIVATE spdlog::spdlog)
target_link_libraries(main PRIVATE fmt::fmt)