add_library(calculator STATIC calculator.cpp)

target_link_libraries(calculator PUBLIC add)

target_include_directories(calculator INTERFACE ./)
