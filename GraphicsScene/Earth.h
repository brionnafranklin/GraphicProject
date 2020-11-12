#pragma once
#include <Texture.h>
#include "Actor.h"
#include "Mesh.h"

/// An Actor that a flat plane
class Earth : public Actor
{
public:
	/// Constructor; sets position, rotation, and scale using given values
	Earth(glm::vec3 position, glm::quat rotation, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });
	/// Initializes the mesh
	bool start() override;
	/// Binds the texture and draws the mesh
	bool draw() override;
private:
	/// Stores the mesh for this Actor
	Mesh m_mesh;
	/// Stores the texture for this Actor
	aie::Texture m_texture;
};

