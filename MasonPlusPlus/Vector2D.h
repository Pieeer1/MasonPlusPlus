#pragma once
#include "Logger.h"
class Vector2D
{

public:

	float X;
	float Y;

	Vector2D();
	Vector2D(float x, float y);

	~Vector2D();


	Vector2D& Add(const Vector2D& vec);
	Vector2D& Subtract(const Vector2D& vec);
	Vector2D& Multiply(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	friend Vector2D& operator+(Vector2D& v1, Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, Vector2D& v2);

	Vector2D& operator +=(const Vector2D& vec);
	Vector2D& operator -=(const Vector2D& vec);
	Vector2D& operator *=(const Vector2D& vec);
	Vector2D& operator /=(const Vector2D& vec);

	char* ToString(const Vector2D& vec);
};