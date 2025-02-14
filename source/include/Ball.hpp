#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Ball
{
public:
    Ball(float wWidth, float wHeight, Paddle& p1, Paddle& p2, bool& paused);

    void update(float dt);
    void render(sf::RenderWindow& window);

    void reset(float dir);

private:
    bool isColliding(Paddle& p);

private:
    sf::CircleShape body;
    
    Paddle& p1, &p2;

    float xDir, yDir;
    float speed;

    const float WIN_WIDTH, WIN_HEIGHT;

    bool& paused;

};