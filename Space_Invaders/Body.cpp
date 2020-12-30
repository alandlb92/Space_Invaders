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
}

void Body::Draw(sf::RenderWindow* window)
{
	int count = rows;
	int x = 0;
	int y = 0;
	for (int i = 0; i < 196; i++)
	{
		if (bodyD[currentFrame][i])
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
	if (bodyType != BodyType::PLAYER)
		cout << to_string(positionX);

	ClampPosition();
}

void Body::NextFrame()
{
	currentFrame++;
	cout << currentFrame;
	if (currentFrame >= animationFrames)
		currentFrame = 0;
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
