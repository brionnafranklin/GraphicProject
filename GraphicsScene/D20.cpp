#include "D20.h"

D20::D20(glm::vec3 position, glm::quat rotation, glm::vec3 scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

bool D20::start()
{
	//Initialise the mesh
	m_mesh.initializeIcosahedron();

	return true;
}

bool D20::draw()
{
	m_texture.bind(0);

	// draw earth
	m_mesh.draw();
	return true;
}
