#include "SampleBuilding.h"
#include "Cube.h"

SampleBuilding::SampleBuilding(glm::vec3 position, glm::vec3 rotation, float size)
{
	this->position = position;
	this->rotation = rotation;
	this->size = size;
}

void SampleBuilding::draw(void) {
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(rotation.x, 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.y, 0.0f, 1.0f, 0.0f);
	glRotatef(rotation.z, 0.0f, 0.0f, 1.0f);
	glScalef(size, size, size);
	
	Cube cube(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	Cube cube2(glm::vec3(0.0f, 2.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	cube.draw();
	cube2.draw();

	glPopMatrix();
}