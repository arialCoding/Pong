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

    void initMAINMENU();
    void initPAUSED();
    void initPLAYING();

    void updateMAINMENU(float dt);
    void updatePAUSED(float dt);
    void updatePLAYING(float dt);

    void renderMAINMENU();
    void renderPAUSED();
    void renderPLAYING();

    bool mouseOver(const sf::RectangleShape& body);

private:
    sf::RenderWindow window;
    sf::Event event;

    Paddle paddle1, paddle2;
    Ball ball;

    sf::Font font;
    sf::Text s1, s2;
    unsigned int scoreP1, scoreP2;

    sf::RectangleShape VSP, VSC, QUIT;
    sf::Texture buttons;

    gameState state;

    bool paused;

};