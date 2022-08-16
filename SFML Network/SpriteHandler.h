#pragma once

#include"Window.h"
#include<iostream>
class SpriteHandler:public virtual Window
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
    void render();
    void click(sf::Event &event,short &level);
private:
    bool is_contains(sf::Sprite& sprite, sf::Event& event);
    void print_position(sf::Sprite& sprite, sf::Event& event);
    static uint8 const count_sprites = 4;
    //static short const count_buttons = 3;
    static uint8 const count_buttons = 1;
    static uint8 const rect_count_param = 4;
    static uint8 const position_count_param = 2;

    sf::Texture texture_button1, texture_button2, texture_button3,
        texture_background;
    sf::Texture* textures[count_sprites] = 
    { &texture_button1, &texture_button2, &texture_button3,
        &texture_background};

    sf::Sprite background, button1, button2, button3;
    sf::Sprite* sprites[count_sprites] = 
{ &background ,&button1, &button2, &button3};
    //sf::Sprite* buttons[count_buttons] = { &button1, &button2, &button3 };
    sf::Sprite* buttons[count_buttons] = { &button1 };

    short width = get_WIDTH();
    short height = get_HEIGHT();

    short TALKlenwidth = 350;
    short TALKlenheight = 185;
    short rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, width,height},
        {0,0, TALKlenwidth, TALKlenheight},
        //{250,165, 350, 185},
        //{250,165, 350, 185}//,
        //{250,165, 350, 185}
    };
    short posTALKwidth = (width - TALKlenwidth) / 2;
    short posTALKheight = (height - TALKlenheight) / 2;
    short position_sprite[count_sprites][position_count_param] =
    {
        {0,0},
        {posTALKwidth,posTALKheight},
        
        //{300,150},
        //{690,360}//,
        //{1280,720}
    };
};

