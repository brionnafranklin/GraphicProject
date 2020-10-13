#include "RotatingSphere.h"

RotatingSphere::RotatingSphere()
{ 
	m_color = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
	m_radius = 1.0f;
	m_position = glm::vec3(1.0f, 1.0f, 1.0f);
}

RotatingSphere::RotatingSphere(glm::vec4 color, float radius)
{
	m_color = color;
	m_radius = radius;
	//m_position = position;
}

RotatingSphere::~RotatingSphere()
{
}

bool RotatingSphere::draw()
{
	aie::Gizmos::addSphere(m_position, m_radius, 6 * m_radius, 6 * m_radius, m_color);

	return true;
}
//
//void RotatingSphere::rotate()
//{
//	
//}
//
//void RotatingSphere::orbit(Actor parentBody)
//{
//
//}