#include <iostream>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <math.h>

#define ENABLE_FULLSCREEN 0
#define RESIZABLE 0
#define VSYNC 0

GLFWwindow* window;
GLFWmonitor* monitor;
unsigned int WIDTH = 1000;
unsigned int HEIGHT = 1000;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {

    // Greet on the terminal
    std::cout << "Hello, RTSkippy!" << std::endl;

    // Init GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Setup GLFW
    glfwWindowHint(GLFW_RESIZABLE, RESIZABLE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Setup Monitor to Primary
    monitor = glfwGetPrimaryMonitor();

    // Handle case where we want to render at the maximum monitor resolution aka Fullscreen :-)
    if (ENABLE_FULLSCREEN) {
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        WIDTH = mode->width;
        HEIGHT = mode->height;
    }
    std::cout << "Using Window Size : " << WIDTH << " x " << HEIGHT << std::endl;

    // Create GLFW Window
    window = glfwCreateWindow(WIDTH, HEIGHT, "RTSkippy", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to open window GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Init Vulkan

    // Display used Vulkan Version
    // std::cout << glGetString(GL_VERSION) << std::endl;
	return 0;
}
