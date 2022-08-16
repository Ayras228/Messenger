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
    
    if (level == 1)
    {
        SpriteHandler::click(event,level);
    }
    else if (level == 2)
    {
        TextField::click(event, level);
    }
    
}


void Graphics::render()
{
    
    if (level==1)
    {
        SpriteHandler::render();
    }
    else if (level == 2)
    {
        TextField::render();
    }
    
}


sf::RenderWindow* Graphics::get_window()
{
    return Window::get_window();
}
