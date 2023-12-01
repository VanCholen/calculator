add_library(add STATIC add.cpp)

target_link_libraries(add PUBLIC common)

target_include_directories(add INTERFACE ./)