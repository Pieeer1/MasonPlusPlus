#pragma once

#include "SDL.h"
#include "Components.h"
#include <string>

class ColliderComponent : public Component
{
public:
	SDL_Rect Collider;
	std::string Tag;

	TransformComponent* Transform;

	ColliderComponent(std::string tag)
	{
		Tag = tag;
	}

	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}
		Transform = &entity->GetComponent<TransformComponent>();

	}
	void Update() override
	{
		Collider.x = static_cast<int>(Transform->Position.X);
		Collider.y = static_cast<int>(Transform->Position.Y);
		Collider.w = Transform->Width * Transform->Scale;
		Collider.h = Transform->Height * Transform->Scale;
	}
};

