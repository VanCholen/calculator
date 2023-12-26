// #include "common.h"

// #include "add.h"

#include <spdlog/spdlog.h>
#include <fmt/core.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "calculator.h"

cv::Mat RotateImage(cv::Mat src, double angle)
{
    cv::Mat dst;
    try
    {
        // float scale = 200.0/ src.rows;//缩放因子
        // cv::resize(src, src, cv::Size(), scale, scale, cv::INTER_LINEAR);
        // 输出图像的尺寸与原图一样
        cv::Size dst_sz(src.cols, src.rows);

        // 指定旋转中心
        cv::Point2f center(static_cast<float>(src.cols / 2.), static_cast<float>(src.rows / 2.));

        // 获取旋转矩阵（2x3矩阵）
        cv::Mat rot_mat = cv::getRotationMatrix2D(center, angle, 1.0);
        // 设置选择背景边界颜色
        /*cv::Scalar borderColor = Scalar(0, 238, 0);*/
        /*cv::warpAffine(src, dst, rot_mat, src.size(), INTER_LINEAR, BORDER_CONSTANT, borderColor);*/
        // 复制边缘填充
        cv::warpAffine(src, dst, rot_mat, dst_sz, cv::INTER_LINEAR, cv::BORDER_REPLICATE);
    }
    catch (cv::Exception e)
    {
    }

    return dst;
}



int main(int argc, char *argv[])
{
    // add(1, 3);
    Calculator calc;
    calc.calcAdd(1, 2);
    // 初始化 spdlog
    spdlog::info("Hello, spdlog!");
    fmt::print("hello,world\n");

    auto j = json::parse(R"({"happy": true, "pi": 3.141})");
    spdlog::info(j.dump(4));

    cv::Mat src = cv::imread("./resource/cat.jpg");
    cv::namedWindow("src", cv::WINDOW_AUTOSIZE);
    cv::imshow("src", src);

    auto dst = RotateImage(src, 90);
    cv::namedWindow("dst", cv::WINDOW_AUTOSIZE);
    cv::imshow("rotated", dst);

    cv::waitKey();
    cv::destroyAllWindows();
    return 0;
}