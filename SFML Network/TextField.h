#pragma once
#include <string>
#include"Window.h"
#include<future>
#include<iostream>

class TextField
{
public:
	TextField(Window* window);

	void init_text();

	void setPosition(sf::Vector2f vec);

	void input(sf::Event &event, short& level, std::promise<std::string>& connect_ip_promise);

	void setFont(sf::Font& f);

	const sf::String& getText();

	void setPlaceholder(std::string str);

	void render(short& level);

	void setLength(int arg);

	int getTextLength();

	bool isActive();

	void open();
	sf::Text *get_txt();
	sf::RectangleShape* get_box();
private:
	bool is_contains(sf::RectangleShape& sprite, sf::Event& event);
	void print_position(sf::RectangleShape& sprite, sf::Event& event);

	const uint8  TEXT_MAX = 24;

	const uint8  TEXT_BACKSPACE = 8;
	const uint8  TEXT_ESCAPE = 27;
	const uint8  TEXT_ENTER = 13;

	const sf::Color TEXT_GRAY = sf::Color(105, 105, 105);

	sf::Text txt;
	sf::RectangleShape box;
	sf::Font font;
	uint8 size;

	Window *window;

	int length;
	bool renderPlaceholder;
	void setActiveText(bool arg);
	bool active;
	sf::Vector2f pos;
	std::string placeholder;
};
