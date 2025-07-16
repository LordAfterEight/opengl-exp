#include <iostream>
#include <cmath>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "helpers/helpers.h"
#include "helpers/shaders.h"
#include "helpers/objects.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

const float WINDOW_SCALING = 0.5;
const int WINDOW_WIDTH = 1920 * WINDOW_SCALING;
const int WINDOW_HEIGHT = 1080 * WINDOW_SCALING;

int main() {
    GLFWwindow* win = init_window(WINDOW_WIDTH, WINDOW_HEIGHT, "UwU", nullptr, nullptr);

	glClearColor(.0F, .0F, .0F, 1.0F);

    unsigned int shaderProgram = setup_shaders();
    unsigned int VAO = build_vertices();

    bool wireframe = false;

    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

	while (!glfwWindowShouldClose(win)) {
		glClear(GL_COLOR_BUFFER_BIT);
        if (wireframe) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }

        process_input(win);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();

}
