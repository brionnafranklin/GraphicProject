#include "Camera.h"

glm::mat4 Camera::getViewMatrix()
{
	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);
	glm::vec3 forward(cos(pitchRadians) * cos(yawRadians), sin(pitchRadians), cos(pitchRadians) * sin(yawRadians));
	return glm::lookAt(m_position, m_position + forward, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(glm::pi<float>() * 0.25f,
		width / height,
		0.1f, 1000.f);
}

bool Camera::update(double deltaTime)
{
	int keyForward = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_A;
	int keyRight = GLFW_KEY_D;
	int keyUp = GLFW_KEY_SPACE;
	int keyDown = GLFW_KEY_LEFT_CONTROL;

	float yawRadians = glm::radians(m_yaw);
	float pitchRadians = glm::radians(m_pitch);

	glm::vec3 forward(cos(pitchRadians) * cos(yawRadians), sin(pitchRadians), cos(pitchRadians) * sin(yawRadians));

	glm::vec3 right(-sin(yawRadians), 0, cos(yawRadians));

	glm::vec3 up(0.0f, 0.0f, 0.0f);

	//check input
	if (glfwGetKey(m_instance->getWindow(), keyForward))
	{
		m_position += forward * (float)deltaTime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyBack))
	{
		m_position -= forward * (float)deltaTime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyRight))
	{
		m_position += right * (float)deltaTime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyLeft))
	{
		m_position -= right * (float)deltaTime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyUp))
	{
		m_position += up * (float)deltaTime;
	}
	if (glfwGetKey(m_instance->getWindow(), keyDown))
	{
		m_position -= up * (float)deltaTime;
	}

	double currentMouseX = 0.0f;
	double currentMouseY = 0.0f;
	double previousMouseX = 0.0f;
	double previousMouseY = 0.0f;

	glfwGetCursorPos(m_instance->getWindow(), &currentMouseX, &currentMouseY);

	m_yaw += m_turnSpeed * (currentMouseX - previousMouseX);
	m_pitch -= m_turnSpeed * (currentMouseY - previousMouseY);

	previousMouseX = currentMouseX;
	previousMouseY = currentMouseY;

	return true;
}
