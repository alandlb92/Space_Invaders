#include "Bullet.h"
#include "EnemyBlock.h"
#include <iostream>

Bullet::Bullet(sf::Vector2f startPosition, bool isEnemy)
{
	enemy = isEnemy;
	positionX = startPosition.x;
	positionY = startPosition.y;
	bulletList.push_back(this);
	bounds = new Bounds(positionX, positionY, bulletSizeX, bulletSizeY);
}

void Bullet::Update(float time)
{
	if (enemy)
		positionY += (time * velocity);
	else
		positionY -= (time * velocity);
	bounds->CalculateBounds(positionX, positionY, bulletSizeX, bulletSizeY);
	VerifyCollision();
}


void Bullet::Draw(sf::RenderWindow* window)
{
	sf::RectangleShape shape(sf::Vector2f(bulletSizeX, bulletSizeY));
	shape.setPosition(sf::Vector2f(positionX, positionY));
	shape.setFillColor(sf::Color::Red);
	window->draw(shape);
}

std::vector<Bullet*> Bullet::GetAllBullets()
{
	return bulletList;
}

void Bullet::VerifyCollision()
{
	if (!enemy)
	{
		for (int i = 0; i < EnemyBlock::Bodies.size(); i++)
		{
			Body* enemy = EnemyBlock::Bodies[i];
			if (bounds->VerifyCollision(enemy->bounds))
			{
				DestroyEnemy(enemy, i);
			}
		}
	}
	else
	{

	}
}

void Bullet::DestroyEnemy(Body * body, int index)
{
	delete body;
	//EnemyBlock::Bodies.erase(1, 1);
	
}
