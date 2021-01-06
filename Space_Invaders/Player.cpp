#include "Player.h"
#include "Bullet.h"
#include <iostream>
Player::Player(BodyType bodyType, sf::Vector2f windowSize) :Body(bodyType, windowSize)
{
	player = this;
	_windowSize = windowSize;
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
		new Bullet(GetBulletStart(), false, _windowSize);
	}
	Body::Update(time);
}

sf::Vector2f Player::GetBulletStart()
{
	float centerX = positionX + GetBodySize().x / 2;
	float centerY = positionY;
	return sf::Vector2f(centerX, centerY);
}
