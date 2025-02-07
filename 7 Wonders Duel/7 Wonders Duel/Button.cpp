#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
    : buttonState(BTN_IDLE), pressed(false), hover(false), toggled(false) {
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

Button::~Button() {}

const bool Button::isPressed() const {
    return this->buttonState == BTN_ACTIVE;
}

const bool Button::isToggled() const {
    return this->toggled;
}

const sf::Text& Button::getText() const {
    return this->text;
}

void Button::toggle() {
    this->toggled = !this->toggled;
    this->shape.setFillColor(this->toggled ? this->activeColor : this->idleColor);
}

void Button::update(const sf::Vector2f mousePos) {
    this->buttonState = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos)) {
        this->buttonState = BTN_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BTN_ACTIVE;
            this->toggled = !this->toggled; // Toggle the state
        }
    }

    switch (this->buttonState) {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;
    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;
    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        break;
    default:
        this->shape.setFillColor(sf::Color::Red);
        break;
    }
}

void Button::render(sf::RenderTarget* target) {
    target->draw(this->shape);
    target->draw(this->text);
}
