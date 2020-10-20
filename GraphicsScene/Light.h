#pragma once
#include "Actor.h"
class Light
{
public:
	glm::vec3 getDirection(){ return m_direction; }
	void setDirection(glm::vec3 direction) { m_direction = direction; }

private:
	glm::vec3 m_direction;
};

