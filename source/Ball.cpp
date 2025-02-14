#include "Ball.hpp"

#define MAX_SPEED 400
#define ACCELERATION 15

#include <cstdio>

Ball::Ball(float wWidth, float wHeight, const Paddle& p1, const Paddle& p2)
    : WIN_WIDTH(wWidth), WIN_HEIGHT(wHeight), p1(p1), p2(p2)
{
    xDir = 0.f;
    reset(1);
}

void Ball::update(float dt)
{
    sf::Vector2f velocity;
    
    if(body.getPosition().y + body.getRadius() >= WIN_HEIGHT) reset(-1);
    else if(body.getPosition().y - body.getRadius() <= 0) reset(1);

    if(body.getPosition().x + body.getRadius() >= WIN_WIDTH) xDir = -xDir;
    else if(body.getPosition().x - body.getRadius() <= 0) xDir = -xDir;
    
    if(isColliding(p1) || isColliding(p2)) yDir *= -1;

    velocity.x = xDir*speed;
    velocity.y = yDir*speed;

    body.move(velocity*dt);

    speed += ACCELERATION*dt;
    if(speed > MAX_SPEED) speed = MAX_SPEED;
}

void Ball::render(sf::RenderWindow& window)
{
    window.draw(body);
}

void Ball::reset(float dir)
{
    body.setFillColor(sf::Color::White);
    body.setRadius(10);
    body.setOrigin(body.getRadius(), body.getRadius());
    body.setPosition(WIN_WIDTH/2, WIN_HEIGHT/2);
 
    speed = 200;

    yDir = dir;
    xDir = (xDir)? (-xDir)*(-xDir) : 1.f; 
}

bool Ball::isColliding(const Paddle& p)
{
    sf::Vector2f circleCenter = body.getPosition();
    float radius = body.getRadius();
        
    sf::Vector2f boxPos = p.getBody().getPosition() - p.getBody().getSize()*0.5f;
    sf::Vector2f boxSize = p.getBody().getSize();
        
    float closestX = std::max(boxPos.x, std::min(circleCenter.x, boxPos.x + boxSize.x));
    float closestY = std::max(boxPos.y, std::min(circleCenter.y, boxPos.y + boxSize.y));
        
    float distanceX = abs(circleCenter.x - closestX);
    float distanceY = abs(circleCenter.y - closestY);
    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
        
    return distanceSquared <= (radius * radius);
}
