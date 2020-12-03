#pragma once
#include "Actor.h"

/// Brightens the area that it shines on
class Light
{
public:
	/// Returns the direction
	glm::vec3 getDirection(){ return m_direction; }
	/// Sets the direction to a given vec3
	void setDirection(glm::vec3 direction) { m_direction = direction; }
	/// Returns the ambient
	glm::vec3 getAmbient() { return m_ambient; }
	/// Sets the ambient to a given vec3
	void setAmbient(glm::vec3 ambient) { m_ambient = ambient; }
	/// Returns the diffuse
	glm::vec3 getDiffuse() { return m_diffuse; }
	/// Sets the diffuse to a given vec3
	void setDiffuse(glm::vec3 diffuse) { m_diffuse = diffuse; }
	/// Returns the specular
	glm::vec3 getSpecular() { return m_specular; }
	/// Sets the specular
	void setSpecular(glm::vec3 specular) { m_specular = specular; }

private:
	/// Stores direction
	glm::vec3 m_direction;
	/// Stores ambient
	glm::vec3 m_ambient;
	/// Stores diffuse
	glm::vec3 m_diffuse;
	/// Stores specular
	glm::vec3 m_specular;
};

