// Dear ImGui: standalone example application for GLFW + BGFX, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// (BGFX is a corss-platfrom general purpose rendering library with multiple backends like OpenGL, Vulkan, Metal, Gnm etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include <big2.h>

#if BIG2_IMGUI_ENABLED
#include <imgui.h>
#endif // BIG2_IMGUI_ENABLED

#include <iostream>

#include <bgfx/bgfx.h>
#include <bx/bx.h>

#include <GLFW/glfw3.h>

int main(std::int32_t, gsl::zstring[]) {
  big2::GlfwInitializationScoped _glfw;
  big2::BgfxInitializationScoped _bgfx;

  big2::Window window("Dear ImGui GLFW+BGFX example", {1280, 720});

  glm::ivec2 window_resolution = big2::GetWindowResolution(window);

#if BIG2_IMGUI_ENABLED
  big2::ImGuiContextWrapper context;

  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
  context.Initialize(window, window.GetView(), /*use_default_callbacks=*/ true);

  ImGui::StyleColorsDark();
#endif // BIG2_IMGUI_ENABLED

  big2::GlfwEventQueue::Initialize();
  while (!glfwWindowShouldClose(window)) {
    big2::GlfwEventQueue::PollEvents();
    const glm::ivec2 new_window_size = window.GetResolution();
    if (new_window_size != window_resolution) {
      window.SetFrameSize(new_window_size);
      window_resolution = new_window_size;
    }

    bgfx::touch(window.GetView());

#if BIG2_IMGUI_ENABLED
    big2::GlfwEventQueue::UpdateImGuiEvents(window);
    BIG2_SCOPE_VAR(big2::ImGuiFrameScoped) {
      ImGui::ShowDemoWindow();
    }
#endif // BIG2_IMGUI_ENABLED

    bgfx::frame();
  }

  return 0;
}
