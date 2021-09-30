#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Texture.h"
#include "stb_image.h"

Texture::Texture(const char* aFilePath)
{
  glGenTextures(1, &myTexture);
  glBindTexture(GL_TEXTURE_2D, myTexture);
  // set the texture wrapping/filtering options (on the currently bound texture object)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  // load and generate the texture
  unsigned char *data = stbi_load(aFilePath, &myWidth, &myHeight, &myNrChannels, 0);

  if (data)
    {
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
      glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
      glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, myWidth, myHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
    }
  else
    {
      std::cout << "Failed to load texture" << std::endl;
    }
  stbi_image_free(data);
}

unsigned int Texture::GetWidth() const
{
  return myWidth;
}

unsigned int Texture::GetHeight() const
{
  return myHeight;
}

unsigned int Texture::GetTexture() const
{
  return myTexture;
}
