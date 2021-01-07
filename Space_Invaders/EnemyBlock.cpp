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
	float pixelSize = 5;
	Bounds bounds = GetBounds();

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
		if (!Bodies[i]->isEnabled)
			continue;

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
	return ((float)CountActivesBodies() /((float)EnemyRows * (float)EnemyColunms));
}

int EnemyBlock::CountActivesBodies()
{
	int count = 0;
	for (int i = 0; i < Bodies.size(); i++)
	{
		if (Bodies[i]->isEnabled)
			count++;
	}

	return count;
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
