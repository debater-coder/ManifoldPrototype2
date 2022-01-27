#include "Gui.h"

Manifold::Gui::Gui()
{
	demo_window_open = true;
}

void Manifold::Gui::DrawGui()
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File")) 
        {
            if (ImGui::MenuItem("Exit", "Alt+F4")) 
            {
                
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) 
        {
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

	if (demo_window_open)
		ImGui::ShowDemoWindow(&demo_window_open);
}
