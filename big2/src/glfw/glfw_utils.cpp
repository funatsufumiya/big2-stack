//
// Copyright (c) 2023 Paper Cranes Ltd.
// All rights reserved.
//

#include <big2/glfw/glfw_utils.h>
#include <GLFW/glfw3.h>
#include <bx/bx.h>
#include <native_window.h>
#include <spdlog/spdlog.h>
#include <big2/macro_utils.h>

namespace big2 {

gsl::span<GLFWmonitor *> GetMonitors() {
  std::int32_t count;
  GLFWmonitor **monitors = glfwGetMonitors(&count);
  return {monitors, static_cast<std::size_t>(count)};
}

glm::ivec2 GetMonitorResolution(gsl::not_null<GLFWmonitor *> monitor) {
  const GLFWvidmode *mode = glfwGetVideoMode(monitor);
  return {mode->width, mode->height};
}

glm::ivec2 GetMonitorPosition(gsl::not_null<GLFWmonitor *> monitor) {
  glm::ivec2 position;
  glfwGetMonitorPos(monitor, &position.x, &position.y);
  return position;
}

std::int32_t GetMonitorRefreshRate(gsl::not_null<GLFWmonitor *> monitor) {
  const GLFWvidmode *mode = glfwGetVideoMode(monitor);
  return mode->refreshRate;
}

glm::ivec2 GetWindowSize(gsl::not_null<GLFWwindow *> window) {
  glm::ivec2 window_size;
  glfwGetWindowSize(window, &window_size.x, &window_size.y);
  return window_size;
}

void *GetNativeWindowHandle(gsl::not_null<GLFWwindow *> window) {
#if BX_PLATFORM_LINUX
  return reinterpret_cast<void *>(glfwGetX11Window(window));
#elif BX_PLATFORM_OSX
  return glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
  return glfwGetWin32Window(window);
#else
  return nullptr;
#endif
}

void GlfwErrorCallback(std::int32_t error, gsl::czstring description) {
  spdlog::error("GLFW error({0}): {1}", error, description);
}

GlfwInitializationScoped::GlfwInitializationScoped() {
  if (is_initialized_) {
    bigWarning("GLFW is initialized twice");
    return;
  }

  glfwSetErrorCallback(GlfwErrorCallback);

  is_initialized_ = glfwInit() == GLFW_TRUE;
  bigValidate(is_initialized_, "Couldn't initialize GLFW");
}

GlfwInitializationScoped::~GlfwInitializationScoped() {
  if(!is_initialized_) {
    bigWarning("GLFW is uninitialized twice");
    return;
  }

  glfwTerminate();
  is_initialized_ = false;
}

}
