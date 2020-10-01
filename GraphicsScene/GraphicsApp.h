#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

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

protected:

	GLFWwindow* m_window;
	Camera* m_camera;

private:

	int m_width;
	int m_height;
	const char* m_title;
};

