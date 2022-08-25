#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <future>

#include "TextField.h"
#include "SpriteHandler.h"


class Graphics
{
public:
    Graphics();
    void init();
    
    void mouse_click(sf::Event &event);
    std::thread thread_click(sf::Event& event);

    void render();
    sf::RenderWindow* get_renderwindow();
    
    std::future<char> *get_type();
    std::future<std::string>* get_connect_ip();
private:
    std::promise<char> type_promise; 
    std::future<char> type;
    
    Window* window;
    SpriteHandler* spritehandler;
    TextField* textfield;
    

    //std::string connect_ip;
    std::promise<std::string> connect_ip_promise;
    std::future<std::string> connect_ip;
    //std::mutex read_data;
    short level;
};