#pragma once
#include <SDL.h>

class Collision
{
public:
	static bool AABBIsColliding(const SDL_Rect& rect1, const SDL_Rect& rect2);

};