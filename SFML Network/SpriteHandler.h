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
    void renderBackground();
    void render(short& level);
    void click(sf::Event &event,short &level);
private:
    bool is_contains(sf::Sprite& sprite, sf::Event& event);
    void print_position(sf::Sprite& sprite, sf::Event& event);
    static uint8 const count_sprites = 4;
    static short const count_buttons = 3;
    //static uint8 const count_buttons = 1;
    static uint8 const rect_count_param = 4;
    static uint8 const position_count_param = 2;

    sf::Texture texture_Talk, texture_Server, texture_Client,
        texture_Background;
    sf::Texture* textures[count_sprites] = 
    { &texture_Talk, &texture_Server, &texture_Client,
        &texture_Background};

    sf::Sprite Background, Talk, Server, Client;
    sf::Sprite* sprites[count_sprites] = 
{ &Background ,&Talk, &Server, &Client};
    sf::Sprite* buttons[count_buttons] = { &Talk, &Server, &Client };

    short width = get_WIDTH();
    short height = get_HEIGHT();

    short TALKlenwidth = 329;
    short TALKlenheight = 111;

    short Serverlenwidth = 417;
    short Serverlenheight = 111;

    short Clientlenwidth = 435;
    short Clientlenheight = 111;

    short rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, width,height},
        {0,0, TALKlenwidth, TALKlenheight},
        {0,0, Serverlenwidth, Serverlenheight},
        {0,0, Clientlenwidth, Clientlenheight}
    };
    short posBackgroundwidth = 0;
    short posBackgroundheight = 0;

    short posTALKwidth = (width - TALKlenwidth) / 2;
    short posTALKheight = (height - TALKlenheight) / 2 - height/5;

    short posServerwidth = (width - Serverlenwidth) / 2 + width / 4;
    short posServerheight = (height - Serverlenheight) / 2 + height / 5;

    short posClientwidth = (width - Clientlenwidth) / 2 - width / 4;
    short posClientheight = (height - Clientlenheight) / 2 + height / 5;

    short position_sprite[count_sprites][position_count_param] =
    {
        {posBackgroundwidth,posBackgroundheight},
        {posTALKwidth,posTALKheight},
        {posServerwidth,posServerheight},
        {posClientwidth,posClientheight},
    };
};

