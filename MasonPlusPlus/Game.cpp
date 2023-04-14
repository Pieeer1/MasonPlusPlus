#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Logger.h"
#include "Map.h"
#include "EntityComponentSystem.h"
#include "Components.h"
GameObject* player;
GameObject* enemy;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.AddEntity());


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

	player = new GameObject("Sprites/BaseCharacter.png", 0, 0);
	enemy = new GameObject("Sprites/EnemyEye.png", 50, 50);
	map = new Map();


	newPlayer.AddComponent<PositionComponent>();

}

void Game::HandleEvents()
{
	SDL_Event event;
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

	player->Update();
	enemy->Update();
	manager.Update();
	char numChar[1000];
#pragma warning(disable : 4996)
	std::sprintf(numChar, "%d", newPlayer.GetComponent<PositionComponent>().x());
	Logger::LogInformation(numChar);

}

void Game::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();

	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
