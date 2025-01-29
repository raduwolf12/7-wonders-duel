#include "SettingsPanel.h"
#include <fstream>
#include <iostream>
#include "Game.h"

SettingsPanel::SettingsPanel()
	: isVisible(false), isResolutionDropdownVisible(false), isFramerateDropdownVisible(false), isFullscreen(false) {
	this->init();
}

SettingsPanel::SettingsPanel(Game* game)
	: gameInstance(game), isVisible(false), isResolutionDropdownVisible(false), isFramerateDropdownVisible(false) {
	this->init();
}


SettingsPanel::~SettingsPanel() {
	for (auto button : resolutionButtons) {
		delete button;
	}
	for (auto button : framerateButtons) {
		delete button;
	}
	delete fullscreenCheckbox;
	delete musicCheckbox;
	delete backButton;
}

void SettingsPanel::init() {
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		throw "ERROR::SETTINGS_PANEL::COULD_NOT_LOAD_FONT";
	}

	// Set up panel background
	panelBackground.setSize(sf::Vector2f(400.f, 400.f));
	panelBackground.setFillColor(sf::Color(50, 50, 50, 200)); // Semi-transparent background

	// Title
	titleText.setFont(font);
	titleText.setString("Settings");
	titleText.setCharacterSize(24);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(20.f, 20.f);

	// Example text for settings
	resolutionText.setFont(font);
	resolutionText.setString("Resolution:");
	resolutionText.setCharacterSize(18);
	resolutionText.setFillColor(sf::Color::White);
	resolutionText.setPosition(20.f, 60.f);

	fullscreenText.setFont(font);
	fullscreenText.setString("Fullscreen:");
	fullscreenText.setCharacterSize(18);
	fullscreenText.setFillColor(sf::Color::White);
	fullscreenText.setPosition(20.f, 140.f);

	framerateText.setFont(font);
	framerateText.setString("Framerate Limit:");
	framerateText.setCharacterSize(18);
	framerateText.setFillColor(sf::Color::White);
	framerateText.setPosition(20.f, 220.f);

	musicText.setFont(font);
	musicText.setString("Music:");
	musicText.setCharacterSize(18);
	musicText.setFillColor(sf::Color::White);
	musicText.setPosition(20.f, 300.f);

	// Initialize dropdowns and checkboxes
	initButtons();
	initDropdownButtons();
}

