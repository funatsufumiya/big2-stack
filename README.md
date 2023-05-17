# BIG<sup>2</sup> Stack

[![CMake](https://github.com/Paper-Cranes-Ltd/big2-stack/actions/workflows/cmake.yml/badge.svg)](https://github.com/Paper-Cranes-Ltd/big2-stack/actions/workflows/cmake.yml)
[![License - The Unlicense](https://badgen.net/badge/License/The%20Unlicense/)](https://github.com/Paper-Cranes-Ltd/big2-stack/blob/main/LICENSE)


[![Buy me a coffee](https://badgen.net/badge/Buy%20me/a%20coffee/FF6600)](https://www.buymeacoffee.com/object71)

This is a middleware repository that eases up the work with [BGFX](https://github.com/bkaradzic/bgfx), [GLFW](https://github.com/glfw/glfw), [IMGUI](https://github.com/ocornut/imgui) and [GLM](https://github.com/g-truc/glm).
It is more or less inspired by other repositories like [bigg](https://github.com/JoshuaBrookover/bigg) or [bigger](https://github.com/yuki-koyama/bigger). The general idea is to have a setup that is easy to work with and is easy to have cross-platform. This project is based on CMake since this is my favourite and is also the most popular project management tool and you can easily include it in your own project as a subdirectory or using fetch content.

## Usage

You can check the intro article on [my blog](https://thatonegamedev.com/cpp/the-big2-stack/) but in general to use this in your cmake project you could clone it to a subdirectory or use fetch content:

```cmake
include(FetchContent)

fetchcontent_declare(
        big2
        GIT_REPOSITORY "https://github.com/Paper-Cranes-Ltd/big2-stack.git"
        GIT_TAG "v0.1.12"
        GIT_SHALLOW TRUE
)

fetchcontent_makeavailable(big2)

# ...

add_executable(Main main.cpp)
target_link_libraries(Main PUBLIC big2)
```

## Dependencies

This project depends on a few other projects:

- [Microsoft.GSL](https://github.com/microsoft/GSL)
- [bgfx.cmake](https://github.com/bkaradzic/bgfx)
- [glfw3](https://github.com/glfw/glfw)
- [glm](https://github.com/g-truc/glm)
- [Dear ImGui](https://github.com/ocornut/imgui) *(optional)*
