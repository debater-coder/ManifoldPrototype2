#pragma once

#include "imgui.h"
// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace Manifold {
	class Gui {
	public:
		bool demo_window_open;

		Gui();
		void DrawGui();
		
		
	};
}