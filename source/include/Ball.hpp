#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Ball
{
public:
    Ball(float wWidth, float wHeight, const Paddle& p1, const Paddle& p2);

    void update(float dt);
    void render(sf::RenderWindow& window);

    void reset(float dir);

private:
    bool isColliding(const Paddle& p);

private:
    sf::CircleShape body;
    
    const Paddle& p1, &p2;

    float xDir, yDir;
    float speed;

    const float WIN_WIDTH, WIN_HEIGHT;

};