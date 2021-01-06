#include <SFML/Graphics.hpp>
#include <iostream>
#include "Body.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyBlock.h"
#include <chrono>
#include <vector>

const sf::Vector2f windowSize(1000, 800);
std::map<int, Bullet*> Bullet::bulletList;
int Bullet::currentId;
std::vector<Body*> EnemyBlock::Bodies;
Player* Player::player;


int main()
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Invaders");
	EnemyBlock* enemies = new EnemyBlock(windowSize);
	Player* player = new Player(BodyType::PLAYER, windowSize);
	auto start = std::chrono::high_resolution_clock::now();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;;
	while (window.isOpen())
	{
		start = std::chrono::high_resolution_clock::now();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		player->Update(elapsed.count(), &event);
		enemies->Update(elapsed.count());
		window.clear();

		for (const auto& it : Bullet::GetAllBullets())
		{
			it.second->Update(elapsed.count());
			it.second->Draw(&window);
		}

		enemies->Draw(&window);
		player->Draw(&window);
		window.display();
		finish = std::chrono::high_resolution_clock::now();
		elapsed = finish - start;
	}

	return 0;
}
