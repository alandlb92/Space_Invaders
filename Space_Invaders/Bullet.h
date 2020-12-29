#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Bullet
{
public:
	Bullet(sf::Vector2f startPosition, bool isEnemy);
	void Update(float time);
	void Draw(sf::RenderWindow* window);
	static std::vector<Bullet*> GetAllBullets();
private:
	static std::vector<Bullet*> bulletList;
	float positionX;
	float positionY;
	bool enemy;
	const float bulletSize = 3;
	const float velocity = 200;
};

