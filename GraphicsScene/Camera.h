#pragma once
#include "GraphicsApp.h"
#include "Actor.h"

/// An Actor used to move the user's view
class Camera  :public Actor
{
public:

	/// Constructor; creates an instance of GraphicsApp
	Camera(GraphicsApp* instance) { m_instance = instance; }
	/// Deconstructor
	~Camera() {}

	/// Returns where the camera is looking
	glm::mat4 getViewMatrix();
	/// Returns the projection
	glm::mat4 getProjectionMatrix(float width, float height);

	/// Returns the yaw
	float getYaw() { return m_yaw; }
	/// Sets the yaw to a given degrees
	void setYaw(float degrees) { m_yaw = degrees; }
	/// Returns the pitch
	float getPitch() { return m_pitch; }
	/// Sets the pitch to a given degrees
	void setPitch(float degrees) { m_pitch = degrees; }

	/// Ipdates position based on input
	bool update(double deltaTime) override;

private:
	/// An instance of the GraphicsApp
	GraphicsApp* m_instance;

	/// Stores the yaw
	float m_yaw = 0.0f; //theta
	/// Stores the pitch
	float m_pitch = 0.0f; //phi

	/// The speed that the camera moves
	float m_moveSpeed = 20.0f;
	/// The speed that the camera turns
	float m_turnSpeed = 0.04f;

	/// The current position of the mouse on the x axis
	double m_currentMouseX = 0.0f;
	/// The current position of the mouse on the y axis
	double m_currentMouseY = 0.0f;
	/// The previous position of the mouse on the x axis
	double m_previousMouseX = 0.0f;
	/// The previous position of the mouse on the y axis
	double m_previousMouseY = 0.0f;
};

