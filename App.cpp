#include "App.h"

Manifold::App::App()
{
    // Initialize ImGUI IO
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO(); (void)io;
    
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

    glViewport(0, 0, window_width, window_height);

    InitGUI(window);

    while (glfwWindowShouldClose(window) == false) 
    {
        Update(window);
    }
    glfwTerminate();
    return 0;
}

void Manifold::App::Update(GLFWwindow* window)
{
    // Background Fill Color
    glClearColor(0.082f, 0.086f, 0.09f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Tell OpenGL a new frame is about to begin
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    DrawFrame();
    DrawGUI();

    // Renders the ImGUI elements
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Flip Buffers and Draw
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Manifold::App::InitGUI(GLFWwindow* window)
{
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void Manifold::App::DrawFrame()
{

}

void Manifold::App::DrawGUI() {
    // ImGUI window creation
    ImGui::Begin("My name is window, ImGUI window");
    // Text that appears in the window
    ImGui::Text("Hello there adventurer!");
    // Ends the window
    ImGui::End();
    ImGui::ShowDemoWindow();
}