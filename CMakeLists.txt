cmake_minimum_required(VERSION 3.12)
add_definitions(-std=c++2a) # 指定采用c++20进行编译（spdlog需要c++11）

add_subdirectory(common)
add_subdirectory(add)
add_subdirectory(calculator)

# 源码引入 第三方库
add_subdirectory(external/spdlog)
add_subdirectory(external/fmt)


# 3rdparty  opencv 4.8.0  mac-arm
find_package(OpenCV REQUIRED 
			PATHS ./3rdparty/opencv480/mac-arm 
			NO_DEFAULT_PATH)


add_executable(main main.cpp)


target_link_libraries(main PRIVATE calculator)
target_link_libraries(main PRIVATE spdlog::spdlog)
target_link_libraries(main PRIVATE fmt::fmt)

target_link_libraries(main PRIVATE ${OpenCV_LIBS})


