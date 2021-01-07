#pragma once
#include"Entity.h"
class CardRender : public Entity
{
public:
	enum card_states { CARD_IDLE = 0, CARD_HOVER, CARD_ACTIVE };
	short unsigned cardState;
	float m_x, m_y;
	std::string m_name;
	bool pressed;
	bool hover;

	sf::RectangleShape shape;
	
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
public:


	sf::RectangleShape m_cardBack;
	sf::RectangleShape m_cardFace;
	void initVariables();
	void initComponents();
	CardRender();
	CardRender(float x, float y, sf::Texture* texture, sf::Color idleColor,
		sf::Color hoverColor, sf::Color activeColor, std::string name);
	CardRender(float x, float y, sf::Texture* texture);
	CardRender(sf::Texture* texture);
	sf::Mouse mouseController;
	~CardRender();
	const bool isPressed() const;
	const bool isPressedR() const;
	void pressedBoot() ;
	//Functions
	std::string getName();
	float getX();
	float getY();
	void setPosition(const float x, const float y);
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);


};

