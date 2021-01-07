#pragma once
#include "SFML/Graphics.hpp"
#include "BarrierPiece.h"
#include <vector>
class Barrier
{
public:
	Barrier(sf::Vector2f position);
	
private:
	const int pieceSize = 10;
	const int rows = 6;
	const int barrierShape[36]
	{
		0,0,1,1,0,0,
		0,1,1,1,1,0,
		0,1,1,1,1,0,
		0,1,1,1,1,0,
		1,1,1,1,1,1,
		1,1,1,1,1,1
	};

};

