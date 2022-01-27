#include "App.h"

Manifold::App::App()
{
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

    while (glfwWindowShouldClose(window) == false) 
    {
        // Background Fill Color
        glClearColor(0.082, 0.086, 0.09, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        Update();

        // Flip Buffers and Draw
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

void Manifold::App::Update()
{

}