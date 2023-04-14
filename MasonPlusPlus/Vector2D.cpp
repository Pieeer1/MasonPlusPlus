#include "Vector2D.h"

Vector2D::Vector2D()
{
	X = 0.0f;
	Y = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	this->X = x;
	this->Y = y;
}

Vector2D::~Vector2D()
{
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->X += vec.X;
	this->Y += vec.Y;
	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
	this->X -= vec.X;
	this->Y -= vec.Y;
	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	this->X *= vec.X;
	this->Y *= vec.Y;
	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	this->X /= vec.X;
	this->Y /= vec.Y;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	return this->Multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	return this->Divide(vec);
}

char* Vector2D::ToString(const Vector2D& vec)
{
	char arr[256];

	sprintf_s(arr, "(%d,%d)", vec.X, vec.Y);

	return arr;
}

Vector2D& operator+(Vector2D& v1, Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, Vector2D& v2)
{
	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, Vector2D& v2)
{
	return v1.Multiply(v2);
}

Vector2D& operator/(Vector2D& v1, Vector2D& v2)
{
	return v1.Divide(v2);
}
