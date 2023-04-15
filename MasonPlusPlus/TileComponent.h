#pragma once

#include "SDL.h"
#include "EntityComponentSystem.h"
#include "Components.h"



class TileComponent : public Component
{
public:
	TransformComponent* Transform;

	SpriteComponent* Sprite;

	SDL_Rect TileRect;
	int TileID;
	const char* Path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		TileRect.x = x;
		TileRect.y = y;
		TileRect.w = w;
		TileRect.h = h;
		TileID = id;

		switch (TileID)
		{
		case 0:
			Path = "Sprites/Water.png";
			break;
		case 1:
			Path = "Sprites/Dirt.png";
			break;
		case 2:
			Path = "Sprites/Grass.png";
			break;
		default:
			break;
		}
	}

	void Init() override
	{
		entity->AddComponent<TransformComponent>((float)TileRect.x, (float)TileRect.y, TileRect.w, TileRect.h, 1);
		Transform = &entity->GetComponent<TransformComponent>();

		entity->AddComponent<SpriteComponent>(Path);
		Sprite = &entity->GetComponent<SpriteComponent>();
	}

};