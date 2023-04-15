#include "Collision.h"
#include "ColliderComponent.h"

bool Collision::AABBIsColliding(const SDL_Rect& rect1, const SDL_Rect& rect2)
{
	return rect1.x + rect1.w >= rect2.x && rect2.x + rect2.w >= rect1.x && rect1.y + rect1.h >= rect2.y && rect2.y + rect2.h >= rect1.y;
}

bool Collision::AABBIsColliding(const ColliderComponent& colA, const ColliderComponent& colB)
{
	bool result = AABBIsColliding(colA.Collider, colB.Collider);

	if (result)
	{
		Logger::LogInformation((colA.Tag + " " + colB.Tag).c_str());
	}

	return result;
}