// System Headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard Headers
#include <cstdio>
#include <cstdlib>
#include <iostream>
int window_width = 1200;
int window_height = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(int argc, char* argv[]) {

    // Load GLFW and Create a Window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(window_width, window_height, "Manifold Prototype 2", nullptr, nullptr);

    // Check for Valid Context
    if (window == nullptr) {
        fprintf(stderr, "Failed to Create GLFW window");
        return EXIT_FAILURE;
    }

    // Create Context and Load OpenGL Functions
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    fprintf(stderr, "OpenGL %s\n", glGetString(GL_VERSION));

    glViewport(0, 0, 800, 1200);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Rendering Loop
    while (glfwWindowShouldClose(window) == false) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // Background Fill Color
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Flip Buffers and Draw
        glfwSwapBuffers(window);
        glfwPollEvents();
    }   
    
    glfwTerminate();
    return EXIT_SUCCESS;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    window_width, window_height = width, height;
}