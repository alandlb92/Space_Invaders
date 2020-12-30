#include "EnemyBlock.h"
#include <iostream>
#include<string>

using namespace std;
EnemyBlock::EnemyBlock(sf::Vector2f windowSize)
{
	for (int i = 0; i < EnemyRows; i++)
	{
		for (int j = 0; j < EnemyColunms; j++)
		{
			Body* instance = new Body(static_cast<BodyType>(i + 1), windowSize);
			Bodies.push_back(instance);
			instance->positionX = (j * instance->getRows() * instance->getSize()) + (spaceHorizontal + (spaceHorizontal * j));
			instance->positionY = (i * instance->getRows() * instance->getSize()) + (spaceVertical + (spaceVertical * i));
			cout << "->Rows:" << instance->getRows() << "_Size: " << instance->getSize();
		}
	}
	stepTime = 2;
	timeCount = 0;
}

void EnemyBlock::Update(float time)
{
	timeCount += time;
	if (timeCount > stepTime)
	{
		timeCount = 0;
		nextStep();
	}
}

void EnemyBlock::Draw(sf::RenderWindow * window)
{
	for (int i = 0; i < Bodies.size(); i++)
	{
		Bodies[i]->Draw(window);
	}
}

void EnemyBlock::nextStep()
{
	cout << "Next Step";
	for (int i = 0; i < Bodies.size(); i++)
	{
		Bodies[i]->NextFrame();
	}
}
