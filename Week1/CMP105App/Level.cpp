#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("hello world");
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(24);	
	text.setPosition(window->getSize().x / 2, 50);

	rectBr.setSize(sf::Vector2f(50, 50));
	rectBr.setPosition(window->getSize().x-50, window->getSize().y-50);
	rectBr.setFillColor(sf::Color::Green);

	rectR.setSize(sf::Vector2f(50, 50));
	rectR.setPosition(100, 100);
	rectR.setFillColor(sf::Color::Red);

	rectG.setSize(sf::Vector2f(25, 25));
	rectG.setPosition(112.5, 112.5);
	rectG.setFillColor(sf::Color::Green);

	rectB.setSize(sf::Vector2f(12.5, 12.5));
	rectB.setPosition(112.5+12.5/2, 112.5 + 12.5 / 2);
	rectB.setFillColor(sf::Color::Blue);

	circle.setRadius(50);
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	rectBr.setPosition(pos.x - 50, pos.y - 50);
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(text);
	window->draw(rectR);
	window->draw(rectG);
	window->draw(rectB);
	window->draw(rectBr);
	window->draw(circle);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}