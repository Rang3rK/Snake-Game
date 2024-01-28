//
// Created by Nu lar on 11/18/23.
//

#include "SnakeGame.h"

SnakeGame::SnakeGame()
    : snakef()
{
    if(!font.loadFromFile("Font/OpenSans-Bold.ttf"))
        exit(3);
    this->text_score.setFont(font);
    this->text_score.setCharacterSize(20);
    this->text_score.setFillColor(sf::Color::White);
    this->text_score.setString("Score: " + std::to_string(score));

}

//generate fruit at random position within window and not snake's position
void SnakeGame::generateFruit()
{
    srand(time(0));
    x_coord = rand() % static_cast<int>(Snake::window_Width - Snake::snake_width);
    y_coord = rand() % static_cast<int>(Snake::window_Height - Snake::snake_height);
    fruits.push_back(Fruit({static_cast<float>(x_coord), static_cast<float>(y_coord)}));
}

//update conditions of fruit and snake
void SnakeGame::game_update() {

    if(fruits.empty())
        generateFruit();
    checkFruitCollision(fruits);
    snakef.update();
}

void SnakeGame::checkFruitCollision(std::vector<Fruit>& fruits)
{
    for(auto i = fruits.begin(); i != fruits.end(); i++)
    {
        if(i->getCircleBounds().intersects(snakef.getHeadBounds()))
        {
            //std::cout<<"FRUITT HITTT"<<std::endl;
            fruits.erase(i);
            generateFruit();
            snakef.grow();
            //std::cout<<"Fruit size: "<<fruits.size()<<std::endl;

            //std::cout<<"SIZEEEE SNAKE :"<< snakef.getSize()<<std::endl;
            score++;
            text_score.setString("Score: " + std::to_string(score));
            break;
        }
    }
}

void SnakeGame::setText(const std::string& text)
{

    this->text_score.setString(text);
}

void SnakeGame::draw(sf::RenderTarget& window, sf::RenderStates states) const
{

    for(auto& x : fruits)
        window.draw(x);
    window.draw(text_score);
    window.draw(snakef);
}

bool SnakeGame::gamecheck()
{
    return checkstatus();
}