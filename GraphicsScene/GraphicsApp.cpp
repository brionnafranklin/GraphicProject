#include "GraphicsApp.h"
#include "Camera.h"
#include <cstdio>

GraphicsApp::GraphicsApp()
{
	m_width = 1280;
	m_height = 720;
	m_title = "Computer Graphics";
}

GraphicsApp::GraphicsApp(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}

GraphicsApp::~GraphicsApp()
{
}

int GraphicsApp::run()
{
	bool updating = true;
	bool drawing = true;

	double deltaTime = 0.0f;
	double timeOfPreviousUpdate = 0.0f;

	if (!start())
		return -1;

	while (updating && drawing) 
	{
		double timeOfCurrentUpdate = glfwGetTime();

		deltaTime = timeOfCurrentUpdate - timeOfPreviousUpdate;

		timeOfPreviousUpdate = timeOfCurrentUpdate;

		updating = update(deltaTime);
		drawing = draw();
	}

	if (!end())
		return -2;

	return 0;
}

bool GraphicsApp::start()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Initialize GLFW
	if (!glfwInit()) {
		return false;
	}

	//Create a window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	//Ensure the window was created
	if (!m_window) {
		glfwTerminate();
		return false;
	}

	//Set the window as our target
	glfwMakeContextCurrent(m_window);

	//Load OpenGL functions
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	//Print the OpenGL version number
	int major = ogl_GetMajorVersion();
	int minor = ogl_GetMinorVersion();
	printf("OpenGL version: %i.%i\n", major, minor);

	//Initialize Shader
	m_shader.loadShader(aie::eShaderStage::VERTEX,
		"simple.vert");
	m_shader.loadShader(aie::eShaderStage::FRAGMENT,
		"simple.frag");
	if (!m_shader.link()) {
		printf("Shader Error: %s\n", m_shader.getLastError());
		return false;
	}


	if (!m_objMesh.load("soulspear.obj"))
	{
		printf("Failed to Load soulspear.obj \n");
		return false;
	}

	//Initialize Gizmos
	aie::Gizmos::create(10000, 10000, 10000, 10000);

	//intialise camera
	m_camera = new Camera(this);
	m_camera->setPosition({ 10, 10, 10 });
	m_camera->setYaw(-135.0f);
	m_camera->setPitch(-35.0f);

	m_earth = new Earth({ 0.0f, 0.0f, 0.0f }, glm::vec3(1.0f, 0.0f, 0.0f), { 2.0f, 2.0f, 2.0f });
	m_earth->start();

	m_d20 = new D20({ 0.0f, 0.0f, 0.0f }, glm::vec3(1.0f, 0.0f, 0.0f), { 2.0f, 2.0f, 2.0f });
	m_d20->start();

	//set up the quad transform
	m_transform =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	//Set the clear color
	glClearColor(0.05f, 0.05f, 0.025f, 1.0f);
	//Enable OpenGL depth test
	glEnable(GL_DEPTH_TEST);

	//Create bones
	m_hipBone = new Bone({
		{ 0.0f, 5.0f, 0.0f }, glm::vec3(1.0f, 0.0f, 0.0f) },
		{ { 0.0f, 5.0f, 0.0f }, glm::vec3(-1.0f, 0.0f, 0.0f) }
	);
	m_kneeBone = new Bone({
		{ 0.0f, -2.5f, 0.0f }, glm::vec3(1.0f, 0.0f, 0.0f) },
		{ { 0.0f, -2.5f, 0.0f }, glm::vec3(0.0f, 0.0f, 0.0f) }
	);
	m_ankleBone = new Bone({
		{ 0.0f, -2.5f, 0.0f }, glm::vec3(-1.0f, 0.0f, 0.0f) },
		{ { 0.0f, -2.5f, 0.0f }, glm::vec3(0.0f, 0.0f, 0.0f) }
	);
	m_kneeBone->setParent(m_hipBone);
	m_ankleBone->setParent(m_kneeBone);

	//Create a skeleton
	m_skeleton = new Skeleton();
	//Add the bone to the skeleton
	m_skeleton->addBone(m_hipBone);
	m_skeleton->addBone(m_kneeBone);
	m_skeleton->addBone(m_ankleBone);

	return true;
}

bool GraphicsApp::update(double deltaTime)
{
	glfwPollEvents();

	//Keep the window open until the user closes it
	if (glfwWindowShouldClose(m_window) || glfwGetKey(m_window, GLFW_KEY_ESCAPE)) {
		return false;
	}

	m_camera->update(deltaTime);

	m_skeleton->update(deltaTime);

	return true;
}

bool GraphicsApp::draw()
{
	using glm::vec3;
	using glm::vec4;
	using glm::mat4;

	//Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Clear the Gizmos
	aie::Gizmos::clear();

	aie::Gizmos::addTransform(mat4(1), 4.0f);

	vec4 white(1, 1, 1, 1);
	vec4 grey(0.5f, 0.5f, 0.5f, 1);

	for (int i = 0; i < 21; ++i) {
		aie::Gizmos::addLine(
			vec3(-10 + i, 0, 10),
			vec3(-10 + i, 0, -10),
			i == 10 ? white : grey);
		aie::Gizmos::addLine(
			vec3(10, 0, -10 + i),
			vec3(-10, 0, -10 + i),
			i == 10 ? white : grey);
	}

	mat4 projectionMatrix = m_camera->getProjectionMatrix(m_width, m_height);
	mat4 viewMatrix = m_camera->getViewMatrix();

	// bind shader
	m_shader.bind();

	// bind transform
	mat4 pvm = projectionMatrix * viewMatrix * m_d20->getTransform();
	m_shader.bindUniform("ProjectionViewModel", pvm);

	//bind texture
	m_shader.bindUniform("diffuseTexture", 0);

	//bind time
	m_shader.bindUniform("timePassed", (float)glfwGetTime());

	//draw D20
	//m_d20->draw();

	// draw earth
	m_earth->draw();

	//draw objMesh
	//m_objMesh.draw();

	//m_skeleton->draw();
	
	aie::Gizmos::draw(projectionMatrix * viewMatrix);

	glfwSwapBuffers(m_window);

	return true;
}

bool GraphicsApp::end()
{
	//delete m_rotatingSphere;
	delete m_hipBone;
	delete m_kneeBone;
	delete m_ankleBone;
	delete m_skeleton;

	//Destroy the Gizmos
	aie::Gizmos::destroy();

	//Close the window
	glfwDestroyWindow(m_window);

	//Terminate GLFW
	glfwTerminate();

	return true;
}