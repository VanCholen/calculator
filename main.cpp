// #include "common.h"

// #include "add.h"

#include <spdlog/spdlog.h>
#include <fmt/core.h>
#include "calculator.h"

int main(int argc, char *argv[])
{
    // add(1, 3);
    Calculator calc;
    calc.calcAdd(1, 2);
    // 初始化 spdlog
    spdlog::info("Hello, spdlog!");
    fmt::print("hello,world\n");
    return 0;
}