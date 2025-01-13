#include "Texture.h"

Texture::Texture(const char* filename)
{
	int width, height, channels;
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(filename, & width, & height, & channels, 0);
	if (data == NULL) {
		printf("Failed to load image\n");
		exit(1);
	}

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);
	//glPixelStorei(GL_UNPACK_ALIGNMENT, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	stbi_image_free(data);
}

void Texture::bind(void)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind(void)
{
	glDisable(GL_TEXTURE_2D);
}