#pragma once
#include "Body.h"
class Player : public Body
{
public:
	static Player* player;
	Player(BodyType bodyType, sf::Vector2f windowSize);
	void Update(float time, sf::Event* event);
private:
	bool canShoot;
	const float VELOCITY = 200;
	sf::Vector2f _windowSize;
};

