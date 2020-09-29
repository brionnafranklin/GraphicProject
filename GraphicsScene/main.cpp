#include <gl_core_4_4.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "App.h"

int main() 
{
	App* app = new App();
	if (app->start())
	{
		while (app->update())
		{
			app->draw(app->view, app->projection, app->window);
		}
		app->end(app->window);
	}
	delete app;
	return 0;
}