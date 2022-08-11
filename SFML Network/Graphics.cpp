#include"Graphics.h"

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
    TextField::input(event);
}


void Graphics::render()
{
    //change render buttons
    short count_sprites = get_count_sprites();
    sf::RenderWindow *window = get_window().get();
    for (size_t i = 0; i < count_sprites; i++)
    {
        sf::Sprite sprite = get_sprites()[i];
        window->draw(sprite);
    }
    //
    window->draw(*get_box());
    window->draw(*get_txt());

}


std::shared_ptr<sf::RenderWindow> Graphics::get_window()
{
    return Window::get_ptr_window();
}
