#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "GraphicsApp.h"

int main() 
{
	GraphicsApp* app = new GraphicsApp(1536, 864, "Computer Graphics");

	app->run();

	delete app;

	return 0;
}