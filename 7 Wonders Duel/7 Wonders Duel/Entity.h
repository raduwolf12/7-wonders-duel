#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
#include"SFML/System.hpp"
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"

class Entity
{
private:
	void initVariables();
protected:
	sf::Texture* texture;
	sf::Sprite *sprite;
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Component functions
	void createSprite(sf::Texture* texture);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt,const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr);
};

#endif