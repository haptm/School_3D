#pragma once
#include <stb/stb_image.h>
#include <GL/glut.h>

class Texture {
public:
	Texture(const char* filename);
	void bind(void);
	void unbind(void);

private:
	GLuint ID;
};