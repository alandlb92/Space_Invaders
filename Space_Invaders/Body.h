#pragma once
#include <SFML/Graphics.hpp>
#include "BodyType.h"
#include "Bounds.h"
using namespace std;
class Body
{

public:
	//enum BodyType { PLAYER, ENEMY_1, ENEMY_2, ENEMY_3, ENEMY_4, ENEMY_5, ENEMY_6 };
	Body(BodyType bodyType, sf::Vector2f windowSize);
	void Draw(sf::RenderWindow* window);
	void Move(sf::Vector2f direction);
	void Update(float time);
	void NextFrame();
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();

	Bounds* bounds;
	int bodyD[2][196];
	int getSize() { return pixelSize; }
	int getRows() { return rows; }
	bool isEnabled;
protected:
	float positionX;
	float positionY;	
private:
	BodyType bodyType;
	sf::Vector2f windowSize;
	int currentFrame = 0;
	int animationFrames;

	void CopyToBodyD(const int copy[2][196]);
	void ClampPosition();

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
	},{
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
	} };


	const int Enemy1[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,1,0,0,
	0,0,0,1,1,0,0,0,0,0,1,0,0,0,
	0,1,1,0,0,1,0,0,0,1,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,0,0,1,0,0,1,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,0,0,0,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,0,0,0,1,1,0,0,
	0,1,1,1,1,0,0,0,0,1,1,1,1,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,1,1,0,0,0,
	0,0,0,0,1,0,0,0,1,0,0,1,1,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,1,0,0,1,0,0,1,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,0,0,0,0,0,0,1,1,0,0,
	0,0,1,1,0,0,0,0,0,0,1,1,0,0,
	0,1,1,1,0,0,0,0,0,1,1,1,0,0
	}

	};

	const int Enemy2[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,0,0,1,1,0,0,1,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,1,0,0,1,1,0,0,1,1,0,0,1,0,
	0,1,0,0,0,1,1,1,1,0,0,0,1,0,
	0,1,0,0,0,1,0,0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,0,1,0,0,0,1,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,1,0,0,1,1,0,0,1,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,0,1,1,1,1,1,1,1,1,1,1,0,0,
	0,1,0,0,1,1,0,0,1,1,0,0,1,0,
	0,1,0,0,0,1,1,1,1,0,0,0,1,0,
	0,0,1,0,0,0,1,1,0,0,0,1,0,0,
	0,0,1,0,0,0,0,0,0,0,0,1,0,0
	}
	};

	const int Enemy3[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,
	0,0,0,1,0,1,0,0,1,0,1,0,0,0,
	0,0,0,1,0,0,1,1,0,0,1,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,1,1,0,0,0,0,1,1,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,1,0,0,1,1,0,0,1,0,0,0,
	0,0,1,0,1,1,1,1,1,1,0,1,0,0,
	0,0,1,0,0,0,1,1,0,0,0,1,0,0,
	0,0,1,0,0,0,1,1,0,0,0,1,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,0,1,0,0,1,0,0,0,0,0
	}
	};

	const int Enemy4[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,1,0,0,1,0,0,1,1,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,
	0,0,0,1,0,1,0,0,1,0,1,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,1,1,0,0,1,0,0,1,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,0,0,0,1,0,0,0,
	0,0,1,0,0,0,0,0,0,0,0,1,0,0
	}
	};

	const int Enemy5[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,1,1,0,0,1,1,1,1,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,1,1,1,0,0,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,1,1,1,1,1,0,0,1,1,1,0,0,
	0,0,0,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,1,1,1,1,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,1,1,1,0,0,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0
	}
	};

	const int Enemy6[2][196] = {
	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,1,0,0,0,0,0,0,
	0,0,0,0,1,0,1,1,0,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,1,0,0,0,1,0,0,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,0,0,0,
	0,0,0,1,0,0,1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,1,0,0,0,0,0,0,0
	},	{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,1,1,1,1,0,0,0,0,0,
	0,0,0,0,1,0,1,1,0,1,0,0,0,0,
	0,0,0,1,1,1,1,1,1,1,0,0,0,0,
	0,0,1,1,1,1,1,1,1,1,1,0,0,0,
	0,0,0,0,1,0,0,0,0,1,0,0,0,0,
	0,0,0,0,0,1,0,0,0,1,0,0,0,0,
	0,0,0,0,0,0,1,0,0,0,1,0,0,0,
	0,0,0,0,0,0,0,1,0,0,1,0,0,0,
	0,0,0,0,0,0,0,1,0,0,0,0,0,0
	}
	};
};

