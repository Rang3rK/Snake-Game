//
// Created by Nu lar on 11/18/23.

#include "Snake.h"

const float Snake::snake_width=10.f;
const float Snake::snake_height=10.f;

const int Snake::window_Width=600;
const int Snake::window_Height=600;

Snake::Snake()
{

};

Snake::Snake(sf::Vector2f startPos)
    : snake_pos(startPos)
{
    rect.setSize({snake_width,snake_height});
    rect.setPosition(startPos);
    rect.setFillColor(sf::Color::Green);

};

Snake::Snake(sf::Vector2f startPos, sf::Color color)
{
    rect.setFillColor(color);
    rect.setPosition(startPos);
}

sf::Vector2f Snake::getPosition()
{
    return snake_pos;
}

void Snake::setPosition(sf::Vector2f newPosition)
{
    rect.setPosition(newPosition);
}

void Snake::move_snake(float x, float y)
{
    snake_pos.x += x;
    snake_pos.y += y;
    rect.setPosition(snake_pos);
}

sf::FloatRect Snake::getBounds()
{
    return rect.getGlobalBounds();
}

void Snake::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect, states);
}

