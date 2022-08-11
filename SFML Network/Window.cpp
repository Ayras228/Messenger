#include"Window.h"


Window::Window()
{
    HEIGHT = 720;
    WIDTH = 1280;
    //window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
    ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::Window(unsigned int WIDTH, unsigned int HEIGHT)
{

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    //window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
    ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::Window(unsigned int WIDTH, unsigned int HEIGHT, std::string name)
{

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    //window.create(sf::VideoMode(WIDTH, HEIGHT), name);
    ptr_window.get()->create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
}
Window::~Window()
{
}

std::shared_ptr<sf::RenderWindow> Window::get_ptr_window()
{
    return ptr_window;
}

//sf::RenderWindow* Window::get_window()
//{
//    return  &window;
//}
