#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>
#include"Mouse.h"
#include"Keyboard.h"
#include"SpriteHandler.h"

class Graphics:public virtual Mouse, public virtual Keyboard, public virtual Window, public virtual SpriteHandler
{
public:


    void init();
    void mouse_click(sf::Event event);
    void draw();
    sf::RenderWindow* get_window();

private:

    
};