#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"

class Game
{
public:
    Game();
    int Run();

private:
    void handleEvent();
    void update(float dt);
    void render();

private:
    sf::RenderWindow window;
    sf::Event event;

    Ball ball;

    Paddle paddle1, paddle2;

};