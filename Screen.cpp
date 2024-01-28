//Created by Nu lar on 12/3/23.

#include "Screen.h"

Screen::Screen()
{
    this->text_score.setCharacterSize(20);
    this->text_score.setFillColor(sf::Color::White);
    this->text_score.setString("Score");

    start.setRadius(35);
    start.setText("Start");
    start.setCharSize(30);
    start.setPosition({200,300});

    quit.setRadius(35);
    quit.setText("Quit");
    quit.setCharSize(30);
    quit.setPosition({320, 300});

    sn.setRadius(0);
    sn.setText("Snake Game\n\nCS3A\nFINAL PROJECT");
    sn.setCharSize(30);
    sn.setPosition({300,100});

}

void Screen::setText(const std::string& text)
{
    this->text_score.setString(text);
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates) const
{
    window.draw(text_score);
    window.draw(start);
    window.draw(quit);
    window.draw(sn);
}

void Screen::run() {

    sf::RenderWindow window({600, 600, 64}, "Snake");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        bool isMenu = true;
        while (isMenu)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (sf::Event::Closed == event.type)
                    window.close();
                else if (event.type == sf::Event::MouseButtonPressed)
                    if (MouseEvent::isHovered(start.getCircle(), window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        isMenu = false;
                    else if (MouseEvent::isHovered(quit.getCircle(), window) &&
                        sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        window.close();
            }
            window.clear();
            window.draw(*this);  // Draw the menu screen
            window.display();
        }

        game.generateFruit();
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (sf::Event::Closed == event.type)
                    window.close();
            }

            game.game_update();
            window.clear();
            window.draw(game);
            window.display();
        }
    }
}
