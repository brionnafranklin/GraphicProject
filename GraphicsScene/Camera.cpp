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

	glm::vec3 direction(
		glfwGetKey(m_instance->getWindow(), keyLeft) - glfwGetKey(m_instance->getWindow(), keyRight), 
		glfwGetKey(m_instance->getWindow(), keyUp) - glfwGetKey(m_instance->getWindow(), keyDown),
		glfwGetKey(m_instance->getWindow(), keyForward) - glfwGetKey(m_instance->getWindow(), keyBack));
	if (direction.x != 0.0f || direction.y != 0.0f || direction.z != 0.0f)
	{
		direction = glm::normalize(direction);
	}

	m_position += direction * m_moveSpeed * (float)deltaTime;

	//check input
	/*if (glfwGetKey(m_instance->getWindow(), keyForward))
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
	}*/

	glfwGetCursorPos(m_instance->getWindow(), &m_currentMouseX, &m_currentMouseY);
	m_currentMouseX -= m_instance->getWidth() / 2;
	m_currentMouseY -= m_instance->getHeight() / 2;

	m_yaw += m_turnSpeed * (m_currentMouseX - m_previousMouseX);
	m_pitch -= m_turnSpeed * (m_currentMouseY - m_previousMouseY);

	m_previousMouseX = m_currentMouseX;
	m_previousMouseY = m_currentMouseY;

	return true;
}
