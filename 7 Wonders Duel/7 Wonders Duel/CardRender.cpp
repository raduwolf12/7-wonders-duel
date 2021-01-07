#include "CardRender.h"

void CardRender::initVariables()
{
	this->m_cardBack.setSize((sf::Vector2f(100, 100)));
}
void CardRender::initComponents()
{

}
CardRender::CardRender()
{
	//empty

}

CardRender::CardRender(float x, float y, sf::Texture* texture, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, std::string name)
{
	this->initVariables();
	this->initComponents();
	this->m_name = name;

	this->m_cardBack.setTexture(texture);
	this->createSprite(texture);
	this->setPosition(x, y);
	this->cardState = CARD_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	//this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
//	this->font = font;
	//this->text.setFont(*this->font);
	//this->text.setString(text);
	//this->text.setFillColor(sf::Color::White);
	//this->text.setCharacterSize(12);
	/*this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);
	*/
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);

}

CardRender::CardRender(float x, float y, sf::Texture* texture)
{
	this->initVariables();
	this->initComponents();
	this->m_cardBack.setTexture(texture);
	this->createSprite(texture);
	this->setPosition(x, y);
}

CardRender::CardRender(sf::Texture* texture)
{
}

CardRender::~CardRender()
{
}

const bool CardRender::isPressed() const
{
	if (this->cardState== CARD_ACTIVE)
		return true;
	return false;
}

const bool CardRender::isPressedR() const
{
	if ( sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
	
	{
		
			std::cout << "Click dreapta";
			return true;
		
	}
	return false;
}
 void CardRender::pressedBoot() 
{
	 this->cardState == CARD_ACTIVE;
		 
}


std::string CardRender::getName()
{
	return m_name;
}

float CardRender::getX()
{
	return m_x;
}

float CardRender::getY()
{
	return m_y;
}

void CardRender::setPosition(const float x, const float y)
{
	m_x = x;
	m_y = y;
	if (this->sprite)
	{
		this->sprite->setPosition(x, y);
	}
	this->shape.setPosition(x, y);
}



void CardRender::update(const sf::Vector2f mousePos)
{
	/*Update the booleans for hover and pressed*/

	//Idle
	this->cardState = CARD_IDLE;

	//Hover

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->cardState = CARD_HOVER;

		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->cardState = CARD_ACTIVE;
		}
	}
	switch (this->cardState)
	{
	case CARD_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case CARD_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case CARD_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void CardRender::render(sf::RenderTarget* target)
{

	target->draw(*this->sprite);
	target->draw(this->shape);

	
	//target->draw(this->text);
}
