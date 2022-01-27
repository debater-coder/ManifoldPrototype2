#include "Gui.h"

Manifold::Gui::Gui()
{
	demo_window_open = true;
}

void Manifold::Gui::DrawGui()
{
	if (demo_window_open)
		ImGui::ShowDemoWindow(&demo_window_open);
}
