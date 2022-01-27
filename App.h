#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>


namespace Manifold 
{
	class App
	{
		public:
			int window_width;
			int window_height;
			ImGuiIO* io;

			App();

			int Init();
			void Update(GLFWwindow* window);
			void InitGUI(GLFWwindow* window);
			void DrawFrame();
			void DrawGUI();
	};


}