#include "Bullet.h"
#include "EnemyBlock.h"
#include "BarrierPiece.h"
#include <iostream>
#include <map>

Bullet::Bullet(sf::Vector2f startPosition, bool isEnemy, sf::Vector2f windowSize)
{
	id = currentId++;
	enemy = isEnemy;
	positionX = startPosition.x - bulletSizeX;
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
			if (enemy->isEnabled && bounds->VerifyCollision(enemy->bounds))
			{
				DestroyEnemyAndBullet(enemy, i);
				return true;
			}
		}
	}
	else
	{

	}

	for (const auto& it : BarrierPiece::GetBarriers())
	{
		if (it.second->enable && bounds->VerifyCollision(it.second->bounds))
		{
			it.second->enable = false;
			DeleteBullet(this->id);
			return true;
		}
	}

	return false;
}

bool Bullet::VerifyOutOffScreen()
{
	if (positionY > _windowSize.y + bulletSizeY || positionY < 0 - bulletSizeY)
	{
		DeleteBullet(this->id);
		return true;
	}
	return false;
}

void Bullet::DestroyEnemyAndBullet(Body * body, int index)
{
	body->isEnabled = false;
	DeleteBullet(this->id);
}
