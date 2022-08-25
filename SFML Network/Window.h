#pragma once
#include<SFML/Graphics.hpp>
typedef unsigned __int16 uint16;
typedef unsigned __int8 uint8;

class Window
{
public:
    Window();
    Window(uint16 WIDTH, uint16 HEIGHT);
    Window(uint16 WIDTH, uint16 HEIGHT, std::string name);
    virtual ~Window();
    //std::shared_ptr<sf::RenderWindow> get_ptr_window();
    sf::RenderWindow* get_renderwindow();
    std::pair< uint16, uint16> get_size_window()const;
    uint16 get_HEIGHT()const;
    uint16 get_WIDTH()const;
private:
    uint16 HEIGHT;
    uint16 WIDTH;
    sf::RenderWindow window;
    //std::shared_ptr<sf::RenderWindow> ptr_window=std::make_shared<sf::RenderWindow>();
};
