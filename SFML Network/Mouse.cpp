#include"Mouse.h"

bool Mouse::is_contains(sf::Sprite& sprite_button)
{
    if (sprite_button.getGlobalBounds().contains(sf::Mouse::getPosition(*get_ptr_window().get()).x, sf::Mouse::getPosition(*get_ptr_window().get()).y))
    {
        return true;
    }
    return false;
    
}

void Mouse::print_position(sf::Sprite& sprite_button)
{
    std::cout << "the left button was pressed" << std::endl;
    std::cout << "x0_y0.first: " << sf::Mouse::getPosition(*get_ptr_window().get()).x << std::endl;
    std::cout << "x0_y0.first: " << sf::Mouse::getPosition(*get_ptr_window().get()).y << std::endl;
    std::cout << "sprite x: " << sprite_button.getPosition().x << std::endl;
    std::cout << "sprite y: " << sprite_button.getPosition().y << std::endl;
}
