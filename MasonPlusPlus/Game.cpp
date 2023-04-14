#include "Game.h"
#include "TextureManager.h"
#include "Logger.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;

auto& player(manager.AddEntity());
auto& wall(manager.AddEntity());


Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		Logger::LogInformation("SDL Init Success");

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	map = new Map();


	player.AddComponent<TransformComponent>(2);
	player.AddComponent<SpriteComponent>("Sprites/BaseCharacter.png");
	player.AddComponent<KeyBoardControlComponent>();
	player.AddComponent<ColliderComponent>("player");

	wall.AddComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.AddComponent<SpriteComponent>("Sprites/Dirt.png");
	wall.AddComponent<ColliderComponent>("wall");
}

void Game::HandleEvents()
{

	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}

}

void Game::Update()
{
	tick++;
	manager.Refresh();
	manager.Update();

	if (Collision::AABBIsColliding(player.GetComponent<ColliderComponent>().Collider, wall.GetComponent<ColliderComponent>().Collider))// collision example
	{
		player.GetComponent<TransformComponent>().Velocity * -1; 
	}
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.Draw();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
