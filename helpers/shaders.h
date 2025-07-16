#include <iostream>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

const char *vertexShaderSource = 
    "#version 460 core\n"
    "layout (location = 0) in vec3 a_pos;\n"
    "layout (location = 1) in vec3 a_col;\n"
    "out vec3 color;\n"
    "void main() {\n"
    "   gl_Position = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0);\n"
    "   color = a_col;\n"
    "}\0";

const char *fragmentShaderSource =
    "#version 460 core \n"
    "out vec4 FragColor;\n"
    "uniform vec4 custom_color;\n"
    "in vec3 color;"
    "void main() { \n"
    "   FragColor = vec4(color, 1.0);"
    "}\0";

int setup_shaders() {
    // --- Set up vertex shader ---
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    std::cout << "Compiling vertex shader..." << std::endl;
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    } else {
        std::cout << "Vertex shader compiled successfully" << std::endl;
    }

    // --- Set up fragment shader ---
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    std::cout << "Compiling fragment shader..." << std::endl;
    glCompileShader(fragmentShader);
    
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    } else {
        std::cout << "Fragment shader compiled successfully" << std::endl;
    }

    // --- Set upo shader program ---
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}