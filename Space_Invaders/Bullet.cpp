#include "Bullet.h"

Bullet::Bullet(sf::Vector2f startPosition,bool isEnemy)
{
	enemy = isEnemy;
	positionX = startPosition.x;
	positionY = startPosition.y;
	bulletList.push_back(this); 
}

void Bullet::Update(float time)
{
	if(enemy)
	positionY += (time * velocity);
	else
	positionY -= (time * velocity);

}

void Bullet::Draw(sf::RenderWindow* window)
{
	sf::RectangleShape shape(sf::Vector2f(bulletSize, bulletSize *2));
	shape.setPosition(sf::Vector2f(positionX, positionY));
	shape.setFillColor(sf::Color::Red);
	window->draw(shape);
}

std::vector<Bullet*> Bullet::GetAllBullets()
{
	return bulletList;
}
