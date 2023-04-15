#pragma once
#include <SDL.h>

class ColliderComponent;

class Collision
{
public:
	static bool AABBIsColliding(const SDL_Rect& rect1, const SDL_Rect& rect2);
	static bool AABBIsColliding(const ColliderComponent& colA, const ColliderComponent& colB);
};