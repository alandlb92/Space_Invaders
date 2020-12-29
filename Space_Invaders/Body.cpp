#include "Body.h"
#include <SFML/Graphics.hpp>

Body::Body(BodyType _bodyType, sf::Vector2f windowSize)
{
	this->windowSize = windowSize;
	this->timeCount = 0;
	switch (_bodyType)
	{
	case BodyType::PLAYER:
		bodyType = _bodyType;
		animationFrames = 1;
		animationFps = 1;
		this->positionX = 10;
		this->positionY = windowSize.y - (rows*pixelSize) - 20;
		break;
	default:
		break;
	}
}

void Body::Draw(sf::RenderWindow* window)
{
	int count = rows;
	int x = 0;
	int y = 0;
	for (int i = 0; i < 196; i++)
	{
		if (playerBody[currentFrame][i])
		{
			sf::RectangleShape shape(sf::Vector2f(pixelSize, pixelSize));
			shape.setPosition(sf::Vector2f((x * pixelSize) + positionX, (y * pixelSize) + positionY));
			shape.setFillColor(sf::Color::Green);
			window->draw(shape);
		}

		if (count == 0)
		{
			count = rows;
			y++;
		}
		count--;
		x = i - (rows*y);
	}
}

void Body::Move(sf::Vector2f direction)
{
	this->positionX += (direction.x);
	this->positionY += (direction.y);
}

void Body::Update(float time)
{
	ClampPosition();

	timeCount += (time);
	if (timeCount > animationFps)
		NextFrame();
}

void Body::NextFrame()
{
	currentFrame++;
	if (currentFrame >= animationFrames)
		currentFrame = 0;

	timeCount = 0;
}

void Body::ClampPosition()
{
	if (positionX > (windowSize.x - (rows*pixelSize)))
		positionX = (windowSize.x - (rows*pixelSize));
	else if (positionX < 0)
		positionX = 0;
}
