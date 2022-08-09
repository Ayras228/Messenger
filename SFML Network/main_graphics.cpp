#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>
#include"Graphics.h"
#include"Window.h"

int main()
{
    Graphics graph;
    //Window window1;
    sf::RenderWindow *window = graph.get_window();
    window->clear(sf::Color::Black);
    graph.init();
    // 
    //sf::String playerInput;
    //sf::Font m_font;
    //m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    //sf::Text playerText(playerInput, m_font, 25);


    while (window->isOpen())
    {
       
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window->close();


            graph.mouse_click(event);


            /*if (event.type == sf::Event::TextEntered)
            {
                playerInput += event.text.unicode;
                playerText.setString(playerInput);
                window->draw(playerText);
            }*/
        }

        graph.draw();
        // 
        // 
        //window->draw(playerText);
        window->display();
    }

    return 0;
}