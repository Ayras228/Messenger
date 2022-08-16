#include "SpriteHandler.h"

void SpriteHandler::set_sprites()
{
    background.setTexture(texture_background);
    button1.setTexture(texture_button1);
    //button2.setTexture(texture_button2);
    //button3.setTexture(texture_button3);
    //frame.setTexture(texture_frame);


}
void SpriteHandler::load_textures()
{
    texture_background.loadFromFile("image\\Background.png");
    texture_button1.loadFromFile("image\\Talk.png");

}
void SpriteHandler::rect_textures()
{
    int index = 0;
    for (sf::Sprite* sprite : sprites)
    {

        short rectLeft = rect_len_sprite[index][0];
        short rectTop = rect_len_sprite[index][1];
        short rectWidth = rect_len_sprite[index][2];
        short rectHeight = rect_len_sprite[index][3];
        sprite->setTextureRect(sf::IntRect(rectLeft, 
            rectTop, rectWidth, rectHeight));
        index++;
    }
}
void SpriteHandler::set_positions()
{
    int index = 0;
    for (sf::Sprite* sprite : sprites)
    {
        short x0 = position_sprite[index][0];
        short y0 = position_sprite[index][1];

        sprite->setPosition(x0, y0);
        index++;
    }
}

sf::Sprite* SpriteHandler::get_buttons()
{
    return *buttons;
}

sf::Sprite* SpriteHandler::get_sprites()
{
    return *sprites;
}

short SpriteHandler::get_count_buttons()
{
    return count_buttons;
}

short SpriteHandler::get_count_sprites()
{
    return count_sprites;
}

void SpriteHandler::render()
{
    sf::RenderWindow* window = get_window();
    for (size_t i = 0; i < count_sprites; i++)
    {
        window->draw(*sprites[i]);
    }
}

void SpriteHandler::click(sf::Event &event, short &level)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (short i = 0; i < count_buttons; i++)
            if (is_contains(*buttons[i], event))
            {
                switch (i)
                {
                case 0:
                    print_position(*buttons[i], event);
                    level++;
                    break;
                    ///
                }

            }
    }
}

bool SpriteHandler::is_contains(sf::Sprite& sprite, sf::Event& event)
{
    if (sprite.getGlobalBounds().contains
    (event.mouseButton.x, event.mouseButton.y))
    {
        return true;
    }
    return false;

}

void SpriteHandler::print_position(sf::Sprite& sprite,
 sf::Event& event)
{
    std::cout << "the left button was pressed" << std::endl;
    std::cout << "x: " << event.mouseButton.x << std::endl;
    std::cout << "y: " << event.mouseButton.y << std::endl;
    std::cout << "sprite x0: " << sprite.getPosition().x  << std::endl;
    std::cout << "sprite y0: " << sprite.getPosition().y  << std::endl;
    
}