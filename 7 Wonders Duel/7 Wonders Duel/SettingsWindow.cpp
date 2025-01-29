#include "SettingsWindow.h"
#include "SettingsWindow.h"
#include <fstream>
#include <sstream>

SettingsWindow::SettingsWindow(const std::string& configFilePath)
    : settingsWindow(sf::VideoMode(400, 300), "Settings", sf::Style::Titlebar | sf::Style::Close), open(true)
{
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        throw "ERROR::SETTINGSWINDOW::COULD_NOT_LOAD_FONT";
    }

    loadSettings(configFilePath);
    initText();
}

SettingsWindow::~SettingsWindow() {
    settingsWindow.close();
}

void SettingsWindow::loadSettings(const std::string& configFilePath) {
    std::ifstream ifs(configFilePath);
    std::stringstream ss;
    std::string line;

    if (ifs.is_open()) {
        while (std::getline(ifs, line)) {
            ss << line << "\n";
        }
    }
    else {
        ss << "Failed to open config file.";
    }

    settingsText.setString(ss.str());
}

void SettingsWindow::initText() {
    settingsText.setFont(font);
    settingsText.setCharacterSize(16);
    settingsText.setFillColor(sf::Color::White);
    settingsText.setPosition(10, 10);
}

void SettingsWindow::render(sf::RenderWindow& window) {
    if (open) {
        settingsWindow.clear();
        settingsWindow.draw(settingsText);
        settingsWindow.display();

        sf::Event event;
        while (settingsWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                close();
            }
        }
    }
}

bool SettingsWindow::isOpen() const {
    return open && settingsWindow.isOpen();
}

void SettingsWindow::close() {
    open = false;
}
