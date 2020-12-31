#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Bounds.h"
#include "Body.h"
class Bullet
{
public:
	Bullet(sf::Vector2f startPosition, bool isEnemy);
	void Update(float time);
	void Draw(sf::RenderWindow* window);
	static std::map<int, Bullet*> GetAllBullets();
	int id;
	Bounds* bounds;
private:
	static int currentId;
	static std::map<int, Bullet*> bulletList;
	void VerifyCollision();
	void DestroyEnemy(Body* body, int index);

	bool verifyCollision;
	float positionX;
	float positionY;
	bool enemy;
	const float bulletSizeX = 4;
	const float bulletSizeY = 12;
	const float velocity = 300;
};

