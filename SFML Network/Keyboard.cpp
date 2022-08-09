#include "Keyboard.h"


void Keyboard::keyboard(sf::Event event)
{
    sf::String playerInput;
    sf::Text playerText;
    if (event.type == sf::Event::TextEntered)
    {
        playerInput += event.text.unicode;
        playerText.setString(playerInput);

    }

    get_window()->draw(playerText);
}
