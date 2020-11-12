#include "D20.h"

/// Constructor; sets position, rotation, and scale using given values
D20::D20(glm::vec3 position, glm::quat rotation, glm::vec3 scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

/// Initializes the mesh
bool D20::start()
{
	//Initialise the mesh
	m_mesh.initializeIcosahedron();

	return true;
}

/// Binds the texture and draws the mesh
bool D20::draw()
{
	m_texture.bind(0);

	// draw earth
	m_mesh.draw();
	return true;
}
