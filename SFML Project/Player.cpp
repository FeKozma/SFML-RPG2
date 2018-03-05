#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(const bool isPlayer2)
{
	this->isPlayer2 = isPlayer2;

	bombSize = 3;
	speed = 80.00;
	animation = 0;
	player.setSize(sf::Vector2f(64.0f, 64.0f));
	if (!isPlayer2)
	{
		player.setPosition(sf::Vector2f(64.0f, 64.0f));
	}
	if (isPlayer2)
	{
		player.setPosition(sf::Vector2f(11*64, 7*64));
	}

	if (playerTexture.loadFromFile("../Resources/player" + std::to_string(isPlayer2 + 1) + ".png"))
	{
		player.setTexture(&playerTexture);
	}
	else
	{
		std::cout << "oh no texture did not work\n";
	}
	if (HPBlock.loadFromFile("../Resources/hp.png"))
	{
		HP.setSize(sf::Vector2f(64, 64 / 2));
		HP.setOrigin(sf::Vector2f(0, 64/2));
		HP.setTexture(&HPBlock);
	}
	else
	{
		std::cout << "did not load \"Health point\" texture\n";
	}

	if (hurtBlock.loadFromFile("../Resources/player2Hit.png"))
	{
		hurt.setSize(sf::Vector2f(64, 64));
		hurt.setTexture(&hurtBlock);
	}
	else
	{
		std::cout << "did not load \"hurt\" texture\n";
	}

	isMoveLeft = false;
	isMoveRight = false;
	isMoveUp = false;
	isMoveDown = false;

	timeTotal = 0;
	timePerFrame = 0.1;
	imageCount = 1;
	currentFrame.width = 64;
	currentFrame.height = 64;
	
	currentFrame.left = imageCount * currentFrame.width;
	currentFrame.top = animation * currentFrame.height;
	player.setTextureRect(currentFrame);

}

void Player::moveLeft(bool isMovingLeft)
{
	isMoveLeft = isMovingLeft;
}

void Player::moveLeft(float  deltaTime)
{
	player.move(-(speed*deltaTime), 0);
}

void Player::moveUp(bool isMovingUp)
{
	isMoveUp = isMovingUp;
}

void Player::moveUp(float deltaTime)
{
	player.move(0, -(speed*deltaTime));
}

void Player::moveDown(bool isMovingDown)
{
	isMoveDown = isMovingDown;
}

void Player::moveDown(float deltaTime)
{
	player.move(0, speed * deltaTime);
}

void Player::moveRight(bool isMovingRight)
{
	isMoveRight = isMovingRight;
}

void Player::moveRight(float  deltaTime)
{
	player.move(speed*deltaTime , 0);
}

void Player::killPlayer()
{
	if (isHurt <= 0)
	{
		hits++;
	}
	isHurt = 0.3;
}

bool Player::getLeft() const
{
	return this->isMoveLeft;
}

bool Player::getUp() const
{
	return this->isMoveUp;
}

bool Player::getDown() const
{
	return this->isMoveDown;
}

bool Player::getRight() const
{
	return this->isMoveRight;
}

void Player::increasSpeed()
{
	this->speed += 30;
}

void Player::increasBombSize()
{
	bombSize++;
}

sf::Vector2f Player::getPosition() const
{
	return player.getPosition();
}



void Player::update(const float & deltaTime) 
{
	//ta bort komentarer om karaktärer ska röra sig saktare diagonalt
	if (isMoveLeft) 
	{
		moveLeft(deltaTime);
		//player.move(-(speed*deltaTime) + ((isMoveDown || isMoveUp) == true ? (speed*deltaTime) / 2 : 0), 0);
		animation = 1;
	}
	if (isMoveUp) 
	{
		moveUp(deltaTime);
		//player.move(0, -(speed*deltaTime) + ((isMoveLeft || isMoveRight) == true ? (speed*deltaTime) / 2 : 0));
		animation = 3;
	}
	if (isMoveDown) 
	{
		moveDown(deltaTime);
		//player.move(0, speed * deltaTime - ((isMoveLeft || isMoveRight) == true ? (speed*deltaTime) / 2 : 0));
		animation = 0;
	}
	if (isMoveRight) 
	{
		moveRight(deltaTime);
		//player.move(speed*deltaTime - ((isMoveDown || isMoveUp) == true ? (speed*deltaTime) / 2 : 0), 0);
		animation = 2;
	}
	
	timeTotal += deltaTime;
	if (isPlayer2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//  no key do not move
	{
		if (timeTotal >= timePerFrame)
		{
			timeTotal -= timePerFrame;
		}
	}
	else if (!isPlayer2 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (timeTotal >= timePerFrame)
		{
			timeTotal -= timePerFrame;
		}
	}
	else if (timeTotal >= timePerFrame)
	{
		timeTotal -= timePerFrame;
		imageCount++;
		if (imageCount > 3)
		{
			imageCount = 0;
		}
		currentFrame.left = imageCount * currentFrame.width;
		currentFrame.top = animation * currentFrame.height;
		player.setTextureRect(currentFrame);
	}

}

void Player::draw(sf::RenderWindow & renderWindow, float deltaTime) 
{



	if (isHurt > 0 && !dead)
	{
		if (hits == 1)
		{
			if (HPBlock.loadFromFile("../Resources/hp1.png"))
			{
				HP.setSize(sf::Vector2f(64, 64 / 2));
				HP.setOrigin(sf::Vector2f(0, 64 / 2));
				HP.setTexture(&HPBlock);
			}
			else
			{
				std::cout << "did not load \"Health point1\" texture\n";
			}
		}
		else if (hits == 2)
		{
			if (HPBlock.loadFromFile("../Resources/hp2.png"))
			{
				HP.setSize(sf::Vector2f(64, 64 / 2));
				HP.setOrigin(sf::Vector2f(0, 64 / 2));
				HP.setTexture(&HPBlock);
			}
			else
			{
				std::cout << "did not load \"Health point2\" texture\n";
			}
		}
		else
		{
			if (HPBlock.loadFromFile("../Resources/hp3.png"))
			{
				HP.setSize(sf::Vector2f(64, 64 / 2));
				HP.setOrigin(sf::Vector2f(0, 64 / 2));
				HP.setTexture(&HPBlock);
				dead = true;
				isHurt = 0.3;
				hits = 6;
			}
			else
			{
				std::cout << "did not load \"Health point3\" texture\n";
			}
		}

		HP.setPosition(player.getPosition());
		renderWindow.draw(HP);

		isHurt = isHurt - deltaTime;
		player.setTexture(&hurtBlock);
		renderWindow.draw(player);
	}
	else
	{
		if (dead)
		{
			if (hits >= 0)
			{
				isHurt = isHurt - deltaTime;
				if (isHurt <= 0)
				{

					isHurt = 0.24;
					hits--;
				}
				HP.setPosition(player.getPosition());
				renderWindow.draw(HP);
				if (hits % 2 == 0)
				{	


					player.setTexture(&hurtBlock);
					renderWindow.draw(player);

				}
				else
				{
					int i = 0;
				}
			}
		}
		else
		{
			HP.setPosition(player.getPosition());
			renderWindow.draw(HP);


			player.setTexture(&playerTexture);
			renderWindow.draw(player);
		}

	}

}
