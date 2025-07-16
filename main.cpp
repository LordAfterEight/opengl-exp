#include <iostream>
#include <cmath>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include "helpers/helpers.h"
#include "helpers/shaders.h"
#include "helpers/objects.h"
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
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        process_input(win);

        glUseProgram(shaderProgram);
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "custom_color");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(VAO);


        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwDestroyWindow(win);
	glfwTerminate();

}
