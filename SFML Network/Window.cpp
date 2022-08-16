#include"Window.h"


Window::Window()
{
    HEIGHT = 720;
    WIDTH = 1280;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
    //ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::Window(uint16 WIDTH, uint16 HEIGHT)
{

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    //window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
    //ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::Window(uint16 WIDTH, uint16 HEIGHT, std::string name)
{

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    //window.create(sf::VideoMode(WIDTH, HEIGHT), name);
    //ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::~Window()
{
}

//std::shared_ptr<sf::RenderWindow> Window::get_ptr_window()
//{
//    return ptr_window;
//}

sf::RenderWindow* Window::get_window()
{
    return  &window;
}

std::pair<uint16, uint16> Window::get_size_window()const
{
    return std::make_pair(WIDTH,HEIGHT);
}

uint16 Window::get_HEIGHT()const
{
    return HEIGHT;
}

uint16 Window::get_WIDTH()const
{
    return WIDTH;
}
