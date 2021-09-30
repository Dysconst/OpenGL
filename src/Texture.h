#include <iostream>
#include "stb_image.h"

class Texture
{
 public:
  Texture(const char* aFilePath);

  unsigned int GetTexture() const;
  unsigned int GetHeight() const;
  unsigned int GetWidth() const;

 private:
  int myWidth, myHeight, myNrChannels;
  unsigned int myTexture;
};
