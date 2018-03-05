#include "Inventory.h"
#include <iostream>


Inventory::Inventory()
{
	axBlock.setSize(sf::Vector2f(64.0f, 64.0f));
	if (ax.loadFromFile("../Resources/inventoryAx.png"))
	{
		axBlock.setTexture(&ax);
	}
	else
	{
		std::cout << "did not load inventoryAx texture\n";
	}

	highLightBlock.setSize(sf::Vector2f(64.0f, 64.0f));
	if (highLight.loadFromFile("../Resources/inventoryHigh.png"))
	{
		highLightBlock.setTexture(&highLight);
	}
	else
	{
		std::cout << "did not load inventoryAx texture\n";
	}

	invBlock.setSize(sf::Vector2f(64.0f, 64.0f));
	if (inv.loadFromFile("../Resources/inv.png"))
	{
		invBlock.setTexture(&inv);
	}
	else
	{
		std::cout << "did not load inv texture\n";
	}
	
	emptyBlock.setSize(sf::Vector2f(64.0f, 64.0f));
	if (empty.loadFromFile("../Resources/inventory.png"))
	{
		emptyBlock.setTexture(&empty);
	}
	else
	{
		std::cout << "did not load emptyBlock texture\n";
	}

	skillAnimationBlock.setSize(sf::Vector2f(64, 64));
	if (skillAnimation.loadFromFile("../Resources/timer.png"))
	{
		skillAnimationBlock.setTexture(&skillAnimation);

		currentFrame.width = 64;
		currentFrame.height = 64;

		currentFrame.left = 0;
		currentFrame.top = 0;
		skillAnimationBlock.setTextureRect(currentFrame);

	}
	else
	{
		std::cout << "did not load skillAnimation texture\n";
	}

	energyBlock.setSize(sf::Vector2f(64, 64));
	if (energy.loadFromFile("../Resources/explosionBlock6.png"))
	{
		energyBlock.setTexture(&energy);
	}



	//load nrs
	f1Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (f1.loadFromFile("../Resources/f1.png"))
	{
		f1Block.setTexture(&f1);
	}
	else
	{
		std::cout << "did not load f1 texture\n";
	}
	f2Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (f2.loadFromFile("../Resources/f2.png"))
	{
		f2Block.setTexture(&f2);
	}
	else
	{
		std::cout << "did not load f2 texture\n";
	}
	f3Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (f3.loadFromFile("../Resources/f3.png"))
	{
		f3Block.setTexture(&f3);
	}
	else
	{
		std::cout << "did not load f3 texture\n";
	}


	_1Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (_1.loadFromFile("../Resources/1.png"))
	{
		_1Block.setTexture(&_1);
	}
	else
	{
		std::cout << "did not load 1 texture\n";
	}
	_2Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (_2.loadFromFile("../Resources/2.png"))
	{
		_2Block.setTexture(&_2);
	}
	else
	{
		std::cout << "did not load 2 texture\n";
	}
	_3Block.setSize(sf::Vector2f(64.0f, 64.0f));
	if (_3.loadFromFile("../Resources/3.png"))
	{
		_3Block.setTexture(&_3);
	}
	else
	{
		std::cout << "did not load 3 texture\n";
	}


}


Inventory::~Inventory()
{
}

void Inventory::draw(sf::RenderWindow & renderWindow, int height, int with)
{


	axBlock.setPosition(sf::Vector2f((float(((with / 2) - 3) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(axBlock);

	f1Block.setPosition(sf::Vector2f((float(((with / 2) - 3) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(f1Block);

	//----
	emptyBlock.setPosition(sf::Vector2f((float(((with / 2) - 2) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(emptyBlock);

	f2Block.setPosition(sf::Vector2f((float(((with / 2) - 2) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(f2Block);

	//----

	emptyBlock.setPosition(sf::Vector2f((float(((with / 2) - 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(emptyBlock);
	f3Block.setPosition(sf::Vector2f((float(((with / 2) - 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(f3Block);

	//----

	invBlock.setPosition(sf::Vector2f((float(((with / 2) - 0) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(invBlock);


	//----

	highLightBlock.setPosition(sf::Vector2f((float(((with / 2) + 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(highLightBlock);

	_1Block.setPosition(sf::Vector2f((float(((with / 2) + 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(_1Block);

	//----
	energyBlock.setPosition(sf::Vector2f((float(((with / 2) + 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(energyBlock);

	_1Block.setPosition(sf::Vector2f((float(((with / 2) + 1) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(_1Block);

	//----
	emptyBlock.setPosition(sf::Vector2f((float(((with / 2) + 2) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(emptyBlock);

	_2Block.setPosition(sf::Vector2f((float(((with / 2) + 2) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(_2Block);

	//----
	emptyBlock.setPosition(sf::Vector2f((float(((with / 2) + 3) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(emptyBlock);

	_3Block.setPosition(sf::Vector2f((float(((with / 2) + 3) * 64)), (float((height - 1) * 64))));
	renderWindow.draw(_3Block);

	if (skill1 != -1)
	{
		currentFrame.left = this->skill1 * 64;
		skillAnimationBlock.setTextureRect(currentFrame);

		skillAnimationBlock.setPosition(sf::Vector2f((float(((with / 2) + 1) * 64)), (float((height - 1) * 64))));
		renderWindow.draw(skillAnimationBlock);
	}
}

int Inventory::updateSkill1(float deltaTime)
{
	timeOnThisFrame = timeOnThisFrame - deltaTime;

	//std::cout << std::to_string(deltaTime) + '\n';
	//std::cout << "timeOnThisFrame: " + std::to_string(timeOnThisFrame) + '\n';
	if (timeOnThisFrame < 0)
	{
		if (skill1 < 10)
		{
			skill1++;
			timeOnThisFrame = timePerFrame;

			return true;
		}
		else
		{
			skill1 = -1;
			timeOnThisFrame = 0;

			return false;
		}
	}

	
}

