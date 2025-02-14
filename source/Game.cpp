#include "Game.hpp"

#define WIDTH 800
#define HEIGHT 600

Game::Game()
    : window(sf::VideoMode(WIDTH, HEIGHT), "Ping Pong"), ball(WIDTH, HEIGHT, paddle1, paddle2), paddle1(WIDTH/2, HEIGHT*0.9, ARROWS), paddle2(WIDTH/2, HEIGHT*0.1, WASD)
{}

void Game::update(float dt)
{
    paddle1.update(dt);
    paddle2.update(dt);
    ball.update(dt);
}

void Game::render()
{
    window.clear();

    paddle1.render(window);
    paddle2.render(window);

    ball.render(window);

    window.display();
}

void Game::handleEvent()
{
    while(window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        
        default:
            break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////GAME LOOP///////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Game::Run()
{
    float dt = 0;
    sf::Clock clock;

    while(window.isOpen())
    {
        dt = clock.restart().asSeconds();

        handleEvent();
        update(dt);
        render();
    }
    return 0;
}
