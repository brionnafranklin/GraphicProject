#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Light.h"
#include "RotatingSphere.h"
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

class GraphicsApp
{
public:
	GraphicsApp();
	GraphicsApp(int width, int height, const char* title);
	~GraphicsApp();

	int run();

	bool start();
	bool update(double deltaTime);
	bool draw();
	bool end();

	GLFWwindow* getWindow() { return m_window; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }
	const char* getTitle() { return m_title; }

protected:

	GLFWwindow* m_window;
	Camera* m_camera;
	//RotatingSphere* m_rotatingSphere;
	//Actor *m_startActor, *m_endActor;

	aie::ShaderProgram m_shader;

	Light m_light;

	aie::OBJMesh m_objMesh;
	aie::Texture m_objTexture;

	Mesh m_mesh;
	glm::mat4 m_transform;
	aie::Texture m_texture;

	Earth* m_earth;
	D20* m_d20;

	Bone* m_hipBone;
	Bone* m_kneeBone;
	Bone* m_ankleBone;
	Skeleton* m_skeleton;

private:

	int m_width;
	int m_height;
	const char* m_title;
};