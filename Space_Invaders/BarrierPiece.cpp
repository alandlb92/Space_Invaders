#include "BarrierPiece.h"

BarrierPiece::BarrierPiece(sf::Vector2f position, int size)
{
	enable = true;
	_position = position;
	_size = size;
	id = currentId++;
	Barriers.insert(std::pair<int, BarrierPiece*>(id, this));
	bounds = new Bounds(_position.x, _position.y, _size, _size);
}

void BarrierPiece::Draw(sf::RenderWindow * window)
{
	if (enable)
	{
		sf::RectangleShape shape(sf::Vector2f(_size, _size));
		shape.setPosition(_position);
		shape.setFillColor(sf::Color::Yellow);
		window->draw(shape);
	}	
}

std::map<int, BarrierPiece*> BarrierPiece::GetBarriers()
{
	return Barriers;
}
