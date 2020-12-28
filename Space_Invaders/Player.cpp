#include "Player.h"

Player::Player(BodyType bodyType, sf::Vector2f windowSize):Body(bodyType, windowSize)
{

}

void Player::Update(float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Move(sf::Vector2f(-VELOCITY * time, 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Move(sf::Vector2f(VELOCITY * time, 0));
	}

	Body::Update(time);
}
