#pragma once
#include "SDL.h"
#include "Components.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		 SetTexture(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}
		transform = &entity->GetComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->Width;
		srcRect.h = transform->Height;
	}
	void Update() override
	{
		destRect.x = static_cast<int>(transform->Position.X);
		destRect.y = static_cast<int>(transform->Position.Y);
		destRect.w = transform->Width * transform->Scale;
		destRect.h = transform->Height * transform->Scale;
	}
	void Draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
	void SetTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;


};