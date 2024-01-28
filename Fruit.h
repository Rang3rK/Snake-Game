//
// Created by Nu lar on 11/28/23.
//

#ifndef SNAKEGAME_FRUIT_H
#define SNAKEGAME_FRUIT_H
#include <SFML/Graphics.hpp>

class Fruit : public sf::Drawable {
private:
    sf::CircleShape circle;

public:
    Fruit();
    Fruit(sf::Vector2f position);
    sf::FloatRect getCircleBounds();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SNAKEGAME_FRUIT_H
