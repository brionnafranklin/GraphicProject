#pragma once
#include <glm/glm.hpp>
#include <Texture.h>

/// Used to draw shapes to  the screen
class Mesh
{
public:
	/// Sets position, normal, color, texCoord
	struct Vertex {
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec4 color;
		glm::vec2 texCoord;
	};

public:
	/// Creates the tricount, the vao, vbo, ibo
	Mesh() : m_triCount(0), m_vao(0), m_vbo(0), m_ibo(0) {}
	/// Default deconstucter
	~Mesh();

	/// Initialized and object
	void initialize(unsigned int vertexCount, const Vertex* vertices, unsigned int indexCount = 0, unsigned int* indices = nullptr);

	/// Initializes a quadilateral
	void initializeQuad();
	/// Initializes a cube
	void initializeCube();
	/// Initializes an Icoscahedron
	void initializeIcosahedron();

	/// Draws the object that was initialized
	virtual void draw();

protected:
	/// The number of triangles that make up the object
	unsigned int m_triCount;
	/// The vao, vbo, and the ibo
	unsigned int m_vao, m_vbo, m_ibo;
};