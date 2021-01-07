#pragma once
#include "Bounds.h"
#include "BarrierPiece.h"
#include "SFML/Graphics.hpp"
#include <map>

class BarrierPiece
{
public:
	BarrierPiece(sf::Vector2f position, int size);
	void Draw(sf::RenderWindow* window);
	bool enable;
	Bounds* bounds;
	int id;
	static std::map<int, BarrierPiece*> GetBarriers();
private:
	static int currentId;
	static std::map<int, BarrierPiece*> Barriers;
	sf::Vector2f _position;
	int _size;
};

