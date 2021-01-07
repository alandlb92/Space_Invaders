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
	const int StepDistance = 30;
	const int spaceHorizontal = 50;
	const int spaceVertical = 10;
	const int EnemyRows = 6;
	const int EnemyColunms = 6;
	
	float timeCount;
	bool Right;

	sf::Vector2f windowSize;

	float StepTime();
	int CountActivesBodies();
	void nextStep();
};

