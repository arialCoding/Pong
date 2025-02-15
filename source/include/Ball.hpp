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

    inline bool scoreFor1() { return P1Scored; }
    inline bool scoreFor2() { return P2Scored; }

    inline void resetScored() { P1Scored = P2Scored = false; }

private:
    bool isColliding(Paddle& p);

private:
    sf::CircleShape body;
    
    Paddle& p1, &p2;

    float xDir, yDir;
    float speed;

    const float WIN_WIDTH, WIN_HEIGHT;

    bool P1Scored;
    bool P2Scored;

    bool& paused;

};