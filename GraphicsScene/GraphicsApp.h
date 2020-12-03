#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Light.h"
#include "Bone.h"
#include "Skeleton.h"
#include <Texture.h>
#include "Shader.h"
#include "Mesh.h"
#include "OBJMesh.h"
#include "Earth.h"
#include "D20.h"

class Camera;

using glm::vec3;
using glm::vec4;
using glm::mat4;

/// Where most the program logic happens
class GraphicsApp
{
public:
	/// Sets up the default window
	GraphicsApp();
	/// Sets up the window using given width, height and title
	GraphicsApp(int width, int height, const char* title);
	/// Default deconstructer
	~GraphicsApp();

	/// Main loop
	int run();

	/// Inistializes everything
	bool start();
	/// Updates everything on screen
	bool update(double deltaTime);
	/// Draws everything to the screen
	bool draw();
	/// Deletes, destores, and closes everything
	bool end();

	/// Returns the window
	GLFWwindow* getWindow() { return m_window; }
	/// Returns the width of the window
	int getWidth() { return m_width; }
	/// Returns the height of the window
	int getHeight() { return m_height; }
	/// Returns the title of the window
	const char* getTitle() { return m_title; }

protected:

	/// Stores the window
	GLFWwindow* m_window;
	/// The main camera; Controls where the user is looking
	Camera* m_camera;
	//Actor *m_startActor, *m_endActor;

	/// The shader
	aie::ShaderProgram m_shader;

	/// The light that is shining on the object
	Light m_light;

	/// The mesh of the object that's being rendered
	aie::OBJMesh m_objMesh;
	/// The texture of the object that's being rendered
	aie::Texture m_objTexture;

	/// The mesh used to render a shape
	Mesh m_mesh;
	/// The transform of the object
	glm::mat4 m_transform;
	/// The texture of the rendered shape
	aie::Texture m_texture;

	/// A plane
	Earth* m_earth;
	/// An Icosahedron
	D20* m_d20;

	/// The top bone that makes up the skeleton
	Bone* m_hipBone;
	/// The middle bone that makes up the skeleton
	Bone* m_kneeBone;
	/// The bottom bone that makes up the skeleton
	Bone* m_ankleBone;
	/// Made up of the hip bone, the knee bone, and the ankle bone
	Skeleton* m_skeleton;

private:
	/// The width of the window
	int m_width;
	/// The height of the window
	int m_height;
	/// The title printed at the top of the window
	const char* m_title;
};