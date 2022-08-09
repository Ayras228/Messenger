#pragma once
#include<SFML/Graphics.hpp>
class SpriteHandler
{
public:
    void set_sprites();
    void load_textures();
    void rect_textures();
    void set_positions();
    sf::Sprite* get_buttons();
    sf::Sprite* get_sprites();
    short get_count_buttons();
    short get_count_sprites();

private:
    static short const count_sprites = 4;
    //static short const count_buttons = 3;
    static short const count_buttons = 1;
    static short const rect_count_param = 4;
    static short const position_count_param = 2;

    sf::Texture texture_button1, texture_button2, texture_button3,
        texture_background;
    sf::Texture* textures[count_sprites] = { &texture_button1, &texture_button2, &texture_button3,
        &texture_background};

    sf::Sprite background, button1, button2, button3;
    sf::Sprite* sprites[count_sprites] = { &background ,&button1, &button2, &button3};
    //sf::Sprite* buttons[count_buttons] = { &button1, &button2, &button3 };
    sf::Sprite* buttons[count_buttons] = { &button1 };
    short rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, 1280,720},
        {0,0, 350, 185},
        {250,165, 350, 185},
        {250,165, 350, 185}//,
        //{250,165, 350, 185}
    };
    short position_sprite[count_sprites][position_count_param] =
    {
        {0,0},
        {0,0},
        {300,150},
        {690,360}//,
        //{1280,720}
    };
};

