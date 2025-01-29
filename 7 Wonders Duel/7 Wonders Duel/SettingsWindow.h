#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <SFML/Graphics.hpp>
#include <string>

class SettingsWindow {
public:
    SettingsWindow(const std::string& configFilePath);
    ~SettingsWindow();

    void render(sf::RenderWindow& window);
    bool isOpen() const;
    void close();

private:
    void loadSettings(const std::string& configFilePath);
    void initText();

    sf::RenderWindow settingsWindow;
    sf::Font font;
    sf::Text settingsText;
    bool open;
};

#endif // SETTINGSWINDOW_H
