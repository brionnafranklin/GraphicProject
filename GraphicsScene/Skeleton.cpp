#include "Skeleton.h"

/// Sets up a list of bones
Skeleton::Skeleton()
{
	m_bones = {};
}

/// Calls the Update for the bones
bool Skeleton::update(double deltaTime)
{
	for each (Bone * b in m_bones)
	{
		b->update(deltaTime);
	}
	return true;
}

/// Calls the Draw for the bones
bool Skeleton::draw()
{
	for each (Bone * b in m_bones)
	{
		b->draw();
	}
	return true;
}

/// Adds a bone to the Skeleton
void Skeleton::addBone(Bone* bone)
{
	m_bones.push_back(bone);
}
