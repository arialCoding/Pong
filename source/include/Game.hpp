#pragma once

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"

enum gameState
{
    MAINMENU,
    PAUSED,
    PLAYING
};

class Game
{
public:
    Game();
    int Run();

private:
    void handleEvent();
    void update(float dt);
    void render();

    void updateMAINMENU(float dt);
    void updatePAUSED(float dt);
    void updatePLAYING(float dt);

    void renderMAINMENU();
    void renderPAUSED();
    void renderPLAYING();

private:
    sf::RenderWindow window;
    sf::Event event;

    Paddle paddle1, paddle2;
    
    Ball ball;


    gameState state;

    bool paused;

};