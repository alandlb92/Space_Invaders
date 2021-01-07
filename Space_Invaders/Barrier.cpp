#include "Barrier.h"
#include <iostream>
Barrier::Barrier(sf::Vector2f position)
{
	int count = 1;

	for (int i = 0; i < 36; i++)
	{
		if (i == rows * count)
		{
			count++;
		}
		float x = ((i - ((count - 1)* rows)) * pieceSize) + position.x;
		float y = (count * pieceSize) + position.y;
		if (barrierShape[i])
			auto instance = new BarrierPiece(sf::Vector2f(x, y), pieceSize);
	}
}
