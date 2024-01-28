
 //Created by Nu lar on 12/3/23.


#ifndef SNAKEGAME_SCREEN_H
#define SNAKEGAME_SCREEN_H
#include<SFML/Graphics.hpp>
#include "SnakeGame.h"
#include "Button.h"

class Screen : public SnakeGame
{
private:
    SnakeGame game;
    Button start, quit, sn;
    sf::Text text_score;
    sf::Text gametext;

public:
    Screen();

    void run();
    void setText(const std::string& text) override;
    void draw(sf::RenderTarget& window, sf::RenderStates) const override;
};


#endif //SNAKEGAME_SCREEN_H
