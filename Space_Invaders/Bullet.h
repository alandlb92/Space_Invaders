#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Bounds.h"
#include "Body.h"
class Bullet
{
public:
	Bullet(sf::Vector2f startPosition, bool isEnemy, sf::Vector2f windowSize);
	void Update(float time);
	void Draw(sf::RenderWindow* window);
	static std::map<int, Bullet*> GetAllBullets();
	int id;
	Bounds* bounds;
private:
	static int currentId;
	static void DeleteBullet(int id);
	static std::map<int, Bullet*> bulletList;

	sf::Vector2f _windowSize;
	bool VerifyCollision();
	bool VerifyOutOffScreen();
	void DestroyEnemy(Body* body, int index);

	float positionX;
	float positionY;
	bool enemy;
	const float bulletSizeX = 4;
	const float bulletSizeY = 12;
	const float velocity = 600;
};

