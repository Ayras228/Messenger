#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<iterator>
struct Position
{

    /*
    x0_y0    x1_y0

    x0_y1    x1_y1
    */
    std::pair<short, short> x0_y0;
    std::pair<short, short> x1_y1;

};


struct People
{
    int age;
    std::string name;
};


struct Spritepos
{
    sf::Sprite *sprite;
    std::pair<short,short> size;//<width,height>
    Position position;

};

class Graphics
{
public:
	Graphics();
    Graphics(unsigned int WIDTH, unsigned int HEIGHT);
    Graphics(unsigned int WIDTH, unsigned int HEIGHT, std::string name);
	~Graphics();
    void init_element();
    void init_sprites();
    void load_textures();
    void rect_textures(Spritepos &sprite_botton1_size);
    void set_positions(Spritepos &sprite_botton1_size);
    void click(sf::Event event);
    void draw();
    sf::RenderWindow *get_window();
private:
    unsigned int HEIGHT;
    unsigned int WIDTH;
    sf::RenderWindow window;
    sf::Texture texture_botton1, texture_botton2, texture_botton3,
        texture_background, texture_frame;
    



    sf::Sprite sprite_botton1, sprite_botton2,sprite_botton3,
        sprite_background, sprite_frame;
    //std::map<sf::Sprite*,std::pair<short, short>> sprite_size;
    std::vector<Spritepos> spritespos;

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
    sprite_botton1.setTexture(texture_botton1);
    sprite_botton2.setTexture(texture_botton2);
    sprite_botton3.setTexture(texture_botton3);
    sprite_background.setTexture(texture_background);
    sprite_frame.setTexture(texture_frame);   
}
void Graphics::load_textures()
{
    texture_botton1.loadFromFile("D:\\universe\\C++\\Study_network\\SFML Network\\image\\start.png");
    
}
void Graphics::rect_textures(Spritepos &sprite_botton1_size)
{
    short  rectLeft = 250, rectTop = 165, rectWidth = 350,   rectHeight = 185;
    
    sprite_botton1_size.size = std::pair<short, short>(rectWidth, rectHeight);
    sprite_botton1_size.sprite = &sprite_botton1;

    sprite_botton1.setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
    
}
void Graphics::set_positions(Spritepos &sprite_botton1_size)
{
    sprite_botton1_size.position.x0_y0 = std::make_pair<short, short>(WIDTH / 2, HEIGHT / 2);
    short size_w = sprite_botton1_size.size.first;
    short size_h = sprite_botton1_size.size.second;
    sprite_botton1_size.position.x1_y1 = std::make_pair<short, short>(WIDTH / 2 + size_w, HEIGHT / 2 + size_h);
    sprite_botton1.setPosition(WIDTH / 2, HEIGHT / 2);

    
}
void Graphics::init_element()
{
    Spritepos sprite_botton1_size;
    init_sprites();
    load_textures();
    rect_textures(sprite_botton1_size);
    set_positions(sprite_botton1_size);
    spritespos.push_back(sprite_botton1_size);
}
void Graphics::click(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for(Spritepos pos:spritespos)
            {

                if (pos.position.x0_y0.first<event.mouseButton.x && event.mouseButton.x < pos.position.x1_y1.first
                    && pos.position.x0_y0.second < event.mouseButton.y && event.mouseButton.y < pos.position.x1_y1.second)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "x0_y0.first: " << pos.position.x0_y0.first << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "x1_y1.first: " << pos.position.x1_y1.first << std::endl;
                    std::cout << "##################################"<< std::endl;
                    std::cout << "x0_y0.second: " << pos.position.x0_y0.second << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    std::cout << "x1_y1.second: " << pos.position.x1_y1.second << std::endl;
                    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
                }
            }
            
            
        }
    }
}
void Graphics::draw()
{
    window.draw(sprite_botton1);
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
    graph.init_element();

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