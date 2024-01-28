#include "SnakeFunction.h"


int SnakeFunction::init_size=5;

SnakeFunction::SnakeFunction()
    : direction(Direction::UP)
{
    init_snake();
}

void SnakeFunction::init_snake()
{
    //center of window
    for (int i = 0; i < SnakeFunction::init_size; i++)
    {
        snake.push_back(Snake(sf::Vector2f(
                Snake::window_Width / 2 - Snake::snake_width / 2,
                Snake::window_Height / 2 - (Snake::snake_height / 2) + (Snake::snake_height * i))));
    }

}

void SnakeFunction::key()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction = Direction::UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction = Direction::DOWN;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction = Direction::LEFT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = Direction::RIGHT;
    }
}

void SnakeFunction::move_snakeDirection() {

    for (int i = snake.size(); i > 0; i--)
    {
        snake[i] = snake[i - 1];
    }

    switch (direction)
    {
        case Direction::UP :
            snake[0].move_snake(0, -speed_x);
            break;
        case Direction::DOWN :
            snake[0].move_snake(0, speed_x);
            break;
        case Direction::LEFT :
            snake[0].move_snake(-speed_y, 0);
            break;
        case Direction::RIGHT :
            snake[0].move_snake(speed_y, 0);
            break;
    }
}

void SnakeFunction::grow()
{
    sf::Vector2f f = snake.back().getPosition();
    switch(direction) {
        case Direction::UP:
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y + Snake::snake_height)));
        case Direction::DOWN:
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));
            snake.emplace_back(Snake(sf::Vector2f(f.x, f.y - Snake::snake_height)));
            break;
        case Direction::LEFT:
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x - Snake::snake_width, f.y)));
            break;
        case Direction::RIGHT:
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));
            snake.emplace_back(Snake(sf::Vector2f(f.x + Snake::snake_width, f.y)));
            break;
    }
}

//game will if hit wall
void SnakeFunction::checkBoundCollision()
{
    check = false;
    if(snake[0].getPosition().x > Snake::window_Width)
    {
        check = true;
        exit(0);
    }
    else if (snake[0].getPosition().x < 0)
    {
        check = true;
        exit(0);

    }
    else if (snake[0].getPosition().y > Snake::window_Height)
    {
        check = true;
        exit(0);
    }
    else if (snake[0].getPosition().y < 0)
    {
        check = true;
        exit(0);
    }
}

void SnakeFunction::checkSelfCollision()
{
    Snake& headNode = snake[0];
    for (int i= 1; i < snake.size(); ++i)
    {
        if (headNode.getPosition() == snake[i].getPosition())
        {
            hitItself =true;
        }
    }
}

int SnakeFunction::getSize() {
    return snake.size();
}

void SnakeFunction::update()
{
    key();
    move_snakeDirection();
    checkSelfCollision();
    checkBoundCollision();
}

sf::FloatRect SnakeFunction::getHeadBounds() {
    return snake[0].getBounds();
}

void SnakeFunction::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(auto &x : snake)
    {
        window.draw(x);
    }
}

int SnakeFunction::getSpeedX() {
    return speed_x;
}

int SnakeFunction::getSpeedY()
{
    return speed_y;
}

void SnakeFunction::setSpeedX(int a) {
    speed_x = a;
}

void SnakeFunction::setSpeedY(int a) {
    speed_y = a;
}

bool SnakeFunction::checkstatus() const {
    return check;
}

