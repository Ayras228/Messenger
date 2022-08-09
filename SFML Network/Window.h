#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

class Window
{
public:
    Window();
    Window(unsigned int WIDTH, unsigned int HEIGHT);
    Window(unsigned int WIDTH, unsigned int HEIGHT, std::string name);
    virtual ~Window();
    sf::RenderWindow* get_window();
private:
    unsigned int HEIGHT;
    unsigned int WIDTH;
    sf::RenderWindow window;
    
};
