#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>
#include"Mouse.h"
#include"TextField.h"
#include"SpriteHandler.h"

class Graphics : public virtual Mouse, public virtual Window, public virtual SpriteHandler, public virtual TextField
{
public:


    void init();
    void mouse_click(sf::Event event);
    //void mouse_click_text(sf::Event event);
    void render();
    std::shared_ptr<sf::RenderWindow> get_window();

private:

};