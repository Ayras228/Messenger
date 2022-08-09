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
    texture_background.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\Background.png");
    texture_button1.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\Talk.png");
    //texture_button2.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\Talk.png");
    //texture_button3.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\Talk.png");

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
        sprite->setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
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
