#pragma once

#include "Game.h"
#include "EntityComponentSystem.h"
#include "Components.h"

class KeyBoardControlComponent : public Component
{
public:
	TransformComponent* Transform;

	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}
		Transform = &entity->GetComponent<TransformComponent>();
	}
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	void Update() override
	{
		Transform->Velocity.X = 0;
		Transform->Velocity.Y = 0;

		if (keystates[SDL_SCANCODE_W]) {
			Transform->Velocity.Y = -1;
		}
		if (keystates[SDL_SCANCODE_A]) {
			Transform->Velocity.X = -1;
		}
		if (keystates[SDL_SCANCODE_S]) {
			Transform->Velocity.Y = 1;
		}
		if (keystates[SDL_SCANCODE_D]) {
			Transform->Velocity.X = 1;
		}
	}
};