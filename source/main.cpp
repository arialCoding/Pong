#include <SFML/Graphics.hpp>

int main(int, char**){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

    sf::Event event;

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();


        window.display();

    }

}
