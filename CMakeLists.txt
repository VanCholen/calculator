cmake_minimum_required(VERSION 3.12)
add_definitions(-std=c++2a) # 指定采用c++20进行编译（spdlog需要c++11）

add_subdirectory(common)
add_subdirectory(add)
add_subdirectory(calculator)

# 源码引入 第三方库
add_subdirectory(external/spdlog)

add_subdirectory(external/fmt)


# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")
# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory(external/nlohmann_json)

# 3rdparty  opencv 4.8.0  mac-arm
find_package(OpenCV REQUIRED 
			PATHS ./3rdparty/opencv480/darwin-arm64
			NO_DEFAULT_PATH)


add_executable(main main.cpp)

# 将生成的二进制文件放置在当前源代码目录下的bin目录中
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)


target_link_libraries(main PRIVATE calculator)
target_link_libraries(main PRIVATE spdlog::spdlog)
target_link_libraries(main PRIVATE fmt::fmt)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

target_link_libraries(main PRIVATE ${OpenCV_LIBS})


