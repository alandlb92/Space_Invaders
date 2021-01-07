#include "Body.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>

using namespace std;

Body::Body(BodyType _bodyType, sf::Vector2f windowSize)
{
	this->windowSize = windowSize;
	switch (_bodyType)
	{
	case BodyType::PLAYER:
		bodyType = _bodyType;
		CopyToBodyD(playerBody);
		this->positionX = 10;
		this->positionY = windowSize.y - (rows*pixelSize) - 20;
		break;
	case BodyType::ENEMY_1:
		bodyType = _bodyType;
		CopyToBodyD(Enemy1);
		break;
	case BodyType::ENEMY_2:
		bodyType = _bodyType;
		CopyToBodyD(Enemy2);
		break;
	case BodyType::ENEMY_3:
		bodyType = _bodyType;
		CopyToBodyD(Enemy3);
		break;
	case BodyType::ENEMY_4:
		bodyType = _bodyType;
		CopyToBodyD(Enemy4);
		break;
	case BodyType::ENEMY_5:
		bodyType = _bodyType;
		CopyToBodyD(Enemy5);
		break;
	case BodyType::ENEMY_6:
		bodyType = _bodyType;
		CopyToBodyD(Enemy6);
		break;
	default:
		break;
	}
	currentFrame = 0;
	animationFrames = 2;
	bounds = new Bounds(this->positionX, this->positionY, this->rows * this->pixelSize, this->rows * this->pixelSize);
	isEnabled = true;
}

void Body::Draw(sf::RenderWindow* window)
{
	if (!isEnabled)
		return;
	int count = 1;

	for (int i = 0; i < 196; i++)
	{
		if (i == rows * count)
		{
			count++;
		}
		float x = ((i - ((count - 1)* rows)) * pixelSize) + positionX;
		float y = (count * pixelSize) + positionY;
		if (bodyD[currentFrame][i] || true)
		{
			sf::RectangleShape shape(sf::Vector2f(pixelSize, pixelSize));
			shape.setPosition(sf::Vector2f(x, y));
			shape.setFillColor(sf::Color::Green);
			window->draw(shape);
		}		
	}
}

void Body::Move(sf::Vector2f direction)
{
	if (!isEnabled)
		return;

	this->positionX += (direction.x);
	this->positionY += (direction.y);
	bounds->CalculateBounds(this->positionX, this->positionY, this->rows * this->pixelSize, this->rows * this->pixelSize);
}

void Body::Update(float time)
{
	if (!isEnabled)
		return;

	ClampPosition();
}

void Body::NextFrame()
{
	currentFrame++;
	if (currentFrame >= animationFrames)
		currentFrame = 0;
}

void Body::SetPosition(sf::Vector2f position)
{
	this->positionX = position.x;
	this->positionY = position.y;
	bounds->CalculateBounds(this->positionX, this->positionY, this->rows * this->pixelSize, this->rows * this->pixelSize);
}

sf::Vector2f Body::GetPosition()
{
	return sf::Vector2f(this->positionX, this->positionY);
}

sf::Vector2f Body::GetBodySize()
{
	float sizeX = rows * pixelSize;
	float sizeY = rows * pixelSize;
	return sf::Vector2f(sizeX, sizeY);
}


void Body::CopyToBodyD(const int copy[2][196])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 196; j++)
		{
			bodyD[i][j] = copy[i][j];
		}
	}
}

void Body::ClampPosition()
{
	if (positionX > (windowSize.x - (rows*pixelSize)))
		positionX = (windowSize.x - (rows*pixelSize));
	else if (positionX < 0)
		positionX = 0;
}
