#include "Player.h"
#include "Bullet.h"
#include <iostream>
Player::Player(BodyType bodyType, sf::Vector2f windowSize) :Body(bodyType, windowSize)
{
	player = this;
	spaceReleased = true;
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

	if (event->type == sf::Event::KeyReleased && event->key.code == sf::Keyboard::Space)
		spaceReleased = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && spaceReleased && CanShoot())
	{
		spaceReleased = false;
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

bool Player::CanShoot()
{
	for (const auto& it : Bullet::GetAllBullets())
	{
		if (!it.second->enemy)
			return false;
	}

	return true;
}
