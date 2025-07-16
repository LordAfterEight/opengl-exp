#include <iostream>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "helpers/helpers.h"
using namespace std;

int main() {
    GLFWwindow* win = init_window(800, 600, "UwU", nullptr, nullptr);

	glClearColor(.1F, .1F, .1F, 1.0F);

	while (!glfwWindowShouldClose(win)) {
		glClear(GL_COLOR_BUFFER_BIT);

        process_input(win);

		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();

}
