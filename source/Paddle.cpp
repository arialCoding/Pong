#include "Paddle.hpp"


Paddle::Paddle(float wWidth, float wHeight) : WIN_WIDTH(wWidth), WIN_HEIGHT(wHeight)
{
    reset();
}


void Paddle::update(float dt)
{
    sf::Vector2f velocity(0, 0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) velocity.x -= speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x += speed;


    body.move(velocity*dt);
}

void Paddle::render(sf::RenderWindow& window)
{
    window.draw(body);
}

void Paddle::reset()
{
    body.setSize(sf::Vector2f(150, 10));
    body.setOrigin(body.getSize()*0.5f);
    body.setPosition(WIN_WIDTH/2, 0.9*WIN_HEIGHT);

    body.setFillColor(sf::Color::White);

    speed = 200;
}
