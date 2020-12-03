#pragma once
#include "Actor.h"
#include "Bone.h"
#include <vector>

/// An Actor made up of bones
class Skeleton : public Actor
{
public:
	/// Sets up a list of bones
	Skeleton();
	/// Default deconstructer
	~Skeleton() {}

	/// Calls the Update for the bones
	bool update(double deltaTime) override;
	/// Calls the Draw for the bones
	bool draw() override;

	/// Adds a bone to the Skeleton
	void addBone(Bone* bone);

private:
	/// The list of bones
	std::vector<Bone*> m_bones;
};

