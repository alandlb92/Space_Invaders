#include "Bounds.h"
#include <iostream>
Bounds::Bounds(float positionX, float positionY, float sizeX, float sizeY)
{
	CalculateBounds(positionX, positionY, sizeX, sizeY);
	x = positionX;
	y = positionY;
	width = sizeX;
	height = sizeY;
}

Bounds::Bounds(bool create, float _right, float _left, float _top, float _botton)
{
	Right = _right;
	Left = _left;
	Top = _top;
	Botton = _botton;
}

void Bounds::CalculateBounds(float positionX, float positionY, float sizeX, float sizeY)
{
	Right = positionX + sizeX;
	Left = positionX;
	Top = positionY;
	Botton = positionY + sizeY;
	x = positionX;
	y = positionY;
	width = sizeX;
	height = sizeY;
}

bool Bounds::VerifyCollision(Bounds * bounds)
{
	Bounds* rect1 = bounds;
	Bounds* rect2 = this;
	return (rect1->x < rect2->x + rect2->width &&
		rect1->x + rect1->width > rect2->x &&
		rect1->y < rect2->y + rect2->height &&
		rect1->y + rect1->height > rect2->y);
}
