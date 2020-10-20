#include "Mesh.h"
#include <gl_core_4_4.h>

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);
}

void Mesh::initialize(unsigned int vertexCount, const Vertex* vertices, unsigned int indexCount, unsigned int* indices)
{
	//Check that the mesh is not already initialized
	assert(m_vao == 0);

	//Generate buffers
	glGenBuffers(1, &m_vbo);
	glGenVertexArrays(1, &m_vao);

	//Bind buffers
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);


	//Fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,
		vertexCount * sizeof(Vertex),
		vertices,
		GL_STATIC_DRAW
	);

	//Enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		0
	);

	// Enable second element as normal
		glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,
		4,
		GL_FLOAT,
		GL_TRUE,
		sizeof(Vertex),
		(GLvoid*)(4 * sizeof(float))
	);

	//enable third element as textCoord
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,
		2,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)(12 * sizeof(float))
	);

	//Enable fourth element as color
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(
		4,
		4,
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(GLvoid*)(8 * sizeof(float))
	);

	// bind indices if there are any
	if (indexCount != 0) 
	{
		//generated index buffer
		glGenBuffers(1, &m_ibo);

		// bind index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

		// fill index buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
		m_triCount = indexCount / 3;
	}
	else 
	{
		m_triCount = vertexCount / 3;
	}

	// unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Mesh::initializeQuad()
{

	//Define 6 vertices for 2 triangles
	Vertex vertices[4];
	//positions
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1 };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1 };
	//normals
	vertices[0].normal = { -1.0f, 0.0f, 1.0f, 1 };
	vertices[1].normal = { 1.0f, 0.0f, 1.0f, 1 };
	vertices[2].normal = { -1.0f, 0.0f, -1.0f, 1 };
	vertices[3].normal = { 1.0f, 0.0f, -1.0f, 1 };
	//colors
	vertices[0].color = { 0.8f, 0.2f, 0.8f, 1 }; // magenta		//green 0.2f, 0.8f, 0.2f, 1
	vertices[1].color = { 1.0f, 1.0f, 1.0f, 1 }; //	white	//magenta 0.8f, 0.2f, 0.8f, 1
	vertices[2].color = { 1.0f, 1.0f, 1.0f, 1 }; //	white	//cyan 0.2f, 0.8f, 0.2f, 1
	vertices[3].color = { 0.8f, 0.2f, 0.2f, 1 }; // red		//red 0.8f, 0.2f, 0.2f, 1
	//TexCoord
	vertices[0].texCoord = { 0, 1 };
	vertices[1].texCoord = { 1, 1 };
	vertices[2].texCoord = { 0, 0 };
	vertices[3].texCoord = { 1, 0 };

	//define 6 indices for 2 triangles
	unsigned int indices[6] = 
	{
		0, 1, 2, //Triangle A
		2, 1, 3 //Triangle B
	};

	initialize(4, vertices, 6, indices);
}

void Mesh::initializeCube()
{
	//Define 8 vertices for 12 triangles
	Vertex vertices[8];
	//positions
	//Bottom
	vertices[0].position = { -0.5f, 0.0f, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0.0f, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0.0f, -0.5f, 1 };
	vertices[3].position = { 0.5f, 0.0f, -0.5f, 1 };
	//Top
	vertices[4].position = { -0.5f, 1.0f, 0.5f, 1 };
	vertices[5].position = { 0.5f, 1.0f, 0.5f, 1 };
	vertices[6].position = { -0.5f, 1.0f, -0.5f, 1 };
	vertices[7].position = { 0.5f, 1.0f, -0.5f, 1 };
	//colors
	glm::vec4 magenta = { 0.8f, 0.2f, 0.8f, 1 };
	glm::vec4 white = { 1.0f, 1.0f, 1.0f, 1 };
	glm::vec4 red = { 0.8f, 0.2f, 0.2f, 1 };
	//Bottom
	vertices[0].color = magenta; 
	vertices[1].color = white; 	
	vertices[2].color = white;
	vertices[3].color = red;
	//Top
	vertices[4].color = magenta;
	vertices[5].color = white;
	vertices[6].color = white;
	vertices[7].color = red;
	//TexCoord
	//Bottom
	vertices[0].texCoord = { 0.25f, 0.833f };
	vertices[1].texCoord = { 0.50f, 0.833f };
	vertices[2].texCoord = { 1.00f, 0.833f };
	vertices[3].texCoord = { 0.75f, 0.833f };
	//top
	vertices[4].texCoord = { 0.25f, 0.166f };
	vertices[5].texCoord = { 0.50f, 0.166f };
	vertices[6].texCoord = { 1.00f, 0.166f };
	vertices[7].texCoord = { 0.75f, 0.166f };

	//define 36 indices for 12 triangles
	unsigned int indices[36] =
	{
		0, 1, 2, //Bottom A
		2, 1, 3, //Bottom B
		4, 5, 6, //Top A
		6, 5, 7, //Top B
		2, 0, 6, //Left A
		4, 0, 6, //Left B
		1, 3, 5, //Right A
		3, 5, 7, //Right B
		0, 1, 4, //Front A
		1, 4, 5, //Front B
		2, 3, 7, //Back A
		2, 6, 7  //Back B
	};

	initialize(8, vertices, 36, indices);
}

