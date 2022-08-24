#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"Graphics.h"
#include"Window.h"
#include"TextField.h"

//#include "User.h"
//#include"Server.h"
//#include"Client.h"
#include"console_messenger.cpp"

#include<chrono>
#include <thread>
#include <future>

//DELTA_TIME = 1.0f / 60.0f

void renderThread(Graphics *graph)
{    
	sf::RenderWindow* window=graph->get_window();

	while (window->isOpen())
	{
		window->clear();
		graph->render();
		window->display();
	}
}
int main()
{
    Graphics graph;

    sf::RenderWindow *window = graph.get_window();

	//FPS
	float  const DELTA_TIME = 1.0f / 15.0f;
	window->setFramerateLimit(1.0f / DELTA_TIME);

    graph.init();


	// deactivate its OpenGL context
	window->setActive(false);

	// launch the rendering thread
	sf::Thread thread(&renderThread, &graph);
	thread.launch();

	std::thread connect([&]()
	{	std::future<char> *type_user = graph.get_type();
		char type= type_user->get();
		connecting(type, graph.get_connect_ip());

	});
   
	
	
	
	//Event
	while (window->isOpen())
    {
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();

			std::thread threadClick = graph.thread_click(event);
			threadClick.join();
		}

    }
	connect.join();
    return 0;
}


