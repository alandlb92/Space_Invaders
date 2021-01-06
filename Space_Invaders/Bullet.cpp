#include "Bullet.h"
#include "EnemyBlock.h"
#include <iostream>
#include <map>

Bullet::Bullet(sf::Vector2f startPosition, bool isEnemy, sf::Vector2f windowSize)
{
	id = currentId++;
	enemy = isEnemy;
	positionX = startPosition.x;
	positionY = startPosition.y;
	_windowSize = windowSize;
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
	if (VerifyCollision())
		return;
	if (VerifyOutOffScreen())
		return;
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

void Bullet::DeleteBullet(int id)
{
	delete Bullet::bulletList[id]->bounds;
	delete Bullet::bulletList[id];
	Bullet::bulletList.erase(id);
}

bool Bullet::VerifyCollision()
{
	if (!enemy)
	{
		for (int i = 0; i < EnemyBlock::Bodies.size(); i++)
		{
			Body* enemy = EnemyBlock::Bodies[i];
			if (bounds->VerifyCollision(enemy->bounds) && enemy->isEnabled)
			{
				DestroyEnemy(enemy, i);
				return true;
			}
		}
	}
	else
	{

	}
	return false;
}

bool Bullet::VerifyOutOffScreen()
{
	if (positionY > _windowSize.y + bulletSizeY || positionY < 0 - bulletSizeY)
	{
		cout << "Deleted out of screen";
		DeleteBullet(this->id);
		return true;
	}
	return false;
}

void Bullet::DestroyEnemy(Body * body, int index)
{
	body->isEnabled = false;
	DeleteBullet(this->id);
	cout << "Deleted Collision";
}
