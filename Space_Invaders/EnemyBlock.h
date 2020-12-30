#pragma once
#include "Body.h"
#include "Bounds.h"
#include <vector>
class EnemyBlock
{
public:
	static std::vector<Body*> Bodies;
	EnemyBlock(sf::Vector2f windowSize);
	void Update(float time);
	void Draw(sf::RenderWindow* window);
	Bounds GetBounds();

	

private:
	sf::Vector2f windowSize;
	float StepTime();
	float timeCount;
	bool Right;

	void nextStep();

	const int StepDistance = 30;
	const int spaceHorizontal = 50;
	const int spaceVertical = 10;
	const int EnemyRows = 6;
	const int EnemyColunms = 6;
};

