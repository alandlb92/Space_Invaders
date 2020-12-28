#pragma once
#include <SFML/Graphics.hpp>
#include "BodyType.h"
using namespace std;
class Body
{

public:
	float positionX;
	float positionY;
	enum BodyType { PLAYER };
	Body(BodyType bodyType, sf::Vector2f windowSize);
	void Draw(sf::RenderWindow* window);
	void Move(sf::Vector2f direction);
	void Update(float time);
private:
	BodyType bodyType;
	sf::Vector2f windowSize;
	int currentFrame = 0;
	int animationFrames;
	float timeCount = 0.0f;

	void ClampPosition();
	void NextFrame();

	float animationFps = 1;
	const int pixelSize = 3;
	const int rows = 14;
	const int playerBody[2][196] = {
		{

	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0
},
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,0,0,1,1,1,1,0,0,1,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0
	};
};

