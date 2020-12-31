#include "Bullet.h"
#include "EnemyBlock.h"
#include <iostream>
#include <map>

Bullet::Bullet(sf::Vector2f startPosition, bool isEnemy)
{
	id = currentId++;
	enemy = isEnemy;
	positionX = startPosition.x;
	positionY = startPosition.y;
	verifyCollision = true;
	bounds = new Bounds(positionX, positionY, bulletSizeX, bulletSizeY);
	bulletList.insert(std::pair<int, Bullet*>(id, this));
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

std::map<int, Bullet*> Bullet::GetAllBullets()
{
	return bulletList;
}

void Bullet::VerifyCollision()
{
	if (!verifyCollision)
		return;
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
	body->isEnabled = false;
	delete this;
}
