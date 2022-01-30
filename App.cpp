#include "App.h"

namespace Manifold {
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}

Manifold::App::App()
{   
    window_width = 1200;
    window_height = 800;
}

int Manifold::App::Init()
{
    // Load GLFW and Create a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, true);
    
    //glfwWindowHint(GLFW_DECORATED, false);
    

    auto window = glfwCreateWindow(window_width, window_height, "Manifold Prototype 2", nullptr, nullptr);

    // Check for Valid Context
    if (window == nullptr) {
        fprintf(stderr, "Failed to Create GLFW window");
        return -1;
    }

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialise GLAD");
        return -1;
    }

    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glViewport(0, 0, window_width, window_height);

    ImGuiIO io = InitGUI(window);
    Gui gui = Gui();

    while (glfwWindowShouldClose(window) == false) 
    {
        Update(window, io, gui);
    }
    glfwTerminate();
    return 0;
}

void Manifold::App::Update(GLFWwindow* window, ImGuiIO io, Gui& gui)
{
    // Background Fill Color
    glClearColor(0.082f, 0.086f, 0.09f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Tell OpenGL a new frame is about to begin
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    DrawFrame();

    gui.DrawGui(io);
    // Renders the ImGUI elements
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Flip Buffers and Draw
    glfwSwapBuffers(window);
    glfwPollEvents();
}

ImGuiIO Manifold::App::InitGUI(GLFWwindow* window)
{
    // Initialize ImGUI IO
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    io.Fonts->AddFontFromFileTTF("OpenSans-Regular.ttf", 16);
    // merge in icons from Font Awesome
    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
    ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
    io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, 16.0f, &icons_config, icons_ranges);
    
    ImVector<ImWchar> ranges;
    ImFontGlyphRangesBuilder builder;
    builder.AddText("∀(x, y ∈ A ∪ B; x ≠ y) x² − y² ≥ 0");                        // Add a string (here "Hello world" contains 7 unique characters)
    builder.AddRanges(io.Fonts->GetGlyphRangesDefault()); // Add one of the default ranges
    builder.BuildRanges(&ranges);                          // Build the final result (ordered ranges with all the unique characters submitted)

    ImFont* mathFont = io.Fonts->AddFontFromFileTTF("NotoSansMath-Regular.ttf", 16, NULL, ranges.Data);
    io.Fonts->Build();

    ImGui::GetStyle().WindowRounding = 4.0f;
    ImGui::GetStyle().ChildRounding = 4.0f;
    ImGui::GetStyle().FrameRounding = 4.0f;
    ImGui::GetStyle().GrabRounding = 4.0f;
    ImGui::GetStyle().PopupRounding = 4.0f;
    ImGui::GetStyle().ScrollbarRounding = 4.0f;

    return io;
}

void Manifold::App::DrawFrame()
{

}
