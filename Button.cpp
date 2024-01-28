//
// Created by Nu lar on 11/14/23.
//

#include "Button.h"

#include <utility>

Button::Button()
    : Button("1")
{

}

Button::Button(const std::string& text)
    : Button(text, 32)
{

}

Button::Button(const std::string& text, float radius)
    : Button(text, radius, Font::getFont(OPEN_SANS))
{

}

Button::Button(const std::string& text, float radius, sf::Font& font)
    : defaultColor(50,50,50), clickColor(212,212,210)
{
    setupCircle(radius);
    setupText(text, font);
}

void Button::setupText(const std::string& text, sf::Font& font)
{
    this->text.setFont(font);
    this->text.setString(text);
    setCharSize(0);
}

void Button::setupCircle(float radius)
{
    setRadius(radius);
    circle.setFillColor(defaultColor);
}

void Button::setRadius(float radius)
{
    circle.setRadius(radius);
    setCharSize(radius);
}

void Button::setFont(const sf::Font& font)
{
    text.setFont(font);
}

void Button::setText(const std::string& text)
{
    this->text.setString(text);
}

void Button::setCharSize(int i)
{
    this->text.setCharacterSize(i);
    Position::centerText(circle,this->text);
}

std::string Button::getText()
{
    return text.getString();
}

void Button::setClickColor(sf::Color color)
{
    clickColor = color;
}

void Button::setDefaultColor(sf::Color color)
{
    defaultColor = color;
}

void Button::setPosition(sf::Vector2f position)
{
    this->circle.setPosition(position);
}

sf::CircleShape& Button::getCircle()
{
    return this->circle;
}

void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(!getState(HIDDEN)) {
        states.transform = circle.getTransform();
        window.draw(circle);
        window.draw(text, states);
    }
}

void Button::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    if(MouseEvent::isClicked(circle,window))
    {
        enableState(CLICKED);
    }
    else
        disableState(CLICKED);
}

void Button::update()
{
    if(getState(CLICKED))
        circle.setFillColor(clickColor);
    else
        circle.setFillColor(defaultColor);
}

//button is child of States