#pragma once
#include <SFML/Graphics.hpp>

class Inventory
{
private: 
	sf::Texture empty;
	sf::RectangleShape emptyBlock;

	sf::Texture ax;
	sf::RectangleShape axBlock;

	sf::Texture highLight;
	sf::RectangleShape highLightBlock;

	sf::Texture skillAnimation;
	sf::RectangleShape skillAnimationBlock;
	sf::IntRect currentFrame;

	sf::Texture energy;
	sf::RectangleShape energyBlock;

	sf::Texture inv;
	sf::RectangleShape invBlock;

	sf::Texture f1;
	sf::RectangleShape f1Block;
	sf::Texture f2;
	sf::RectangleShape f2Block;
	sf::Texture f3;
	sf::RectangleShape f3Block;

	sf::Texture _1;
	sf::RectangleShape _1Block;
	sf::Texture _2;
	sf::RectangleShape _2Block;
	sf::Texture _3;
	sf::RectangleShape _3Block;


	int skill1 = -1;


	float timePerFrame = 0.3;
	float timeOnThisFrame = 0; 

public:
	Inventory();
	~Inventory();
	void draw(sf::RenderWindow & renderWindow, int height, int with);
	int updateSkill1(float deltaTime);
	
};

