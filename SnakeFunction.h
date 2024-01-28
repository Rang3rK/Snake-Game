//
// Created by Nu lar on 11/20/23.
//

#ifndef SNAKEGAME_SNAKEFUNCTION_H
#define SNAKEGAME_SNAKEFUNCTION_H

//#include "SnakeGame.h"
#include "Snake.h"

#include <SFML/Graphics.hpp>

enum Direction
{
    UP, DOWN, LEFT, RIGHT
};

//inherit snake
class SnakeFunction : public sf::Drawable  {
private:
    std::vector<Snake> snake;
    static int init_size;
    Direction direction;

    void init_snake();
    void move_snakeDirection();
    void checkBoundCollision();
    int speed_x =5;
    int speed_y =5;
    bool check;

public:
    SnakeFunction();
    void update();
    void key();
    void grow();

    sf::FloatRect getHeadBounds();
    int getSize();
    int getSpeedX();
    void setSpeedX(int a);

    int getSpeedY();
    void setSpeedY(int a);
    bool hitItself =false;
    void checkSelfCollision();

    bool checkstatus() const;

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SNAKEGAME_SNAKEFUNCTION_H
