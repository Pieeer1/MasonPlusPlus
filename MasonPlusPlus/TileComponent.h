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

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
	
	}
	//TileComponent()
	//{
	//	if (!entity->HasComponent<TransformComponent>())
	//	{
	//		entity->AddComponent<TransformComponent>();
	//	}
	//	if (!entity->HasComponent<SpriteComponent>())
	//	{
	//		entity->AddComponent<SpriteComponent>();
	//	}
	//	Transform = &entity->GetComponent<TransformComponent>();
	//	Sprite = &entity->GetComponent<SpriteComponent>();
	//}


};