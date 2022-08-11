#include"TextFieldtest.h"

int main()
{
	sf::RenderWindow window;
	const int HEIGHT = 720;
	const int WIDTH = 1280;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Messenger");
	TextField textField;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	//Инициализация
	textField.setFont(font); //font- это ваш загруженный sf::Font 
	textField.setLength(64);
	textField.setPlaceholder("Enter your message");
	textField.setPosition(sf::Vector2f(100, 100)); //координаты для ввода

	//Рисование 


	//Обработка событий

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			textField.input(event);
		}
		textField.render(window);
		window.display();
	}
	 //ev == sf::Event / window.pollEvent()
}