#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class chat
{
private:
	sf::Texture chatBlock;
	sf::RectangleShape chat1;

	sf::Texture block1Block;
	sf::RectangleShape block1;

	int posY = 64 * 8 - 18;
	int posX = 64 * 12 + 16;
	int orgPosY = 64 * 8 - 18;
	int test = 170;
public:
	chat();
	~chat();
	bool update(float deltaTime);
	void draw(sf::RenderWindow & renderWindow);
};

