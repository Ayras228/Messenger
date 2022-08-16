#include"Graphics.h"

Graphics::Graphics()
{
    level = 1;
}

void Graphics::init()
{
    init_text();
    set_sprites();
    load_textures();
    rect_textures();
    set_positions(); 
}


void Graphics::mouse_click(sf::Event event)
{
    SpriteHandler::click(event, level);
    if (level == 3)
    {
        TextField::click(event, level);
    }
}


void Graphics::render()
{
    SpriteHandler::render(level);
    if (level==3)
    {
        TextField::render();
    }
}


sf::RenderWindow* Graphics::get_window()
{
    return Window::get_window();
}
