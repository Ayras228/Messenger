#include "TextField.h"
#include<iostream>
TextField::TextField() 
{
	
	active = false;
	box.setFillColor(sf::Color::White);
	box.setOutlineThickness(3);

	renderPlaceholder = false;
	placeholder = "";

	txt.setFillColor(sf::Color::Black);

	size = TEXT_MAX;

	length = 0;
	
}

void TextField::init_text()
{
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	setFont(font);
	setLength(24);
	setPlaceholder("Enter IP friend ");
	short width, height;
	short wbow, hbox;
	
	wbow = box.getSize().x;
	hbox = box.getSize().y;
	std::tie(width, height)=get_size_window();
	setPosition(sf::Vector2f((width- wbow)/2,
		(height-hbox)/2 + height / 4));
}

void TextField::setPosition(sf::Vector2f vec) {
	box.setPosition(vec);
	txt.setPosition(vec + sf::Vector2f(5, 5));
}

void TextField::click(sf::Event& event, short& level, std::promise<std::string>& connect_ip_promise)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (is_contains(box, event))
		{
			setActive(true);

		}
		else
		{
			setActive(false);
		}
	}

	if (event.type == sf::Event::TextEntered && active) {
		sf::String str = txt.getString();

		if (event.text.unicode == TEXT_BACKSPACE) {
			if (str.getSize() > 0) {
				length--;
				str = str.substring(0, str.getSize() - 1);
			}
		}
		else if (event.text.unicode == TEXT_ESCAPE) {
			setActive(false);
		}
		else if (event.text.unicode == TEXT_ENTER)
		{
			std::cout << "PRESS ENTER" << std::endl;
			if (txt.getString().getSize()>8)
			{
				//set IPfriend;
				std::string connect_ip = txt.getString().toAnsiString();
				connect_ip_promise.set_value(connect_ip);
				level++;
			}
			else
			{
				std::cout << "incorrect IP" << std::endl;
			}
			
		}
		else {
			sf::String sfstr = "";
			sfstr += event.text.unicode;
			str += sfstr.toAnsiString();
		}

		if (str.getSize() == size) return;

		txt.setString(str);
		length++;
		//IPfriend
		//std::cout << txt.getString().toAnsiString() << std::endl;

	}
}

void TextField::setFont(sf::Font& f) {
	txt.setFont(f);
	txt.setCharacterSize(24);

	box.setSize(sf::Vector2f((txt.getCharacterSize()* 
		(size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
}

const sf::String& TextField::getText() {
	return txt.getString();
}

void TextField::render(short &level)
{
	if (level == 3)
	{
		get_window()->draw(box);
		get_window()->draw(txt);
	}
}

void TextField::setActive(bool arg) {
	active = arg;
	if (active) {
		box.setOutlineColor(sf::Color::Red);
	}
	else {
		box.setOutlineColor(sf::Color::White);
	}

	if (renderPlaceholder && arg) {
		renderPlaceholder = false;
		txt.setString("");
		txt.setFillColor(sf::Color::Black);
	}
}

void TextField::setPlaceholder(std::string str) {
	placeholder = str;
	renderPlaceholder = true;
	txt.setFillColor(TEXT_GRAY);
	txt.setString(placeholder);
	setActive(false);
}

void TextField::setLength(int arg) {
	size = arg;

	box.setSize(sf::Vector2f((txt.getCharacterSize() *
		(size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
}

int TextField::getTextLength() {
	return length;
}

bool TextField::isActive() {
	return active;
}

void TextField::open() {
	setActive(true);
}

sf::Text* TextField::get_txt()
{
	
	return &txt;
}

sf::RectangleShape* TextField::get_box()
{
	return &box;
}
bool TextField::is_contains(sf::RectangleShape& sprite, sf::Event& event)
{
	if (sprite.getGlobalBounds().contains
	(event.mouseButton.x, event.mouseButton.y))
	{
		return true;
	}
	return false;

}

void TextField::print_position(sf::RectangleShape& sprite, sf::Event& event)
{
	std::cout << "the left button was pressed" << std::endl;
	std::cout << "x: " << event.mouseButton.x << std::endl;
	std::cout << "y: " << event.mouseButton.y << std::endl;
	std::cout << "sprite x: " << sprite.getPosition().x << std::endl;
	std::cout << "sprite y: " << sprite.getPosition().y << std::endl;
}