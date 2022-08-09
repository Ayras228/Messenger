#include"Graphics.h"

void Graphics::init()
{
    set_sprites();
    load_textures();
    rect_textures();
    set_positions();
}


void Graphics::mouse_click(sf::Event event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (short i = 0; i < get_count_buttons(); i++)
        {
            sf::Sprite *sprite_button=get_buttons();
            if (is_contains(sprite_button[i]))
            {
                print_position(sprite_button[i]);
            }
        }
    }
}


void Graphics::draw()
{
    for (size_t i = 0; i < get_count_sprites(); i++)
    {
        sf::Sprite sprite = get_sprites()[i];
        get_window()->draw(sprite);
    }
}


sf::RenderWindow* Graphics::get_window()
{
    return Window::get_window();
}
