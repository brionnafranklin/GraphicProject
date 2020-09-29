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

class App
{
public:
	App();
	~App();

	bool start();
	bool end(GLFWwindow* window);
	bool update();
	bool draw(mat4 view, mat4 projection, GLFWwindow* window);

	GLFWwindow* window;
	mat4 view;
	mat4 projection;
};

