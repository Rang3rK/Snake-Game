//
// Created by Nu lar on 11/28/23.
//

#include "Fruit.h"

Fruit::Fruit()
{

}

Fruit::Fruit(sf::Vector2f position)
{
    circle.setRadius(8);    //fixed radius
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(position);
}

sf::FloatRect Fruit::getCircleBounds()
{
    return circle.getGlobalBounds();
}

void Fruit::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(circle);
}

