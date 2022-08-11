#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>
#include"Graphics.h"
#include"Window.h"
#include"TextField.h"
int main()
{
    Graphics graph;

    sf::RenderWindow *window = graph.get_window().get();
    window->clear(sf::Color::Black);
    graph.init();

     
    
    
    while (window->isOpen())
    {
       
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window->close();
            
            graph.mouse_click(event);

        }

        graph.render();

        window->display();
    }

    return 0;
}