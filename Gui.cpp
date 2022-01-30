#include "Gui.h"

Manifold::Gui::Gui()
{
	demo_window_open = false;
	main_window_open = true;
}

void Manifold::Gui::DrawGui(ImGuiIO& IO)
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File")) 
        {
            if (ImGui::MenuItem("Exit", "Alt+F4")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) 
        {
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("View")) 
        {
            if (ImGui::MenuItem("Main Window"))
                main_window_open = true;
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help")) 
        {
            if (ImGui::MenuItem("Show Demo"))
                demo_window_open = true;

            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

	if (demo_window_open)
		ImGui::ShowDemoWindow(&demo_window_open);
    if (main_window_open)
        ShowMainWindow(&main_window_open, IO);
}

void Manifold::Gui::ShowMainWindow(bool* main_window_open, ImGuiIO& io)
{
    ImGui::Begin(ICON_FA_HOME " Main window", main_window_open);
    ImGui::Text(ICON_FA_EXCLAMATION_TRIANGLE" Math in Open Sans: ∀(x, y ∈ A ∪ B; x ≠ y) x² − y² ≥ 0");
    ImGui::PushFont(io.Fonts->Fonts[1]);
    ImGui::Text(ICON_FA_EXCLAMATION_TRIANGLE" Math in Noto Sans Math: ∀(x, y ∈ A ∪ B; x ≠ y) x² − y² ≥ 0");
    ImGui::PopFont();
    ImGui::End();
}

