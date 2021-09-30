#ifndef OGL_H
#define OGL_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace OGL
{
  // Only supports GL_STATIC_DRAW, fixme
  unsigned int PopulateNewVBO(float* someVertData, int aVertCount);

  // Only supports GL_STATIC_DRAW, fixme
  unsigned int PopulateNewEBO(unsigned int* someIndexData, int anIndexCount);

  unsigned int GenerateShaderProgram(const char* someVShaderSource, const char* someFShaderSource);
}
#endif
