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

    ////Find the direction
    //glm::vec3 direction(
    //    glfwGetKey(m_instance->getWindow(), keyRight) - glfwGetKey(m_instance->getWindow(), keyLeft),
    //    glfwGetKey(m_instance->getWindow(), keyUp) - glfwGetKey(m_instance->getWindow(), keyDown),
    //    glfwGetKey(m_instance->getWindow(), keyForward) - glfwGetKey(m_instance->getWindow(), keyBack)
    //);
    //if (direction.x != 0.0f || direction.y != 0.0f || direction.z != 0.0f)
    //    direction = glm::normalize(direction);

    ////Move
    //m_position += direction * m_moveSpeed * (float)deltaTime;

    //Check input
    if (glfwGetKey(m_instance->getWindow(), keyForward)) {
        //Move forward
        m_position += forward * m_moveSpeed * (float)deltaTime;
    }
    if (glfwGetKey(m_instance->getWindow(), keyBack)) {
        //Move back
        m_position -= forward * m_moveSpeed * (float)deltaTime;
    }
    if (glfwGetKey(m_instance->getWindow(), keyLeft)) {
        //Move left
        m_position -= right * m_moveSpeed * (float)deltaTime;
    }
    if (glfwGetKey(m_instance->getWindow(), keyRight)) {
        //Move right
        m_position += right * m_moveSpeed * (float)deltaTime;
    }
    if (glfwGetKey(m_instance->getWindow(), keyUp)) {
        //Move up
        m_position += up * m_moveSpeed * (float)deltaTime;
    }
    if (glfwGetKey(m_instance->getWindow(), keyDown)) {
        //Move down
        m_position -= up * m_moveSpeed * (float)deltaTime;
    }

    //Get current mouse coordinates
    glfwGetCursorPos(m_instance->getWindow(), &m_currentMouseX, &m_currentMouseY);
    m_currentMouseX -= m_instance->getWidth() / 2;
    m_currentMouseY -= m_instance->getHeight() / 2;

    //Turn the camera based on the change in mouse position (delta mouse)
    if (glfwGetMouseButton(m_instance->getWindow(), GLFW_MOUSE_BUTTON_1)) {
        setYaw(getYaw() + m_turnSpeed * (m_currentMouseX - m_previousMouseX));
        setPitch(getPitch() - m_turnSpeed * (m_currentMouseY - m_previousMouseY));
    }
    //Store previous mouse coordinates
    m_previousMouseX = m_currentMouseX;
    m_previousMouseY = m_currentMouseY;

    return true;
}
