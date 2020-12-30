#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bounds.h"
#include "Body.h"
class Bullet
{
public:
	Bullet(sf::Vector2f startPosition, bool isEnemy);
	void Update(float time);
	void Draw(sf::RenderWindow* window);
	static std::vector<Bullet*> GetAllBullets();
	Bounds* bounds;
private:
	static std::vector<Bullet*> bulletList;
	void VerifyCollision();
	void DestroyEnemy(Body* body, int index);

	float positionX;
	float positionY;
	bool enemy;
	const float bulletSizeX = 4;
	const float bulletSizeY = 12;
	const float velocity = 300;
};

