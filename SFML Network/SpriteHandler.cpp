#include "SpriteHandler.h"

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
    sf::RenderWindow* window = get_window();
    window->draw(Background);
}

void SpriteHandler::render(short& level)
{
    sf::RenderWindow* window = get_window();
    window->draw(*sprites[0]);
    if (level == 1|| level == 3)
    {
        window->draw(*sprites[1]);
    }
    if (level == 2)
    {
        window->draw(*sprites[2]);
        window->draw(*sprites[3]);
    }
    if (level==4)
    {
        window->draw(*sprites[4]);
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