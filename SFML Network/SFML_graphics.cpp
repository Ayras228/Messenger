#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>




class Graphics
{
public:
	Graphics();
    Graphics(unsigned int WIDTH, unsigned int HEIGHT);
    Graphics(unsigned int WIDTH, unsigned int HEIGHT, std::string name);
	~Graphics();


    void init();
    void _init_button();


    void init_sprites();
    void load_textures();
    void rect_button1(sf::Sprite& sprite_button);
    void rect_textures(sf::Sprite& sprite_button, short rectLeft, short rectTop,
        short rectWidth, short rectHeight);
    void set_button1_positions(sf::Sprite&sprite_button);
    void set_positions(sf::Sprite& sprite_button, short x0, short y0);
    void click(sf::Event event);


    void draw();
    sf::RenderWindow *get_window();
private:
    unsigned int HEIGHT;
    unsigned int WIDTH;
    sf::RenderWindow window;

    sf::Texture texture_button1, texture_button2, texture_button3,
        texture_background, texture_frame;
    sf::Texture *textures[5] = { &texture_button1, &texture_button2, &texture_button3,
        &texture_background, &texture_frame };



    sf::Sprite button1, button2, button3, background, frame;
    sf::Sprite* sprites[5] = { &button1, &button2, &button3, &background, &frame };


};  

Graphics::Graphics()
{
    HEIGHT = 720;
    WIDTH = 1280;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");

}
Graphics::Graphics(unsigned int WIDTH, unsigned int HEIGHT)
{

    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");

}
Graphics::Graphics(unsigned int WIDTH, unsigned int HEIGHT,std::string name)
{
    
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    window.create(sf::VideoMode(WIDTH, HEIGHT), name);

}

Graphics::~Graphics()
{
}

void Graphics::init_sprites()
{

    button1.setTexture(texture_button1);
    button2.setTexture(texture_button2);
    button3.setTexture(texture_button3);
    background.setTexture(texture_background);
    frame.setTexture(texture_frame);


}
void Graphics::load_textures()
{
    texture_button1.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\start.png");
    
}
void Graphics::rect_button1(sf::Sprite&sprite_button)
{
    short  rectLeft = 250, rectTop = 165, rectWidth = 350,   rectHeight = 185;

    sprite_button.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
}
void Graphics::rect_textures(sf::Sprite& sprite_button, short rectLeft,
    short rectTop, short rectWidth, short rectHeight)
{

    sprite_button.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));

}
void Graphics::set_button1_positions(sf::Sprite&sprite_button)
{

    sprite_button.setPosition(WIDTH / 2, HEIGHT / 2);
  
}
void Graphics::set_positions(sf::Sprite& sprite_button, short x0, short y0)
{

    sprite_button.setPosition(x0, y0);

}

void Graphics::_init_button()
{
    
    for (sf::Sprite *sprite_button:sprites)
    {
        rect_button1(*sprite_button);
        set_button1_positions(*sprite_button);
        break;//for 1 button
    }
   
}

void Graphics::init()
{
    init_sprites();
    load_textures();
    _init_button();
}

void Graphics::click(sf::Event event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (sf::Sprite *sprite_button : sprites)
        {

            if (sprite_button->getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            {
                std::cout << "the left button was pressed" << std::endl;
                std::cout << "x0_y0.first: " << sf::Mouse::getPosition(window).x << std::endl;
                std::cout << "x0_y0.first: " << sf::Mouse::getPosition(window).y << std::endl;
                std::cout << "sprite x: " << sprite_button->getPosition().x << std::endl;
                std::cout << "sprite y: " << sprite_button->getPosition().y << std::endl;
            }
        }

    }
}

void Graphics::draw()
{
    window.draw(button1);
}
sf::RenderWindow *Graphics::get_window()
{
    return &window;
}

    
int main()
{
    Graphics graph;
    sf::RenderWindow *window = graph.get_window();
    window->clear(sf::Color::Black);
    graph.init();
   

    while (window->isOpen())
    {
       
        sf::Event event;
        while (window->pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window->close();
        }
        graph.click(event);
        
        graph.draw();

        window->display();
    }

    return 0;
}