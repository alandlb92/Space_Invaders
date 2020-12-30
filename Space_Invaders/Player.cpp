#include "Player.h"
#include "Bullet.h"
#include <iostream>
Player::Player(BodyType bodyType, sf::Vector2f windowSize) :Body(bodyType, windowSize)
{
	player = this;
}

void Player::Update(float time, sf::Event* event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Move(sf::Vector2f(-VELOCITY * time, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Move(sf::Vector2f(VELOCITY * time, 0));
	}
	if (event->type == sf::Event::KeyPressed)
		canShoot = true;
	if (event->type == sf::Event::KeyReleased && event->key.code == sf::Keyboard::Space && canShoot)
	{
		canShoot = false;
		new Bullet(sf::Vector2f(positionX, positionY), false);
	}


	Body::Update(time);
}