void Mesh::initializeIcosahedron()
{
	//Define 12 vertices for 20 triangles
	Vertex vertices[12];

	//positions
		//A
	vertices[0].position = { 0.0f, 1.0f, 0.25f, 1 };
		//B
	vertices[1].position = { 1.0f, 0.5f, -0.25f, 1 };
		//C
	vertices[2].position = { 1.0f, -0.5f, 0.25f, 1 };
		//D
	vertices[3].position = { 0.0f, -1.0f, -0.25f, 1 };
		//E
	vertices[4].position = { -1.0f, -0.5f, 0.25f, 1 };
		//F
	vertices[5].position = { -1.0f, 0.5f, -0.25f, 1 };
		//G
	vertices[6].position = { -0.5f, 0.25f, 1.0f, 1 };
		//H
	vertices[7].position = { 0.0f, -0.5f, 1.0f, 1 };
		//I
	vertices[8].position = { 0.5f, 0.25f, 1.0f, 1 };
		//J
	vertices[9].position = { 0.0f, 0.5f, -1.0f, 1 };
		//K
	vertices[10].position = { -0.5f, -0.25f, -1.0f, 1 };
		//L
	vertices[11].position = { 0.5f, -0.25f, -1.0f, 1 };

	//colors
	glm::vec4 magenta = { 0.8f, 0.2f, 0.8f, 1 };
	glm::vec4 pink = { 0.8f, 0.4f, 0.8f, 1 };
	glm::vec4 white = { 1.0f, 1.0f, 1.0f, 1 };
	glm::vec4 orange = { 0.8f, 0.4f, 0.4f, 1 };
	glm::vec4 red = { 0.8f, 0.2f, 0.2f, 1 };
		//A
	vertices[0].color = white;
		//B
	vertices[1].color = white;
		//C
	vertices[2].color = magenta;
		//D
	vertices[3].color = white;
		//E
	vertices[4].color = white;
		//F
	vertices[5].color = red;
		//G
	vertices[6].color = white;
		//H
	vertices[7].color = white;
		//I
	vertices[8].color = white;
		//J
	vertices[9].color = white;
		//K
	vertices[10].color = white;
		//L
	vertices[11].color = white;

	//TexCoord
	//A
	vertices[0].texCoord = { 0, 0 };
	//B
	vertices[1].texCoord = { 0, 0 };
	//C
	vertices[2].texCoord = { 0, 0 };
	//D
	vertices[3].texCoord = { 0, 0 };
	//E
	vertices[4].texCoord = { 0, 0 };
	//F
	vertices[5].texCoord = { 0, 0 };
	//G
	vertices[6].texCoord = { 0, 0 };
	//H
	vertices[7].texCoord = { 0, 0 };
	//I
	vertices[8].texCoord = { 0, 0 };
	//J
	vertices[9].texCoord = { 0, 0 };
	//K
	vertices[10].texCoord = { 0, 0 };
	//L
	vertices[11].texCoord = { 0, 0 };

	//define 60 indices for 20 triangles
	unsigned int indices[60] =
	{
		9, 11, 10,  //JLK (1)
		8, 2, 7,    //ICH (2)
		0, 9, 5,    //AJF (3)
		4, 7, 3,    //EHD (4)
		11, 2, 3,   //LCD (5)
		5, 10, 4,   //FKE (6)
		9, 1, 11,   //JBL (7)
		0, 8, 6,    //AIG (8)
		5, 6, 4,    //FGE (9)
		0, 1, 8,    //ABI (10)
		3, 7, 3,    //EHD (11)
		1, 2, 8,    //BCI (12)
		10, 11, 3,  //KLD (13)
		6, 7, 4,    //GHE (14)
		1, 2, 8,    //BCI (15)
		0, 6, 5,    //AGF (16)
		0, 1, 9,    //ABJ (17)
		7, 2, 3,    //HCD (18)
		5, 9, 10,   //FJK (19)
		6, 8, 7,    //GIH (20)
	};

	initialize(12, vertices, 60, indices);
}


void Mesh::draw()
{
	glBindVertexArray(m_vao);
	//Using indices or just vertices
	if (m_ibo != 0)
		glDrawElements(
			GL_TRIANGLES,
			3 * m_triCount,
			GL_UNSIGNED_INT, 0
		);
	else
		glDrawArrays(
			GL_TRIANGLES,
			0,
			3 * m_triCount
		);
}