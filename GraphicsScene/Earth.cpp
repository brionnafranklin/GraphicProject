#include "Earth.h"

/// Constructor; sets position, rotation, and scale using given values
Earth::Earth(glm::vec3 position, glm::quat rotation, glm::vec3 scale)
{
	m_position = position;
	m_rotation = rotation;
	m_scale = scale;
}

/// Initializes the mesh
bool Earth::start()
{
	//Initialise the mesh
	m_mesh.initializeQuad();

	if (!m_texture.load("earth_diffuse.jpg"))
	{
		printf("Failed to load texture ;~; \n");
		return false;
	}
	return true;
}

/// Binds the texture and draws the mesh
bool Earth::draw()
{
	m_texture.bind(0);

	// draw earth
	m_mesh.draw();

	return false;
}
