#pragma once

#include <SFML/Graphics.hpp>


class Paddle
{
public:
    Paddle(float wWidth, float wHeight);

    void update(float dt);
    void render(sf::RenderWindow& window);

    void reset();

private:
    sf::RectangleShape body;

    float speed;

    const float WIN_WIDTH, WIN_HEIGHT;
};