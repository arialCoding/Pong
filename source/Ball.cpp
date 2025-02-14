#include "Ball.hpp"

#include <random>

Ball::Ball(float wWidth, float wHeight) : WIN_WIDTH(wWidth), WIN_HEIGHT(wHeight)
{
    reset(1);
}

void Ball::update(float dt)
{
    sf::Vector2f velocity;
    
    if(body.getPosition().y + body.getRadius() >= WIN_HEIGHT) reset(-1);
    else if(body.getPosition().y - body.getRadius() <= 0) reset(1);

    velocity.x = speed;
    velocity.y = direction*speed;

    body.move(velocity*dt);
}

void Ball::render(sf::RenderWindow& window)
{
    window.draw(body);
}

void Ball::reset(int dir)
{
    body.setFillColor(sf::Color::White);
    body.setRadius(10);
    body.setPosition(WIN_WIDTH/2, WIN_HEIGHT/2);
 
    speed = 200;
    direction = dir;
}
