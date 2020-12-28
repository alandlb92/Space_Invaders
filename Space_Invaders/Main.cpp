#include <SFML/Graphics.hpp>
#include <iostream>
#include "Body.h"
#include "Player.h"
#include <chrono>

const sf::Vector2f windowSize(1000, 800);

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
		player.Update(elapsed.count());
		//cout << "  Delta Time:" << elapsed.count();
		window.clear();
		player.Draw(& window);
		window.display();
		finish = std::chrono::high_resolution_clock::now();
		elapsed = finish - start;
	}

	return 0;
}
