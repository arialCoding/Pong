#include "Game.hpp"

#define WIDTH 800
#define HEIGHT 600

Game::Game()
    : window(sf::VideoMode(WIDTH, HEIGHT), "Ping Pong"),
      paddle1(WIDTH/2, HEIGHT*0.9, ARROWS), paddle2(WIDTH/2, HEIGHT*0.1, WASD),
      ball(WIDTH, HEIGHT, paddle1, paddle2, paused)
{
    state = MAINMENU;

    buttons.loadFromFile("resource/Buttons.png");

    VSP.setSize(sf::Vector2f(128, 64));
    VSP.setOrigin(VSP.getSize()*0.5f);
    VSP.setPosition(0.5*WIDTH, 0.35*HEIGHT);
    VSP.setTexture(&buttons);
    VSP.setTextureRect(sf::IntRect(0, 0, 128, 64));

    VSC.setSize(sf::Vector2f(128, 64));
    VSC.setOrigin(VSC.getSize()*0.5f);
    VSC.setPosition(0.5*WIDTH, 0.55*HEIGHT);
    VSC.setTexture(&buttons);
    VSC.setTextureRect(sf::IntRect(128, 0, 128, 64));

    QUIT.setSize(sf::Vector2f(128, 64));
    QUIT.setOrigin(QUIT.getSize()*0.5f);
    QUIT.setPosition(0.5*WIDTH, 0.75*HEIGHT);
    QUIT.setTexture(&buttons);
    QUIT.setTextureRect(sf::IntRect(256, 0, 128, 64));

    font.loadFromFile("resource/font.ttf");

    s1.setFont(font);
    s1.setCharacterSize(32);
    s1.setFillColor(sf::Color::White);
    s1.setPosition(10, HEIGHT/2 - 42);

    s2.setFont(font);
    s2.setCharacterSize(32);
    s2.setFillColor(sf::Color::White);
    s2.setPosition(10, HEIGHT/2 + 10);
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

bool Game::mouseOver(const sf::RectangleShape& body)
{
    float deltaX = abs(sf::Mouse::getPosition(window).x - body.getPosition().x);
    float deltaY = abs(sf::Mouse::getPosition(window).y - body.getPosition().y);

    return deltaX < body.getSize().x*0.5f && deltaY < body.getSize().y*0.5f;
}

///////////////////////////////////////////////////MAIN MENU//////////////////////////////////////////////////////

void Game::initMAINMENU()
{

}

void Game::updateMAINMENU(float dt)
{
    VSP.setTextureRect(sf::IntRect(0, 0, 128, 64));
    VSC.setTextureRect(sf::IntRect(128, 0, 128, 64));
    QUIT.setTextureRect(sf::IntRect(256, 0, 128, 64));

    if(mouseOver(VSP))
    {
        VSP.setTextureRect(sf::IntRect(0, 64, 128, 64));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            VSP.setTextureRect(sf::IntRect(0, 128, 128, 64));
            paddle2.setControlType(WASD);
            ball.reset(1);
            scoreP1 = scoreP2 = 0;
            state = PAUSED;
        }
    }
    else if(mouseOver(VSC))
    {
        VSC.setTextureRect(sf::IntRect(128, 64, 128, 64));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            VSC.setTextureRect(sf::IntRect(128, 128, 128, 64));
            paddle2.setControlType(COMPUTER);
            ball.reset(1);
            scoreP1 = scoreP2 = 0;
            state = PAUSED;
        }
    }
    else if(mouseOver(QUIT))
    {
        QUIT.setTextureRect(sf::IntRect(256, 64, 128, 64));
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            QUIT.setTextureRect(sf::IntRect(256, 128, 128, 64));
            window.close();
        }
    }
}

void Game::renderMAINMENU()
{
    window.clear(sf::Color(0x1d658a));

    window.draw(VSP);
    window.draw(VSC);
    window.draw(QUIT);
    
    window.display();
}



/////////////////////////////////////////////////////////PAUSED////////////////////////////////////////////////////////////

void Game::initPAUSED()
{

}

void Game::updatePAUSED(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
    {
        state = PLAYING;
        paused = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) 
    {
        state = MAINMENU;
        paused = false;
    }

    s1.setString(std::to_string(scoreP1));
    s2.setString(std::to_string(scoreP2));
}

void Game::renderPAUSED()
{
    window.clear(sf::Color(0x1d658a));

    paddle1.render(window);
    paddle2.render(window);

    ball.render(window);

    window.draw(s1);
    window.draw(s2);

    window.display();
}



/////////////////////////////////////////////////////////PLAYING////////////////////////////////////////////////////////////

void Game::initPLAYING()
{

}

void Game::updatePLAYING(float dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) || paused) state = PAUSED;

    paddle1.update(dt);
    paddle2.update(dt);
    
    ball.update(dt);

    if(ball.scoreFor1())
    {
        scoreP2++;
        ball.resetScored();
    } else if(ball.scoreFor2())
    {
        scoreP1++;
        ball.resetScored();
    }

    s1.setString(std::to_string(scoreP1));
    s2.setString(std::to_string(scoreP2));

}


void Game::renderPLAYING()
{
    window.clear(sf::Color(0x1d658a));

    paddle1.render(window);
    paddle2.render(window);

    ball.render(window);

    window.draw(s1);
    window.draw(s2);

    window.display();
}

