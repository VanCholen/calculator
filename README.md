# 把第三方源码和本项目源码一起编译-示例在项目中引入第三方库spdlog
```bash
git submodule add https://github.com/gabime/spdlog.git external/spdlog
git submodule update --init --recursive
cd external/spdlog
git tag         # 查看有哪些版本
git checkout v1.12.0   # 切换你要使用的spdlog的版本
```

然后在项目CMakeLists.txt中，哪个目标要用到spdlog就添加spdlog
```cmake
add_subdirectory(external/spdlog)
target_link_libraries(main PRIVATE spdlog::spdlog)
```


# 把第三方源码单独编译，编译好的库放置于3rdparty——以opencv+opencv_contrib举例
```bash
git submodule add https://github.com/opencv/opencv.git external/opencv
git submodule add https://github.com/opencv/opencv_contrib.git external/opencv_contrib
git submodule update --init --recursive

cd external/opencv
git tag         # 查看有哪些版本
git checkout 4.8.0   # 切换你要使用opencv的版本
cd ../opencv_contrib
git tag         # 查看有哪些版本
git checkout 4.8.0 # 切换你要使用opencv_contrib的版本(注意⚠️要和opencv保持一致)

cd ../opencv
mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Release -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -DCMAKE_INSTALL_PREFIX=../../../3rdparty/opencv480/darwin-arm64 .. 
#################################################################
# CMAKE_BUILD_TYPE 指定Release模式
# OPENCV_EXTRA_MODULES_PATH 指定opencv_contrib的目录下的modules目录
# CMAKE_INSTALL_PREFIX指定安装目录
#################################################################

make -j16
make install 

cd ../
rm -rf build    # 完成编译后build目录就可以删掉了

```

# 3rdparty/opencv480/windows-amd64目录下所有文件的来源
从官网直接下载，然后把build目录下的所有文件拷贝至此。

由于git的限制，我将3rdparty/opencv480/windows-amd64/x64/vc16/bin下的**opencv_world480.pdb**、
**opencv_world480d.dll**、**opencv_world480d.pdb**删除了，因此在Windows下选择
编译工具链时不能使用debug模式，如果需要使用，请自行添加这三个文件。

- 将编译工具链选择为msvc的编译器 ==> cmake select kit
- 3rdparty/opencv480/windows-amd64/x64/vc16/bin下的**opencv_world480.dll**这个动态库拷贝到本项目生成的可执行文件下，以便能够顺利执行。


# Version
fmt 10.1.1

spdlog v1.12.0

poco poco-1.11.3-release

opencv 4.8.0

opencv_contrib 4.80

nlohmann_json v3.11.3
