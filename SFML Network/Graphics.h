#include<iostream>
#include<vector>
#include"TextField.h"
#include"SpriteHandler.h"

class Graphics :  public virtual Window,
    public virtual SpriteHandler, public virtual TextField
{
public:
    Graphics();

    void init();
    void mouse_click(sf::Event event);
    void render();
    sf::RenderWindow* get_window();

private:
    short level;
};