#include "HighScore.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <stack>


HighScore::HighScore()
{
	font.loadFromFile("Lobster_1.3.otf");
	int i = 0;

	ifstream myfile("example.txt");


	name.loadFromFile("name.otf");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			text[i].setString(line);
			arr = line;
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

HighScore::~HighScore()
{
}

void HighScore::draw(sf::RenderWindow &window)
{
	sf::Texture h_score;
	h_score.loadFromFile("HighScore.jpg");
	sf::Sprite high_score;
	high_score.setTexture(h_score);
	high_score.setPosition(0, 0);

	sf::Font score;
	score.loadFromFile("high.ttf");
	sf::Text high;
	high.setFont(score);
	high.setString("HIGH SCORE");
	high.setColor(sf::Color::Black);
	high.setCharacterSize(110);
	high.setStyle(sf::Text::Bold);
	high.setPosition(900 / 2 - high.getGlobalBounds().width / 2, 120);

	sf::Font fnt;
	fnt.loadFromFile("high.ttf");
	sf::Text txt;
	txt.setFont(fnt);
	txt.setString("Press ESCAPE key for the Main Menu");
	txt.setColor(sf::Color::Black);
	txt.setStyle(sf::Text::Bold);
	txt.setCharacterSize(53);
	txt.setPosition(900 / 2 - txt.getGlobalBounds().width / 2, 650);



	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		if (sf::Keyboard::isKeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				break;
		}
		window.clear();
		window.draw(high_score);
		window.draw(txt);
		window.draw(high);
		for (int i = 0; i < 2; i++)
		{
			text[i].setColor(sf::Color::Black);
			text[i].setFont(name);
			text[i].setPosition(900 / 2 - text[i].getGlobalBounds().width / 2, 380 + (i * 70));
			text[i].setStyle(sf::Text::Regular);
			text[i].setCharacterSize(60);
			window.draw(text[i]);
		}
		window.display();
	}
}

int HighScore::score()
{
	int x;
	x = stoi(arr);
	return x;
}