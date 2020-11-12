#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

/// Class that all game objects inherient from
class Actor
{
public:
	/// Default constructor
	Actor() {}
	/// Constructor; sets position, rotation, and scale
	Actor(glm::vec3 position, glm::quat rotation, glm::vec3 scale = { 1.0f, 1.0f, 1.0f });
	/// Default deconstructer
	~Actor() {}

	/// Start function that objrcts inherienting from Actor will override
	virtual bool start() { return true; }
	/// Update function that objrcts inherienting from Actor will override
	virtual bool update(double deltaTime) { return true; }
	/// Draw function that objrcts inherienting from Actor will override
	virtual bool draw() { return true; }
	/// End function that objrcts inherienting from Actor will override
	virtual bool end() { return true; }

	/// Returns position
	glm::vec3 getPosition() { return m_position; }
	/// Sets position to a given vec3
	void setPosition(glm::vec3 position) { m_position = position; }
	/// Returns rotation
	glm::quat getRotation() { return m_rotation; }
	/// Sets rotation to a given quat
	void setRotation(glm::quat rotation) { m_rotation = rotation; }
	/// Returns scale
	glm::vec3 getScale() { return m_scale; }
	/// Sets scale to a given vec3
	void setScale(glm::vec3 scale) { m_scale = scale; }
	/// Returns position, rotation, scale
	glm::mat4 getTransform();

	/// Returns this object's parent
	Actor* getParent() { return m_parent; }
	/// Sets parent to a given Actor
	void setParent(Actor* parent) { m_parent = parent; }
	/// Returns the parent's position
	glm::vec3 getParentPosition();
	/// Returns the parent's rotation
	glm::quat getParentRotation();

protected:
	/// Stores position on the x, y, and z axies
	glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
	/// Stores the values for rotation in a quat
	glm::quat m_rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
	/// Stores the scale of the actor
	glm::vec3 m_scale{ 1.0f, 1.0f, 1.0f };

private:
	/// Default parent
	Actor* m_parent = nullptr;
};
