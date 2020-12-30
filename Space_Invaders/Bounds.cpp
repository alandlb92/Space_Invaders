#include "Bounds.h"

Bounds::Bounds(float positionX, float positionY, float sizeX, float sizeY)
{
	CalculateBounds(positionX, positionY, sizeX, sizeY);
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
}
