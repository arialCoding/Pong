#include "Paddle.hpp"


Paddle::Paddle(float x, float y, ControlType type) : initX(x), initY(y), controlType(type)
{
    reset();
}


void Paddle::update(float dt)
{
    sf::Vector2f velocity(0, 0);

    switch(controlType)
    {
        case ARROWS:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) velocity.x -= speed;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocity.x += speed;
            break;
        case WASD:
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity.x -= speed;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity.x += speed;
            break;
        case COMPUTER:
            break;
        case AI:
            break;
            
        default:
            break;
    }


    body.move(velocity*dt);
}

void Paddle::render(sf::RenderWindow& window)
{
    window.draw(body);
}

void Paddle::reset()
{
    body.setSize(sf::Vector2f(150, 10));
    body.setOrigin(body.getSize()*0.5f);
    body.setPosition(initX, initY);

    body.setFillColor(sf::Color::White);

    speed = 350;
}
