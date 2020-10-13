#pragma once
#include "Actor.h"
#include <Gizmos.h>

class RotatingSphere : public Actor
{
public:
	RotatingSphere();
	RotatingSphere(glm::vec4 color, float radius);//, float rotationSpeed, glm::vec3 position
	~RotatingSphere();

	bool draw() override;
	//void rotate();
	//void orbit(Actor parentBody);

private:

	glm::vec4 m_color;
	float m_radius;
	//float m_rotationSpeed;
};

