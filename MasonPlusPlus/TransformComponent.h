#pragma once
#pragma once
#include "Components.h"
#include "Vector2D.h"
class TransformComponent : public Component
{
public:

	TransformComponent()
	{
		Position.X = 0.0f;
		Position.Y = 0.0f;
	}
	TransformComponent(int scale)
	{
		Position.X = 0.0f;
		Position.Y = 0.0f;
		Scale = scale;
	}
	TransformComponent(float x, float y)
	{
		Position.X = x;
		Position.Y = y;
	}
	TransformComponent(float x, float y, int h, int w, int scale)
	{
		Position.X = x;
		Position.Y = y;
		Height = h;
		Width = w;
		Scale = scale;
	}
	void Update() override
	{
		Position.X += Velocity.X * Speed;
		Position.Y += Velocity.Y * Speed;
	}
	void Init() override
	{
		Velocity.X = 0;
		Velocity.Y = 0;
	}

	Vector2D Position;
	Vector2D Velocity;
	int Speed = 3;

	int Height = 32;
	int Width = 32;

	int Scale = 1;


};