#pragma once
#include "IconsFontAwesome5.h"
#include "imgui.h"
// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace Manifold {
	class Gui {
	public:
		bool demo_window_open;
		bool main_window_open;

		Gui();
		void DrawGui(ImGuiIO& io);
		void ShowMainWindow(bool* main_window_open, ImGuiIO& io);
		
	};
}