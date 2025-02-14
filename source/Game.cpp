#include "Game.hpp"

#define WIDTH 800
#define HEIGHT 600

Game::Game()
    : window(sf::VideoMode(WIDTH, HEIGHT), "Ping Pong"), paddle1(WIDTH/2, HEIGHT*0.9, ARROWS), paddle2(WIDTH/2, HEIGHT*0.1, WASD), ball(WIDTH, HEIGHT, paddle1, paddle2, paused)
{
    state = PLAYING;
}

void Game::update(float dt)
{
    switch(state)
    {
        case MAINMENU:
            updateMAINMENU(dt);
            break;
        case PAUSED:
            updatePAUSED(dt);
            break;
        case PLAYING:
            updatePLAYING(dt);
            break;

        default:
            break;

    }
}

void Game::render()
{
    switch(state)
    {
        case MAINMENU:
            renderMAINMENU();
            break;
        case PAUSED:
            renderPAUSED();
            break;
        case PLAYING:
            renderPLAYING();
            break;

        default:
            break;

    }
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////STATES////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::updateMAINMENU(float dt)
{

}

void Game::renderMAINMENU()
{

}

void Game::updatePAUSED(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
    {
        state = PLAYING;
        paused = false;
    }
}

void Game::renderPAUSED()
{
    window.clear();

    paddle1.render(window);
    paddle2.render(window);

    ball.render(window);

    window.display();
}


void Game::updatePLAYING(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || paused) state = PAUSED;
    paddle1.update(dt);
    paddle2.update(dt);
    ball.update(dt);

}

void Game::renderPLAYING()
{
    window.clear();

    paddle1.render(window);
    paddle2.render(window);

    ball.render(window);

    window.display();
}