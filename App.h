#pragma once

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
		int window_width = 1200;
		int window_height = 800;
	public:
		App();

		int Init();
		void Update();
	};


}