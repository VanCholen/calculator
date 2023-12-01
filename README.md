# 示例在项目中引入第三方库spdlog
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

