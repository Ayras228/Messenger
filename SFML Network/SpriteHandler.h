#pragma once
#include"Window.h"
#include<iostream>
#include<future>
class SpriteHandler
{
public:
    SpriteHandler(Window*window);
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
    void click(sf::Event &event,short &level, std::promise<char> &type_promise);
    
private:
    Window* window;
    
    void check_level(sf::Event& event, short index, short& level, std::promise<char>& type_promise);
    bool is_contains(sf::Sprite& sprite, sf::Event& event);
    void print_position(sf::Sprite& sprite, sf::Event& event);
    static uint8 const count_sprites = 5;
    static short const count_buttons = 4;
    //static uint8 const count_buttons = 1;
    static uint8 const rect_count_param = 5;
    static uint8 const position_count_param = 2;

    sf::Texture texture_Talk, texture_Server, texture_Client,
        texture_Background, texture_Enter_name;
    sf::Texture* textures[count_sprites] = 
    { &texture_Talk, &texture_Server, &texture_Client,
        &texture_Background,&texture_Enter_name };

    sf::Sprite Background, Talk, Server, Client, Enter_name;
    sf::Sprite* sprites[count_sprites] = 
{ &Background ,&Talk, &Server, &Client,&Enter_name };
    sf::Sprite* buttons[count_buttons] = { &Talk, &Server, &Client,&Enter_name };

    void init_button();

    short width; 
    short height;

    short TalkLenWidth;
    short TalkLenHeight;

    short ServerLenWidth;
    short ServerLenHeight;

    short ClientLenWidth ;
    short ClientLenHeight;

    short EnterNameLenWidth;
    short EnterNameLenHeight;

    short rect_len_sprite[count_sprites][rect_count_param];
    /*short rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, width,height},
        {0,0, TalkLenWidth, TalkLenHeight},
        {0,0, ServerLenWidth, ServerLenHeight},
        {0,0, ClientLenWidth, ClientLenHeight},
        {0,0, EnterNameLenWidth, EnterNameLenHeight},
    };*/


    short PosBackgroundWidth;
    short PosBackgroundheight;

    short PosTalkWidth ;
    short PosTalkHeight;

    short PosServerWidth;
    short PosServerHeight;

    short PosClientWidth;
    short PosClientHeight;

    short PosEnterNameWidth;
    short PosEnterNameHeight;

    short position_sprite[count_sprites][position_count_param];
    /*short position_sprite[count_sprites][position_count_param] =
    {
        {PosBackgroundWidth,PosBackgroundheight},
        {PosTalkWidth,PosTalkHeight},
        {PosServerWidth,PosServerHeight},
        {PosClientWidth,PosClientHeight},
        {PosEnterNameWidth,PosEnterNameHeight}
    };*/



    /*short width = window->get_WIDTH();
    short height = window->get_HEIGHT();

    short TalkLenWidth = 329;
    short TalkLenHeight = 111;

    short ServerLenWidth = 417;
    short ServerLenHeight = 111;

    short ClientLenWidth = 435;
    short ClientLenHeight = 111;

    short EnterNameLenWidth = 650;
    short EnterNameLenHeight = 104;

    short rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, width,height},
        {0,0, TalkLenWidth, TalkLenHeight},
        {0,0, ServerLenWidth, ServerLenHeight},
        {0,0, ClientLenWidth, ClientLenHeight},
        {0,0, EnterNameLenWidth, EnterNameLenHeight},
    };
    short PosBackgroundWidth = 0;
    short PosBackgroundheight = 0;

    short PosTalkWidth = (width - TalkLenWidth) / 2;
    short PosTalkHeight = (height - TalkLenHeight) / 2 - height/5;

    short PosServerWidth = (width - ServerLenWidth) / 2 + width / 4;
    short PosServerHeight = (height - ServerLenHeight) / 2 + height / 5;

    short PosClientWidth = (width - ClientLenWidth) / 2 - width / 4;
    short PosClientHeight = (height - ClientLenHeight) / 2 + height / 5;

    short PosEnterNameWidth = (width - EnterNameLenWidth) / 2 ;
    short PosEnterNameHeight = (height - EnterNameLenHeight) / 2 - height / 5;

    short position_sprite[count_sprites][position_count_param] =
    {
        {PosBackgroundWidth,PosBackgroundheight},
        {PosTalkWidth,PosTalkHeight},
        {PosServerWidth,PosServerHeight},
        {PosClientWidth,PosClientHeight},
        {PosEnterNameWidth,PosEnterNameHeight}
    };*/
};

