#include "App.h"

App::App()
{
}

App::~App()
{
}

bool App::start()
{
	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(1280, 720, "Computer Graphics", nullptr, nullptr);

	view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);

	if (window == nullptr)
	{
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(window);
		glfwTerminate();
		return -3;
	}

	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	aie::Gizmos::create(10000, 10000, 10000, 10000);

	glClearColor(0.2f, 0.05f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST); // enables the depth buffer

}

bool App::end(GLFWwindow* window)
{
	aie::Gizmos::destroy();
	glfwDestroyWindow(window);
	glfwTerminate();
	return true;
}

bool App::update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	aie::Gizmos::clear();
	return !glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE);
}

bool App::draw(mat4 view, mat4 projection, GLFWwindow* window)
{
	aie::Gizmos::addTransform(mat4(1));

	vec4 white(1);
	vec4 black(0, 0, 0, 1);

	for (int i = 0; i < 21; ++i)
	{
		aie::Gizmos::addLine(vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : black);

		aie::Gizmos::addLine(vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : black);
	}

	aie::Gizmos::addSphere(glm::vec3(0.0f, 0.0f, 0.0f), 6.0f, 5.0f, 5.0f, glm::vec4(0.8f, 0.8f, 1.0f, 1.0f),
		mat4(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f), glm::vec4(0.0f, 1.0f, 0.0f, 0.0f), glm::vec4(0.0f, 0.0f, 1.0f, 0.0f), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), -360.0f, 360.0f, -90.0f, 90.0f);

	aie::Gizmos::draw(projection * view);
	glfwSwapBuffers(window);
	glfwPollEvents();
	return true;
}