void SettingsPanel::initButtons() {
	fullscreenCheckbox = new Button(200, 140, 20, 20, &font, "",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	musicCheckbox = new Button(200, 300, 20, 20, &font, "",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	backButton = new Button(20, 350, 100, 30, &font, "Back",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void SettingsPanel::initDropdownButtons() {
	videoModes = sf::VideoMode::getFullscreenModes();
	for (auto& mode : videoModes) {
		resolutions.push_back(std::to_string(mode.width) + "x" + std::to_string(mode.height));
	}

	for (size_t i = 0; i < resolutions.size(); i++) {
		resolutionButtons.push_back(new Button(200, 60 + i * 30, 150, 30, &font, resolutions[i],
			sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	}

	for (size_t i = 0; i < framerateLimits.size(); i++) {
		framerateButtons.push_back(new Button(200, 220 + i * 30, 150, 30, &font, framerateLimits[i],
			sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200)));
	}
}

void SettingsPanel::toggleVisibility() {
	isVisible = !isVisible;
}

bool SettingsPanel::getVisibility() const {
	return isVisible;
}

unsigned int SettingsPanel::getWidth() const {
	std::string resolution = resolutionText.getString();
	std::size_t xPos = resolution.find('x');
	if (xPos != std::string::npos) {
		return std::stoi(resolution.substr(0, xPos));
	}
	return 800; // Default width if parsing fails
}

// Return the height of the selected resolution
unsigned int SettingsPanel::getHeight() const {
	std::string resolution = resolutionText.getString();
	std::size_t xPos = resolution.find('x');
	if (xPos != std::string::npos) {
		return std::stoi(resolution.substr(xPos + 1));
	}
	return 600; // Default height if parsing fails
}

// Return whether fullscreen is enabled
bool SettingsPanel::isFullscreenEnabled() const {
	return isFullscreen; // The original data member
}

// Return the selected framerate limit
unsigned int SettingsPanel::getFramerateLimit() const {
	std::string framerate = framerateText.getString();
	return std::stoi(framerate.substr(framerate.find(": ") + 2));  // Extract framerate value from text
}

// Return whether music is enabled
bool SettingsPanel::isMusicOn() const {
	return musicCheckbox->isToggled();  // Assuming isToggled() returns true for checked, false for unchecked
}

void SettingsPanel::update(const sf::Vector2f& mousePosition, bool mousePressed) {
	if (isVisible) {
		// Update dropdowns and checkboxes
		for (auto& button : resolutionButtons) {
			button->update(mousePosition);
			if (mousePressed && button->isPressed()) {
				resolutionText.setString("Resolution: " + button->getText().getString().toAnsiString());
				isResolutionDropdownVisible = false;
				break;
			}
		}

		for (auto& button : framerateButtons) {
			button->update(mousePosition);
			if (mousePressed && button->isPressed()) {
				framerateText.setString("Framerate Limit: " + button->getText().getString().toAnsiString());
				isFramerateDropdownVisible = false;
				break;
			}
		}

		fullscreenCheckbox->update(mousePosition);
		if (mousePressed && fullscreenCheckbox->isPressed()) {
			fullscreenCheckbox->toggle();
			fullscreenText.setString("Fullscreen: " + std::string(fullscreenCheckbox->isToggled() ? "Yes" : "No"));
			isFullscreen = fullscreenCheckbox->isToggled(); // Update fullscreen flag
		}

		musicCheckbox->update(mousePosition);
		if (mousePressed && musicCheckbox->isPressed()) {
			musicCheckbox->toggle();
			musicText.setString("Music: " + std::string(musicCheckbox->isToggled() ? "On" : "Off"));
		}

		if (mousePressed && resolutionText.getGlobalBounds().contains(mousePosition)) {
			isResolutionDropdownVisible = !isResolutionDropdownVisible;
		}

		if (mousePressed && framerateText.getGlobalBounds().contains(mousePosition)) {
			isFramerateDropdownVisible = !isFramerateDropdownVisible;
		}

		backButton->update(mousePosition);
		if (mousePressed && backButton->isPressed()) {
			toggleVisibility(); // Hide the settings panel
			// Implement the logic to return to the main menu
		}
	}
}

void SettingsPanel::render(sf::RenderTarget& target) {
	if (isVisible) {
		target.draw(panelBackground);
		target.draw(titleText);
		target.draw(resolutionText);
		target.draw(fullscreenText);
		target.draw(framerateText);
		target.draw(musicText);

		if (isResolutionDropdownVisible) {
			for (auto& button : resolutionButtons) {
				button->render(&target);
			}
		}

		if (isFramerateDropdownVisible) {
			for (auto& button : framerateButtons) {
				button->render(&target);
			}
		}

		fullscreenCheckbox->render(&target);
		musicCheckbox->render(&target);
		backButton->render(&target);
	}
}

void SettingsPanel::saveSettings() {
	// Here, add logic to save individual settings if needed

	// Call the Game class's saveWindowSettings method
	if (gameInstance) {
		gameInstance->saveWindowSettings();
	}
}

//void SettingsPanel::saveSettings() {
//	std::ofstream ofs("Config/window.ini");
//
//	if (ofs.is_open()) {
//		// Write the settings to file
//		ofs << "resolution=" << resolutionText.getString().toAnsiString() << "\n";
//		ofs << "fullscreen=" << (fullscreenCheckbox->isToggled() ? "true" : "false") << "\n";
//		ofs << "framerate=" << framerateText.getString().toAnsiString() << "\n";
//		ofs << "music=" << (musicCheckbox->isToggled() ? "true" : "false") << "\n";
//	}
//
//	ofs.close();
//}


