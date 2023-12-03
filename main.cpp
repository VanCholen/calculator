// #include "common.h"

// #include "add.h"

#include <spdlog/spdlog.h>
#include <fmt/core.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "calculator.h"

int main(int argc, char *argv[])
{
    // add(1, 3);
    Calculator calc;
    calc.calcAdd(1, 2);
    // 初始化 spdlog
    spdlog::info("Hello, spdlog!");
    fmt::print("hello,world\n");

    cv::Mat img = cv::imread("/Users/cholen/Downloads/cat.jpg");
    cv::namedWindow("test", cv::WINDOW_AUTOSIZE);
    cv::imshow("test", img);
    cv::waitKey();
    return 0;
}