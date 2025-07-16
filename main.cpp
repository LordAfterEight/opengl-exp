#include <iostream>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "helpers/helpers.h"
#include "helpers/shaders.h"
using namespace std;

const float WINDOW_SCALING = 0.5;
const int WINDOW_WIDTH = 1920 * WINDOW_SCALING;
const int WINDOW_HEIGHT = 1080 * WINDOW_SCALING;

int main() {
    GLFWwindow* win = init_window(WINDOW_WIDTH, WINDOW_HEIGHT, "UwU", nullptr, nullptr);

	glClearColor(.1F, .1F, .1F, 1.0F);

    setup_shaders();

	while (!glfwWindowShouldClose(win)) {
		glClear(GL_COLOR_BUFFER_BIT);

        process_input(win);

		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();

}
