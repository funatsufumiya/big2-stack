//
// Copyright (c) 2023 Paper Cranes Ltd.
// All rights reserved.
//

#ifndef BIG2_STACK_BIG2_GLFW_UTILS_H_
#define BIG2_STACK_BIG2_GLFW_UTILS_H_

#include <gsl/span>
#include <bgfx/bgfx.h>
#include <glm/glm.hpp>

struct GLFWwindow;
struct GLFWmonitor;

namespace big2
{
void SetNativeWindowData(bgfx::Init &init_obj, GLFWwindow *window);

[[nodiscard]] gsl::span<GLFWmonitor*> GetMonitors();
[[nodiscard]] glm::ivec2 GetMonitorResolution(GLFWmonitor* monitor);
[[nodiscard]] glm::ivec2 GetMonitorPosition(GLFWmonitor* monitor);
[[nodiscard]] std::int32_t GetMonitorRefreshRate(GLFWmonitor* monitor);

}

#endif //BIG2_STACK_BIG2_GLFW_UTILS_H_
