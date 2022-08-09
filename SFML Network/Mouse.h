#pragma once
#include"Window.h"

class Mouse :virtual Window
{
public:
    bool is_contains(sf::Sprite& sprite_button);
    void print_position(sf::Sprite& sprite_button);
private:

};