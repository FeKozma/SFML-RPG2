#include "chat.h"



chat::chat()
{
	if (chatBlock.loadFromFile("../Resources/chat.png"))
	{
		chat1.setSize(sf::Vector2f(192, 147));
		chat1.setTexture(&chatBlock);
		chat1.setOrigin(0, -170);
		chat1.setPosition(sf::Vector2f(posX, posY - 170));

	}
	else
	{
		std::cout << "did not load chat  texture\n";
	}
	if (block1Block.loadFromFile("../Resources/block1.png"))
	{
		
		block1.setSize(sf::Vector2f(64, 64));
		block1.setTexture(&block1Block);
	}
	else
	{
		std::cout << "did not load block1Block in chat  texture\n";
	}
}


chat::~chat()
{
}

bool chat::update(float deltaTime)
{
	test = test - deltaTime/32;
	if (test < 0)
	{
		test = 170;
		return false;
	}
	chat1.setPosition(sf::Vector2f(posX, posY - test));
	return true;
}

void chat::draw(sf::RenderWindow & renderWindow)
{
	renderWindow.draw(chat1);
	block1.setPosition(64 * 12, 64 * 10);
	renderWindow.draw(block1);
	block1.setPosition(64 * 13, 64 * 10);
	renderWindow.draw(block1);
	block1.setPosition(64 * 14, 64 * 10);
	renderWindow.draw(block1);
	block1.setPosition(64 * 15, 64 * 10);
	renderWindow.draw(block1);
}


//chat.setPosition(sf::Vector2f(64*12 + 16, 64*8-18));
//renderWindow.draw(chat);