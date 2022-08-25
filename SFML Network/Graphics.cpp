#include"Graphics.h"

Graphics::Graphics()
{
    window = new Window;
    textfield = new TextField(window);
    spritehandler = new SpriteHandler(window);
    level = 1;
    type = type_promise.get_future();
    connect_ip = connect_ip_promise.get_future();

    
}

void Graphics::init()
{
    textfield->init_text();
    spritehandler->set_sprites();
    spritehandler->load_textures();
    spritehandler->rect_textures();
    spritehandler->set_positions();
}



void Graphics::mouse_click(sf::Event& event)
{
    if (level<=4)
    {
        spritehandler->click(event, level, type_promise);
    }

    if (level == 3)
    {
        textfield->input(event, level, connect_ip_promise);
    }
}


void Graphics::render()
{
    spritehandler->render(level);
    textfield->render(level);
}


sf::RenderWindow* Graphics::get_renderwindow()
{
    return window->get_renderwindow();
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
