#ifndef SETTINGS_PANEL_H
#define SETTINGS_PANEL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class Game;

class SettingsPanel {
private:
	sf::RectangleShape panelBackground;
	sf::Font font;
	sf::Text titleText;
	sf::Text resolutionText;
	sf::Text fullscreenText;
	sf::Text framerateText;
	sf::Text musicText;

	std::vector<std::string> resolutions;
	std::vector<Button*> resolutionButtons;
	std::vector<Button*> framerateButtons;

	Button* fullscreenCheckbox;
	Button* musicCheckbox;
	Button* backButton;

	std::vector<sf::VideoMode> videoModes;
	std::vector<std::string> framerateLimits = { "30", "60", "120", "144", "240" };

	bool isVisible;
	bool isResolutionDropdownVisible;
	bool isFramerateDropdownVisible;

public:

	Game* gameInstance;

	bool isFullscreen;
	void init();
	void initButtons();
	void initDropdownButtons();

public:
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getFramerateLimit() const;
	bool isMusicOn() const;

	SettingsPanel();
	SettingsPanel(Game* game); // Constructor to accept the game instance
	~SettingsPanel();

	// Accessors
	bool getVisibility() const;
	bool isFullscreenEnabled() const;

	// Functions
	void toggleVisibility();
	void update(const sf::Vector2f& mousePosition, bool mousePressed);
	void render(sf::RenderTarget& target);
	void saveSettings();

};

#endif // SETTINGS_PANEL_H
