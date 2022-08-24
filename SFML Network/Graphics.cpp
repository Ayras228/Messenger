#include"Graphics.h"

Graphics::Graphics()
{
    level = 1;
    //type_user = ' ';
    type = type_promise.get_future();
    connect_ip = connect_ip_promise.get_future();
}

void Graphics::init()
{
    init_text();
    set_sprites();
    load_textures();
    rect_textures();
    set_positions(); 
}



void Graphics::mouse_click(sf::Event& event)
{
    if (level<=4)
    {
        SpriteHandler::click(event, level, type_promise);
    }

    if (level == 3)
    {
        TextField::click(event, level, connect_ip_promise);
    }
}


void Graphics::render()
{
    SpriteHandler::render(level);
    TextField::render(level);
}


sf::RenderWindow* Graphics::get_window()
{
    return Window::get_window();
}


std::thread Graphics::thread_click(sf::Event &event)
{
    return std::thread(&Graphics::mouse_click, this, std::ref(event));
}

std::future<char> *Graphics::get_type()
{
    return &type;
}

std::future<std::string>* Graphics::get_connect_ip()
{
    return &connect_ip;
}
