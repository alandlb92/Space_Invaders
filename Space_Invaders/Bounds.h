#pragma once
class Bounds
{
public:
	Bounds(float positionX, float positionY, float sizeX, float sizeY);
	Bounds(bool create, float _right, float _left, float _top, float _botton);
	void CalculateBounds(float positionX, float positionY, float sizeX, float sizeY);
	bool VerifyCollision(Bounds* bounds);

	float Right;
	float Left;
	float Top;
	float Botton;

	float x;
	float y;
	float width;
	float height;
};