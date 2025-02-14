#pragma once

#include <SFML/Graphics.hpp>


enum ControlType
{
    COMPUTER,
    ARROWS,
    WASD,
    AI
};

class Paddle
{
public:
    Paddle(float x, float y, ControlType type);

    void update(float dt);
    void render(sf::RenderWindow& window);

    void reset();

    inline const sf::RectangleShape& getBody() const { return body; }

    inline void setControlType(ControlType type) { controlType = type; }

private:
    sf::RectangleShape body;

    float speed;

    const float initX, initY;
    ControlType controlType;
    
};