#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OGL
{
  // Only supports GL_STATIC_DRAW, fixme
  unsigned int PopulateNewVBO(float* someVertData, int aVertCount)
  {
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, aVertCount, someVertData, GL_STATIC_DRAW);
    return VBO;
  }

  // Only supports GL_STATIC_DRAW, fixme
  unsigned int PopulateNewEBO(unsigned int* someIndexData, int anIndexCount)
  {
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, anIndexCount, someIndexData, GL_STATIC_DRAW);
    return EBO;
  }

  unsigned int GenerateShaderProgram(const char* someVShaderSource, const char* someFShaderSource)
  {
    unsigned int vertexShader, fragmentShader, shaderProgram;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderProgram = glCreateProgram();

    glShaderSource(vertexShader, 1, &someVShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char infoLog[1024];
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    glShaderSource(fragmentShader, 1, &someFShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      char infoLog[1024];
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success)
    {
      char infoLog[1024];
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
  }
}
