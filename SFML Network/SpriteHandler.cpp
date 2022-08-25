#include "SpriteHandler.h"

SpriteHandler::SpriteHandler(Window* window)
{
    this->window=window;
    init_button();
}

void SpriteHandler::set_sprites()
{
    Background.setTexture(texture_Background);
    Talk.setTexture(texture_Talk);
    Server.setTexture(texture_Server);
    Client.setTexture(texture_Client);
    Enter_name.setTexture(texture_Enter_name);


}
void SpriteHandler::load_textures()
{
    texture_Background.loadFromFile("image\\Background.png");
    texture_Talk.loadFromFile("image\\Talk.png");
    texture_Server.loadFromFile("image\\Server.png");
    texture_Client.loadFromFile("image\\Client.png");
    texture_Enter_name.loadFromFile("image\\EnterName.png");
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
void SpriteHandler::renderBackground()
{
    sf::RenderWindow* renderwindow = window->get_renderwindow();
    renderwindow->draw(Background);
}

void SpriteHandler::render(short& level)
{
    sf::RenderWindow* renderwindow = window->get_renderwindow();
    renderwindow->draw(*sprites[0]);
    if (level == 1|| level == 3)
    {
        renderwindow->draw(*sprites[1]);
    }
    if (level == 2)
    {
        renderwindow->draw(*sprites[2]);
        renderwindow->draw(*sprites[3]);
    }
    if (level==4)
    {
        renderwindow->draw(*sprites[4]);
    }
}

void SpriteHandler::click(sf::Event &event, short &level, std::promise<char>& type_promise)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (short i = 0; i < count_buttons; i++)
        {
            if (is_contains(*buttons[i], event))
            {
                check_level(event, i, level, type_promise);
            }
        }
    }
}
void SpriteHandler::check_level(sf::Event& event,short index ,short& level,  std::promise<char>& type_promise)
{
    switch (index)
    {
    case 0:
        //Talk
        if (level == 1)
        {
            print_position(*buttons[index], event);
            level++;
        }
        break;
    case 1:
        //Server
        if (level == 2)
        {
            
            print_position(*buttons[index], event);
            //type_user = 's';
            type_promise.set_value('s');
            level += 2;
        }
        break;
    case 2:
        //Client
        if (level == 2)
        {
            print_position(*buttons[index], event);
            //type_user = 'c';
            type_promise.set_value('c');
            level++;
        }
        break;
    }
}
bool SpriteHandler::is_contains(sf::Sprite& sprite, sf::Event& event)
{
    if (sprite.getGlobalBounds().contains
    (static_cast<int>(event.mouseButton.x), static_cast<int>(event.mouseButton.y)))
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

void SpriteHandler::init_button()
{

    width = window->get_WIDTH();
    height = window->get_HEIGHT();

    TalkLenWidth = 329;
    TalkLenHeight = 111;

    ServerLenWidth = 417;
    ServerLenHeight = 111;

    ClientLenWidth = 435;
    ClientLenHeight = 111;

    EnterNameLenWidth = 650;
    EnterNameLenHeight = 104;
    
    
    PosBackgroundWidth = 0;
    PosBackgroundheight = 0;

    PosTalkWidth = (width - TalkLenWidth) / 2;
    PosTalkHeight = (height - TalkLenHeight) / 2 - height / 5;

    PosServerWidth = (width - ServerLenWidth) / 2 + width / 4;
    PosServerHeight = (height - ServerLenHeight) / 2 + height / 5;

    PosClientWidth = (width - ClientLenWidth) / 2 - width / 4;
    PosClientHeight = (height - ClientLenHeight) / 2 + height / 5;

    PosEnterNameWidth = (width - EnterNameLenWidth) / 2;
    PosEnterNameHeight = (height - EnterNameLenHeight) / 2 - height / 5;
    short _rect_len_sprite[count_sprites][rect_count_param] =
    {
        {0,0, width,height},
        {0,0, TalkLenWidth, TalkLenHeight},
        {0,0, ServerLenWidth, ServerLenHeight},
        {0,0, ClientLenWidth, ClientLenHeight},
        {0,0, EnterNameLenWidth, EnterNameLenHeight},
    };
    for (int i = 0; i < count_sprites; i++)
    {
        for (int j = 0; j < rect_count_param; j++)
        {
            rect_len_sprite[i][j] = _rect_len_sprite[i][j];
        }
    }
    short _position_sprite[count_sprites][position_count_param] =
    {
        {PosBackgroundWidth,PosBackgroundheight},
        {PosTalkWidth,PosTalkHeight},
        {PosServerWidth,PosServerHeight},
        {PosClientWidth,PosClientHeight},
        {PosEnterNameWidth,PosEnterNameHeight}
    };
    for (int q = 0; q < count_sprites; q++)
    {
        for (int k = 0; k < position_count_param; k++)
        {
            position_sprite[q][k] = _position_sprite[q][k];
        }
    }
    
}
