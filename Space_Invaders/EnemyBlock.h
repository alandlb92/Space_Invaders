#pragma once
#include "Body.h"
#include <vector>
class EnemyBlock
{
public:
	EnemyBlock(sf::Vector2f windowSize);
	std::vector<Body*> Bodies;

	void Update(float time);
	void Draw(sf::RenderWindow* window);

private:
	float stepTime;
	float timeCount;

	void nextStep();

	const int spaceHorizontal = 50;
	const int spaceVertical = 10;
	const int EnemyRows = 6;
	const int EnemyColunms = 6;
};

