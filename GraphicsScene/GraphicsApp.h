#pragma once
#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

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

protected:

	GLFWwindow* m_window;
	mat4 m_view;
	mat4 m_projection;

private:

	int m_width;
	int m_height;
	const char* m_title;
};

