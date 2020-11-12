#pragma once
#include "Actor.h"

/// An Actor that is part of a Skeleton
class Bone : public Actor
{
public:
	/// Constructor; sets an actor for start frame and an actor for end frame
	Bone(Actor startFrame, Actor endFrame);
	/// Default deconstructor
	~Bone() {}

	/// Updates position and rotation
	bool update(double deltaTime) override;
	/// Draws this Bone
	bool draw() override;

private:
	/// Stores the start frame
	Actor m_startFrame;
	/// Stores the end frame
	Actor m_endFrame;
};
