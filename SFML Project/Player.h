#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
private:
	float isHurt = 0;
	int hits = 0;
	bool dead = false;
	bool isPlayer2;

	sf::Texture HPBlock;
	sf::RectangleShape HP;

	sf::Texture hurtBlock;
	sf::RectangleShape hurt;

	int bombSize;
	sf::RectangleShape player;
	sf::Texture playerTexture;
	float speed;
	int animation;
	bool isMoveLeft, isMoveRight, isMoveDown, isMoveUp;

	float timeTotal;
	float timePerFrame;
	int imageCount;
	sf::IntRect currentFrame;
public:
	Player(const bool isPlayer2 = 0);

	void moveLeft(bool isMovingLeft);
	void moveLeft(float deltaTime);
	
	void moveUp(bool isMovingUp);
	void moveUp(float deltaTime);
	
	void moveDown(bool isMovingDown);
	void moveDown(float  deltaTime);
	
	void moveRight(bool isMovingRight);
	void moveRight(float  deltaTime);

	void killPlayer();


	bool getLeft() const;
	bool getUp() const;
	bool getDown() const;
	bool getRight() const;

	void increasSpeed();
	void increasBombSize();

	sf::Vector2f getPosition() const;

	void update(const float & deltaTime);
	void draw(sf::RenderWindow & renderWindow, float deltaTime) ;
	
};

#endif // !PLAYER_H
