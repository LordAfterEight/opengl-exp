#include <iostream>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow *init_window(int width, int height, const char *title, GLFWmonitor* monitor, GLFWwindow* window) {
    if (glfwInit() == -1) {
		std::cerr << "Failed to initialize GLFW.\n";
		return 0;
	}

	auto* win = glfwCreateWindow(width, height, title, monitor, window);

	if (win == nullptr) {
		std::cerr << "Failed to create a window.\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(win);

	if (gladLoadGL() == -1) {
		std::cerr << "Failed to initlaize GLAD.\n";
		glfwDestroyWindow(win);
		glfwTerminate();
	}

	glClearColor(.0F, .1F, .1F, 1.0F);
    return win;
}