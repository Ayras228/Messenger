#pragma once
#include<SFML/Graphics.hpp>


class Window
{
public:
    Window();
    Window(unsigned int WIDTH, unsigned int HEIGHT);
    Window(unsigned int WIDTH, unsigned int HEIGHT, std::string name);
    virtual ~Window();
    std::shared_ptr<sf::RenderWindow> get_ptr_window();
    //sf::RenderWindow* get_window();
private:
    unsigned int HEIGHT;
    unsigned int WIDTH;
    //sf::RenderWindow window;
    std::shared_ptr<sf::RenderWindow> ptr_window=std::make_shared<sf::RenderWindow>();
};
