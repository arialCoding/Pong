#pragma once

#include <SFML/Graphics.hpp>


class Ball
{
public:
    Ball(float wWidth, float wHeight);

    void update(float dt);
    void render(sf::RenderWindow& window);

    void reset(int dir);

private:
    sf::CircleShape body;
    
    int direction;
    float speed;

    const float WIN_WIDTH, WIN_HEIGHT;

};