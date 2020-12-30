#pragma once
class Bounds
{
public:
	Bounds(float positionX, float positionY, float sizeX, float sizeY);
	Bounds(bool create, float _right, float _left, float _top, float _botton);
	void CalculateBounds(float positionX, float positionY, float sizeX, float sizeY);

	float Right;
	float Left;
	float Top;
	float Botton;
};