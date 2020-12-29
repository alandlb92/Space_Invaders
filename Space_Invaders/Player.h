#pragma once
#include "Body.h"
class Player : public Body
{
public:
	Player(BodyType bodyType, sf::Vector2f windowSize);
	void Update(float time, sf::Event* event);
private:
	bool canShoot;
	const float VELOCITY = 200;
};

