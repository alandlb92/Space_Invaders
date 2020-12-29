#include <SFML/Graphics.hpp>
#include <iostream>
#include "Body.h"
#include "Player.h"
#include "Bullet.h"
#include <chrono>
#include <vector>

const sf::Vector2f windowSize(1000, 800);
std::vector<Bullet*> Bullet::bulletList;

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Invaders");
	Player player(Body::BodyType::PLAYER, windowSize);
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
		player.Update(elapsed.count(), &event);

		window.clear();

		if (!Bullet::GetAllBullets().empty())
			for (int i = 0; i < Bullet::GetAllBullets().size(); i++)
			{
				Bullet::GetAllBullets()[i]->Update(elapsed.count());
				Bullet::GetAllBullets()[i]->Draw(&window);
			}


		player.Draw(&window);
		window.display();
		finish = std::chrono::high_resolution_clock::now();
		elapsed = finish - start;
	}

	return 0;
}
