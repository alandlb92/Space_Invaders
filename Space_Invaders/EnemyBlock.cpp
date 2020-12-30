#include "EnemyBlock.h"
#include <SFML/Graphics.hpp>
#include<string>
#include<iostream>

EnemyBlock::EnemyBlock(sf::Vector2f windowSize)
{
	this->windowSize = windowSize;
	for (int i = 0; i < EnemyRows; i++)
	{
		for (int j = 0; j < EnemyColunms; j++)
		{
			Body* instance = new Body(static_cast<BodyType>(i + 1), windowSize);
			Bodies.push_back(instance);
			float instancePositionX = (j * instance->getRows() * instance->getSize()) + (spaceHorizontal + (spaceHorizontal * j));
			float instancePositionY = (i * instance->getRows() * instance->getSize()) + (spaceVertical + (spaceVertical * i));
			instance->SetPosition(sf::Vector2f(instancePositionX, instancePositionY));
		}
	}
	timeCount = 0;
	Right = true;
}



void EnemyBlock::Update(float time)
{
	timeCount += time;
	if (timeCount > StepTime())
	{
		timeCount = 0;
		nextStep();
	}
}

void EnemyBlock::Draw(sf::RenderWindow * window)
{
	/*float pixelSize = 5;
	Bounds bounds = GetBounds();
	std::cout << bounds.Right << "Left" << bounds.Left;

	sf::RectangleShape shape1(sf::Vector2f(pixelSize, pixelSize));
	shape1.setPosition(sf::Vector2f(bounds.Left, bounds.Top));
	shape1.setFillColor(sf::Color::Red);
	window->draw(shape1);

	sf::RectangleShape shape2(sf::Vector2f(pixelSize, pixelSize));
	shape2.setPosition(sf::Vector2f(bounds.Left, bounds.Botton));
	shape2.setFillColor(sf::Color::Yellow);
	window->draw(shape2);

	sf::RectangleShape shape3(sf::Vector2f(pixelSize, pixelSize));
	shape3.setPosition(sf::Vector2f(bounds.Right, bounds.Top));
	shape3.setFillColor(sf::Color::Blue);
	window->draw(shape3);


	sf::RectangleShape shape4(sf::Vector2f(pixelSize, pixelSize));
	shape4.setPosition(sf::Vector2f(bounds.Right, bounds.Botton));
	shape4.setFillColor(sf::Color::Magenta);
	window->draw(shape4);*/

	for (int i = 0; i < Bodies.size(); i++)
	{
		Bodies[i]->Draw(window);
	}
}


Bounds EnemyBlock::GetBounds()
{
	float Right = -10000;
	float Left = 10000;

	float Top = 10000;
	float Botton = -10000;
	for (int i = 0; i < Bodies.size(); i++)
	{
		if (Bodies[i]->bounds->Left < Left)
			Left = Bodies[i]->bounds->Left;
		if (Bodies[i]->bounds->Right > Right)
			Right = Bodies[i]->bounds->Right;

		if (Bodies[i]->bounds->Botton > Botton)
			Botton = Bodies[i]->bounds->Botton;
		if (Bodies[i]->bounds->Top < Top)
			Top = Bodies[i]->bounds->Top;
	}

	return Bounds(true, Right, Left, Top, Botton);
}

float EnemyBlock::StepTime()
{
	return (Bodies.size()/(EnemyRows * EnemyColunms)) * (2) ;
}

void EnemyBlock::nextStep()
{
	sf::Vector2f movementDirection = sf::Vector2f(0, 0);
	if (Right)
		movementDirection = sf::Vector2f(StepDistance, 0);
	else
		movementDirection = sf::Vector2f(-StepDistance, 0);


	if ((GetBounds().Right > this->windowSize.x - StepDistance && Right) || (GetBounds().Left < StepDistance && !Right))
	{
		movementDirection = sf::Vector2f(0, StepDistance);
		Right = !Right;
	}

	for (int i = 0; i < Bodies.size(); i++)
	{
		Bodies[i]->Move(movementDirection);
		Bodies[i]->NextFrame();
	}
}
