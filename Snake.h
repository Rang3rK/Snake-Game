//
// Created by Nu lar on 11/18/23
#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Snake : public sf::Drawable {
private:
    sf::Vector2f snake_pos;
    sf::RectangleShape rect;
public:
    Snake();
    Snake(sf::Vector2f startPos);
    Snake(sf::Vector2f startPos, sf::Color color);

    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition();

    void move_snake(float x, float y);

    sf::FloatRect getBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    static const float snake_width;
    static const float snake_height;

    static const int window_Width;
    static const int window_Height;

};


#endif //SNAKEGAME_SNAKE_H
