#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>
#include <iostream>
#include <sstream>
#include <string.h>
#include <fstream>
#include "HighScore.h"

using namespace std;

bool release = true, rls = true;

float random_dist()
{
	float y;
	std::random_device rd;
	std::mt19937 mersenne(rd());
	y = 250 + mersenne() % 300;
	return y;
}

float random_width()
{
	float x;
	std::random_device rd;
	std::mt19937 mersenne(rd());
	x = 15 + mersenne() % 55;
	return x;
}

float perfect(float rect_x, float rect_wid)
{
	float midx;
	midx = rect_wid / 2.0;
	midx -= 2.5;
	midx += rect_x;
	return midx;
}




int ppp;

int main()
{

	sf::RenderWindow window(sf::VideoMode(900, 800), "STICK HERO", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(300);

	bool isFullscreen = true;

	int cnt = 0;

	int life = 2;
	int total_rect = 0;

	goto main_menu;




main_menu:
	{
		///////////main menu image//////////////////////
		sf::Texture main_menu;
		main_menu.loadFromFile("menuPage.jpg");
		sf::Sprite menu;
		menu.setTexture(main_menu);
		////////////////////////////////////////////////


		//////////////////////Main Menu Music////////////////////

		sf::Music music, music1;
		music.openFromFile("menupage.wav");
		music.setVolume(100);

		music1.openFromFile("highscoremusic.wav");
		music1.setVolume(100);

		////////////////////////////////////////////////////////////

		music.play();
		music.setLoop(true);

		//////////////////////main menu//////////////////////////////
		sf::Font title;
		title.loadFromFile("high.ttf");


		sf::Text ttl("Stick Hero", title, 170);
		ttl.setStyle(sf::Text::Bold);
		ttl.setColor(sf::Color::Black);

		ttl.setPosition(window.getSize().x / 2 - ttl.getGlobalBounds().width / 2, 150);
		sf::Mouse::setPosition(sf::Vector2i(10, 100), window);



		sf::Text menu_text[5];

		window.draw(menu);
		window.draw(ttl);

		string str[] = { "New Game", "High Score", "Credit", "Help", "Exit" };
		int k;
		for (k = 0; k < 5; k++)
		{
			menu_text[k].setFont(title);
			menu_text[k].setCharacterSize(45);
			menu_text[k].setString(str[k]);
			menu_text[k].setColor(sf::Color::Black);
			menu_text[k].setPosition(window.getSize().x - 450, 400 + k * 60);
			window.draw(menu_text[k]);
		}

		while (window.isOpen())
		{
			
			sf::Event event;
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();

					break;

				case sf::Event::MouseButtonPressed:

					if (release && (menu_text[0].getGlobalBounds().contains(mouse)))
						goto new_game;
					if (release && (menu_text[1].getGlobalBounds().contains(mouse)))
					{
						music.stop();
						music1.play();
						music1.setLoop(true);
						HighScore h;
						HighScore HighScore();
						h.draw(window);

						goto main_menu;
					}
					if (release && (menu_text[2].getGlobalBounds().contains(mouse)))
						goto credit_game;
					if (release && (menu_text[3].getGlobalBounds().contains(mouse)))
						goto help;
					if (release && (menu_text[4].getGlobalBounds().contains(mouse)))
						goto exit_game;

					release = false;
					break;

				case sf::Event::MouseButtonReleased:
					release = true;
					break;
				}

			}

			window.draw(menu);
			window.draw(ttl);




			if (menu_text[0].getGlobalBounds().contains(mouse))
			{
				menu_text[0].setColor(sf::Color::White);
				menu_text[0].setCharacterSize(65);
			}
			else
			{
				menu_text[0].setColor(sf::Color::Black);
				menu_text[0].setCharacterSize(55);
			}

			if (menu_text[1].getGlobalBounds().contains(mouse))
			{
				menu_text[1].setColor(sf::Color::White);
				menu_text[1].setCharacterSize(65);
			}
			else
			{
				menu_text[1].setColor(sf::Color::Black);
				menu_text[1].setCharacterSize(55);
			}

			if (menu_text[2].getGlobalBounds().contains(mouse))
			{
				menu_text[2].setColor(sf::Color::White);
				menu_text[2].setCharacterSize(65);
			}
			else
			{
				menu_text[2].setColor(sf::Color::Black);
				menu_text[2].setCharacterSize(55);
			}
			if (menu_text[3].getGlobalBounds().contains(mouse))
			{
				menu_text[3].setColor(sf::Color::White);
				menu_text[3].setCharacterSize(65);
			}
			else
			{
				menu_text[3].setColor(sf::Color::Black);
				menu_text[3].setCharacterSize(55);
			}
			if (menu_text[4].getGlobalBounds().contains(mouse))
			{
				menu_text[4].setColor(sf::Color::White);
				menu_text[4].setCharacterSize(65);
			}
			else
			{
				menu_text[4].setColor(sf::Color::Black);
				menu_text[4].setCharacterSize(55);
			}

			window.draw(menu_text[0]);
			window.draw(menu_text[1]);
			window.draw(menu_text[2]);
			window.draw(menu_text[3]);
			window.draw(menu_text[4]);
			window.display();
		}
	}


credit_game:
	{
		sf::Texture crdt;
		crdt.loadFromFile("credits.jpg");
		sf::Sprite credit;
		credit.setTexture(crdt);

		credit.setPosition(0, 0);

		sf::Music music;
		music.openFromFile("menupage.wav");
		music.setVolume(100);

		music.play();
		music.setLoop(true);

		while (1)
		{
			window.clear();
			window.draw(credit);
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				goto main_menu;
			}
		}
	}

help:
	{
		sf::Texture hlp;
		hlp.loadFromFile("help.png");
		sf::Sprite help;
		help.setTexture(hlp);

		help.setPosition(0, 0);

		sf::Music music;
		music.openFromFile("menupage.wav");
		music.setVolume(100);

		music.play();
		music.setLoop(true);

		while (1)
		{
			window.clear();
			window.draw(help);
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				goto main_menu;
			}
		}
	}

new_game :
{
	window.setFramerateLimit(300);

	float rand_dist, r1x, r2x, random_rectx, stick_height = 0, angle = 0, temporary, stick_width = 5, die_angle = 0.0;
	r1x = 150; r2x = random_dist(); random_rectx = window.getSize().x;

	float r1_width = random_width(), r2_width = random_width(), rand_width = random_width();
	float perfect_height = 4, perfect_width = 5;

	sf::RectangleShape r1(sf::Vector2f(r1_width, 300));
	sf::RectangleShape r2(sf::Vector2f(r2_width, 300));
	sf::RectangleShape random_rect(sf::Vector2f(rand_width, 300));
	sf::RectangleShape perfect_rect(sf::Vector2f(perfect_width, perfect_height));


	sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));

	sf::Texture tex;
	tex.loadFromFile("aa.png");
	sf::Sprite stickHero;
	stickHero.setTexture(tex);


	sf::Texture g_over;
	g_over.loadFromFile("GameOver.jpg");
	sf::Sprite game_over;
	game_over.setTexture(g_over);


	/////////////background/////////////////////////
	sf::Texture bk_ground;
	bk_ground.loadFromFile("bk_5.jpg");
	sf::Sprite back;
	back.setTexture(bk_ground);

	sf::Texture bk_ground2;
	bk_ground2.loadFromFile("bk_5.jpg");
	sf::Sprite back2;
	back2.setTexture(bk_ground2);
	//////////////background////////////////////////


	sf::Font font;
	font.loadFromFile("Pacifico.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Perfect!!   +1");
	text.setColor(sf::Color::Black);
	text.setCharacterSize(40);
	text.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, 200);

	//Scoring///////////////////////////////////////////


	sf::Font arial;
	arial.loadFromFile("Pacifico.ttf");

	std::stringstream ss;
	ss << "Score: " << cnt;

	sf::Text score;
	score.setCharacterSize(50);
	score.setPosition(window.getSize().x - 550, 10);
	score.setColor(sf::Color::Black);
	score.setFont(arial);
	score.setString(ss.str());
	/////////////////////////////////////////////////////

	///////////////////////////////////////Life////////////////////////////////////////

	sf::Font lf;
	lf.loadFromFile("high.ttf");

	std::stringstream s;
	s << "Life: " << life + 1;

	sf::Text lifee;
	lifee.setCharacterSize(40);
	lifee.setPosition(750, 80);
	lifee.setColor(sf::Color::Black);
	lifee.setStyle(sf::Text::Bold);
	lifee.setFont(lf);
	lifee.setString(s.str());





	//////////////////////////////////////////////////////////////////////////////////////

	r1.setFillColor(sf::Color::Black);
	r2.setFillColor(sf::Color::Black);
	random_rect.setFillColor(sf::Color::Black);
	perfect_rect.setFillColor(sf::Color::Red);

	float perfect_posx = perfect(r2x, r2_width);
	float perfect_point = perfect_posx;

	r1.setPosition(r1x, 500);
	r2.setPosition(r2x, 500);
	random_rect.setPosition(random_rectx, 500);
	perfect_rect.setPosition(perfect_posx, 500);

	float stickherox, stickheroy, diff;
	float back2_x = 3000, back_x = 0;


	stickherox = (r1_width / 2.0) + 135;
	stickheroy = 480;
	stickHero.setPosition(stickherox, stickheroy);
	back.setPosition(back_x, 0);
	back2.setPosition(back2_x, 0);
	game_over.setPosition(0, 0);

	bool flag = false, flag2 = false, prfct = false;
	bool gameOver = false;

	int i = 0;

	sf::Music musicc;
	musicc.openFromFile("gamesound.wav");
	musicc.setVolume(60);
	musicc.setLoop(true);
	musicc.play();


	sf::SoundBuffer buffer;
	buffer.loadFromFile("stick.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(100);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (i == 0)
		{
			flag2 = false;
			gameOver = false;

			sf::RectangleShape r1(sf::Vector2f(r1_width, 300));
			sf::RectangleShape r2(sf::Vector2f(r2_width, 300));
			sf::RectangleShape random_rect(sf::Vector2f(rand_width, 300));
			sf::RectangleShape perfect_rect(sf::Vector2f(perfect_width, perfect_height));

			r1.setFillColor(sf::Color::Black);
			r2.setFillColor(sf::Color::Black);
			random_rect.setFillColor(sf::Color::Black);
			perfect_rect.setFillColor(sf::Color::Red);

			r1.setPosition(r1x, 500);
			r2.setPosition(r2x, 500);
			random_rect.setPosition(random_rectx, 500);
			perfect_rect.setPosition(perfect_posx, 500);

			float stickx;
			stickx = 150 + r1_width - 5;

			stick.setPosition(stickx, 500);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				window.setFramerateLimit(300);
				
				stick_height--;
				
				sf::RectangleShape stick(sf::Vector2f(5, stick_height));
				stick.setFillColor(sf::Color::Black);
				stick.setPosition(stickx, 500);
				window.draw(stick);
				window.display();
				
				flag = true;
			}
			sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
			stick.setFillColor(sf::Color::Black);
			stick.setPosition(stickx, 498);
			while ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space) && flag && angle <= 90)
			{
				window.setFramerateLimit(300);
				sound.play();
			    stick.setRotation(angle);
				angle++;
				window.clear(sf::Color::White);
				window.draw(back);
				window.draw(back2);
				window.draw(score);
				window.draw(lifee);
				window.draw(r1);
				window.draw(r2);
				window.draw(random_rect);
				window.draw(stickHero);
				window.draw(perfect_rect);
				window.draw(stick);
				window.display();
				if (angle == 91)
				{
					temporary = stick_height;
					stick_height = stick_width;
					stick_width = temporary;
					stick_height *= (-1);
					stick_width *= (-1);
					diff = r2x - (r1x + r1_width - 5);



					float r2_mid;
					r2_mid = (r2_width / 2.0) + (r2x - 15);
					if ((stick_width >= diff) && (stick_width <= diff + r2_width))
					{

						while (stickherox <= r2_mid)
						{
							window.setFramerateLimit(200);
							stickherox++;
							back_x -= 0.3;
							back2_x -= 0.3;
							if (back_x == -3000)
								back_x = 3000;
							if (back2_x == -3000)
								back2_x = 3000;
							back.setPosition(back_x, 0);
							back2.setPosition(back2_x, 0);
							stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
							window.clear(sf::Color::White);
							window.draw(back);
							window.draw(back2);
							window.draw(score);
							window.draw(lifee);
							window.draw(r1);
							window.draw(r2);
							window.draw(random_rect);
							window.draw(stickHero);
							window.draw(perfect_rect);
							window.draw(stick);
							if ((stickx + stick_width >= perfect_posx) && (stickx + stick_width <= perfect_posx + 5))
							{
								window.draw(text);
								prfct = true;
							}
							window.display();
						}
						if (prfct)
							cnt++;
						cnt++;

						/////////////////////////////
						ss.str("");
						ss << "Score: " << cnt;
						score.setString(ss.str());
						////////////////////////////

						total_rect++;

						float rnd_rectX = random_dist();
						stick_height = 0;
						sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
						if (r1x > -100 || r2x > 150 || random_rectx > rnd_rectX)
						{
							while (r1x > -100 || r2x > 150 || random_rectx > rnd_rectX)
							{
								window.setFramerateLimit(300);
								if (r1x > -100)
									r1x--;
								if (r2x > 150)
								{
									r2x--;
									stickherox--;
								}
								if (random_rectx > rnd_rectX)
									random_rectx--;
								r1.setPosition(r1x, 500);
								r2.setPosition(r2x, 500);
								random_rect.setPosition(random_rectx, 500);
								stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
								window.clear(sf::Color::White);
								window.draw(back);
								window.draw(back2);
								window.draw(score);
								window.draw(lifee);
								window.draw(r1);
								window.draw(r2);
								window.draw(random_rect);
								window.draw(stickHero);
								window.draw(stick);
								window.display();
							}
							if (r1x == -100)
							{
								r1x = 900;
								r1_width = random_width();
								angle = 0;
								stick_width = 5;
								flag = false;
								prfct = false;
								perfect_posx = perfect(random_rectx, rand_width);
								i++;
							}
						}
					}
					else
					{
						while (!flag2)
						{
							if (stickherox > (r1x + r1_width + stick_width))
							{
								while (stickheroy < 800)
								{
									window.setFramerateLimit(300);
									stickheroy += 0.5;
									stickHero.setRotation(die_angle);
									die_angle++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
									flag2 = true;
									gameOver = true;
								}

							}
							else
							{
								while (stickherox <= (r1x + r1_width + stick_width))
								{
									window.setFramerateLimit(200);
									stickherox++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
								}
							}
						}
					}
					while (gameOver)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							life = 2;
							HighScore h;
							ppp = h.score();
							if (cnt > ppp)
							{
								goto scoring;
							}
							else
							{
								cnt = 0;
								goto main_menu;
							}
						}
						else
						{
							if (life > 0)
							{
								life--;
								s.str("");
								s << "Life: " << life + 1;
								lifee.setString(s.str());
								goto new_game;
							}
							else if (life == 0)
							{
								/////////////////////////////////////////////

								sf::Font scre;
								scre.loadFromFile("high.ttf");

								std::stringstream sss;
								sss << "Your Score: " << cnt;

								sf::Text pp;
								pp.setCharacterSize(90);
								pp.setColor(sf::Color::Black);
								pp.setFont(scre);
								pp.setString(sss.str());
								pp.setPosition(900 / 2 - pp.getGlobalBounds().width / 2, 350);

								/////////////////////////////////////////////

								window.clear();
								window.draw(game_over);
								window.draw(pp);
								window.display();
							}
						}
					}
				}
			}
			stick.setPosition(r1x + r1_width - 5, 498);
		}
		//i == 0 ends/////////////////////////////////////////////////////////////////////


		//i == 1 starts//////////////////////////////////////////////////////////////////

		if (i == 1)
		{
			flag2 = false;
			gameOver = false;
			

			sf::RectangleShape r1(sf::Vector2f(r1_width, 300));
			sf::RectangleShape r2(sf::Vector2f(r2_width, 300));
			sf::RectangleShape random_rect(sf::Vector2f(rand_width, 300));
			sf::RectangleShape perfect_rect(sf::Vector2f(perfect_width, perfect_height));

			r1.setFillColor(sf::Color::Black);
			r2.setFillColor(sf::Color::Black);
			random_rect.setFillColor(sf::Color::Black);
			perfect_rect.setFillColor(sf::Color::Red);

			r1.setPosition(r1x, 500);
			r2.setPosition(r2x, 500);
			random_rect.setPosition(random_rectx, 500);
			perfect_rect.setPosition(perfect_posx, 500);

			float stickx;
			stickx = 150 + r2_width - 5;

			stick.setPosition(stickx, 500);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				window.setFramerateLimit(300);
				stick_height--;
				sf::RectangleShape stick(sf::Vector2f(5, stick_height));
				stick.setFillColor(sf::Color::Black);
				stick.setPosition(stickx, 500);
				window.draw(stick);
				window.display();
				flag = true;
			}
			sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
			stick.setFillColor(sf::Color::Black);
			stick.setPosition(stickx, 498);
			while ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space) && flag && angle <= 90)
			{
				window.setFramerateLimit(300);
				sound.play();
				stick.setRotation(angle);
				angle++;
				window.clear(sf::Color::White);
				window.draw(back);
				window.draw(back2);
				window.draw(score);
				window.draw(lifee);
				window.draw(r1);
				window.draw(r2);
				window.draw(random_rect);
				window.draw(stickHero);
				window.draw(perfect_rect);
				window.draw(stick);
				window.display();
				if (angle == 91)
				{
					temporary = stick_height;
					stick_height = stick_width;
					stick_width = temporary;
					stick_height *= (-1);
					stick_width *= (-1);
					diff = random_rectx - (r2x + r2_width - 5);

					float rand_mid;
					rand_mid = (rand_width / 2.0) + (random_rectx - 15);
					if ((stick_width >= diff) && (stick_width <= diff + rand_width))
					{
						while (stickherox <= rand_mid)
						{
							window.setFramerateLimit(200);
							stickherox++;
							back_x -= 0.3;
							back2_x -= 0.3;
							if (back_x == -3000)
								back_x = 3000;
							if (back2_x == -3000)
								back2_x = 3000;
							back.setPosition(back_x, 0);
							back2.setPosition(back2_x, 0);
							stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
							window.clear(sf::Color::White);
							window.draw(back);
							window.draw(back2);
							window.draw(score);
							window.draw(lifee);
							window.draw(r1);
							window.draw(r2);
							window.draw(random_rect);
							window.draw(stickHero);
							window.draw(perfect_rect);
							window.draw(stick);
							if ((stickx + stick_width >= perfect_posx) && (stickx + stick_width <= perfect_posx + 5))
							{
								window.draw(text);
								prfct = true;
							}
							window.display();
						}
						if (prfct)
							cnt++;
						cnt++;

						///////////////////////////
						ss.str("");
						ss << "Score: " << cnt;
						score.setString(ss.str());
						//////////////////////////

						total_rect++;

						float r1_X = random_dist();
						stick_height = 0;
						sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
						if (r2x > -100 || random_rectx > 150 || r1x > r1_X)
						{
							while (r2x > -100 || random_rectx > 150 || r1x > r1_X)
							{
								window.setFramerateLimit(300);
								if (r2x > -100)
									r2x--;
								if (random_rectx > 150)
								{
									random_rectx--;
									stickherox--;
								}
								if (r1x > r1_X)
									r1x--;
								r1.setPosition(r1x, 500);
								r2.setPosition(r2x, 500);
								random_rect.setPosition(random_rectx, 500);
								stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
								window.clear(sf::Color::White);
								window.draw(back);
								window.draw(back2);
								window.draw(score);
								window.draw(lifee);
								window.draw(r1);
								window.draw(r2);
								window.draw(random_rect);
								window.draw(stickHero);
								window.draw(stick);
								window.display();
							}
							if (r2x == -100)
							{
								r2x = 900;
								r2_width = random_width();
								angle = 0;
								stick_width = 5;
								flag = false;
								prfct = false;
								perfect_posx = perfect(r1x, r1_width);
								i++;
							}
						}
					}
					else
					{
						while (!flag2)
						{
							if (stickherox > (r2x + r2_width + stick_width))
							{
								while (stickheroy < 800)
								{
									window.setFramerateLimit(300);
									stickheroy += 0.5;
									stickHero.setRotation(die_angle);
									die_angle++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
									flag2 = true;
									gameOver = true;
								}
							}
							else
							{
								while (stickherox <= (r2x + r2_width + stick_width))
								{
									window.setFramerateLimit(200);
									stickherox++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
								}
							}
						}
					}
					while (gameOver)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							life = 2;
							HighScore h;
							ppp = h.score();
							if (cnt > ppp)
							{
								goto scoring;
							}
							else
							{
								cnt = 0;
								goto main_menu;
							}
						}
						else
						{
							if (life > 0)
							{
								life--;
								s.str("");
								s << "Life: " << life + 1;
								lifee.setString(s.str());
								goto new_game;
							}
							else if (life == 0)
							{
								/////////////////////////////////////////////

								sf::Font scre;
								scre.loadFromFile("high.ttf");

								std::stringstream sss;
								sss << "Your Score: " << cnt;

								sf::Text pp;
								pp.setCharacterSize(90);
								pp.setColor(sf::Color::Black);
								pp.setFont(scre);
								pp.setString(sss.str());
								pp.setPosition(900 / 2 - pp.getGlobalBounds().width / 2, 350);

								/////////////////////////////////////////////

								window.clear();
								window.draw(game_over);
								window.draw(pp);
								window.display();
							}
						}
					}
				}
			}
			stick.setPosition(r2x + r2_width - 5, 498);
		}
		//i == 1 ends//////////////////////////////////////////////////////////////////////////


		//i == 2 starts///////////////////////////////////////////////////////////////////////

		if (i == 2)
		{
			flag2 = false;
			gameOver = false;
			

			sf::RectangleShape r1(sf::Vector2f(r1_width, 300));
			sf::RectangleShape r2(sf::Vector2f(r2_width, 300));
			sf::RectangleShape random_rect(sf::Vector2f(rand_width, 300));
			sf::RectangleShape perfect_rect(sf::Vector2f(perfect_width, perfect_height));

			r1.setFillColor(sf::Color::Black);
			r2.setFillColor(sf::Color::Black);
			random_rect.setFillColor(sf::Color::Black);
			perfect_rect.setFillColor(sf::Color::Red);

			r1.setPosition(r1x, 500);
			r2.setPosition(r2x, 500);
			random_rect.setPosition(random_rectx, 500);
			perfect_rect.setPosition(perfect_posx, 500);

			float stickx;
			stickx = 150 + rand_width - 5;

			stick.setPosition(stickx, 500);
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				window.setFramerateLimit(300);
				stick_height--;
				sf::RectangleShape stick(sf::Vector2f(5, stick_height));
				stick.setFillColor(sf::Color::Black);
				stick.setPosition(stickx, 500);
				window.draw(stick);
				window.display();
				flag = true;
			}
			sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
			stick.setFillColor(sf::Color::Black);
			stick.setPosition(stickx, 498);
			while ((event.type == sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space) && flag && angle <= 90)
			{
				window.setFramerateLimit(300);
				sound.play();
				stick.setRotation(angle);
				angle++;
				window.clear(sf::Color::White);
				window.draw(back);
				window.draw(back2);
				window.draw(score);
				window.draw(lifee);
				window.draw(r1);
				window.draw(r2);
				window.draw(random_rect);
				window.draw(stickHero);
				window.draw(perfect_rect);
				window.draw(stick);
				window.display();
				if (angle == 91)
				{
					temporary = stick_height;
					stick_height = stick_width;
					stick_width = temporary;
					stick_height *= (-1);
					stick_width *= (-1);
					diff = r1x - (random_rectx + rand_width - 5);

					float r1_mid;
					r1_mid = (r1_width / 2.0) + (r1x - 15);
					if ((stick_width >= diff) && (stick_width <= diff + r1_width))
					{
						while (stickherox <= r1_mid)
						{
							window.setFramerateLimit(200);
							stickherox++;
							back_x -= 0.3;
							back2_x -= 0.3;
							if (back_x == -3000)
								back_x = 3000;
							if (back2_x == -3000)
								back2_x = 3000;
							back.setPosition(back_x, 0);
							back2.setPosition(back2_x, 0);
							stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
							window.clear(sf::Color::White);
							window.draw(back);
							window.draw(back2);
							window.draw(score);
							window.draw(lifee);
							window.draw(r1);
							window.draw(r2);
							window.draw(random_rect);
							window.draw(stickHero);
							window.draw(perfect_rect);
							window.draw(stick);
							if ((stickx + stick_width >= perfect_posx) && (stickx + stick_width <= perfect_posx + 5))
							{
								window.draw(text);
								prfct = true;
							}
							window.display();
						}
						if (prfct)
							cnt++;
						cnt++;

						///////////////////////////
						ss.str("");
						ss << "Score: " << cnt;
						score.setString(ss.str());
						//////////////////////////

						total_rect++;

						float r2_X = random_dist();

						stick_height = 0;
						sf::RectangleShape stick(sf::Vector2f(stick_width, stick_height));
						if (random_rectx > -100 || r1x > 150 || r2x > r2_X)
						{
							while (random_rectx > -100 || r1x > 150 || r2x > r2_X)
							{
								window.setFramerateLimit(300);
								if (random_rectx > -100)
									random_rectx--;
								if (r1x > 150)
								{
									r1x--;
									stickherox--;
								}
								if (r2x > r2_X)
									r2x--;
								r1.setPosition(r1x, 500);
								r2.setPosition(r2x, 500);
								random_rect.setPosition(random_rectx, 500);
								stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
								window.clear(sf::Color::White);
								window.draw(back);
								window.draw(back2);
								window.draw(score);
								window.draw(lifee);
								window.draw(r1);
								window.draw(r2);
								window.draw(random_rect);
								window.draw(stickHero);
								window.draw(stick);
								window.display();
							}
							if (random_rectx == -100)
							{
								random_rectx = 900;
								rand_width = random_width();
								angle = 0;
								stick_width = 5;
								flag = false;
								prfct = false;
								perfect_posx = perfect(r2x, r2_width);
								i++;
								i %= 3;
							}
						}
					}
					else
					{
						while (!flag2)
						{
							if (stickherox > (random_rectx + rand_width + stick_width))
							{
								while (stickheroy < 800)
								{
									window.setFramerateLimit(300);
									stickheroy += 0.5;
									stickHero.setRotation(die_angle);
									die_angle++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
									flag2 = true;
									gameOver = true;
								}
							}
							else
							{
								while (stickherox <= (random_rectx + rand_width + stick_width))
								{
									window.setFramerateLimit(200);
									stickherox++;
									stickHero.setPosition(sf::Vector2f(stickherox, stickheroy));
									window.clear(sf::Color::White);
									window.draw(back);
									window.draw(back2);
									window.draw(score);
									window.draw(lifee);
									window.draw(r1);
									window.draw(r2);
									window.draw(random_rect);
									window.draw(stickHero);
									window.draw(perfect_rect);
									window.draw(stick);
									window.display();
								}
							}
						}
					}
					while (gameOver)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
						{
							life = 2;
							HighScore h;
							ppp = h.score();
							if (cnt > ppp)
							{
								goto scoring;
							}
							else
							{
								cnt = 0;
								goto main_menu;
							}
						}
						else
						{
							if (life > 0)
							{
								life--;
								s.str("");
								s << "Life: " << life + 1;
								lifee.setString(s.str());
								goto new_game;
							}
							else if (life == 0)
							{
								/////////////////////////////////////////////

								sf::Font scre;
								scre.loadFromFile("high.ttf");

								std::stringstream sss;
								sss << "Your Score: " << cnt;

								sf::Text pp;
								pp.setCharacterSize(90);
								pp.setColor(sf::Color::Black);
								pp.setFont(scre);
								pp.setString(sss.str());
								pp.setPosition(900 / 2 - pp.getGlobalBounds().width / 2, 350);

								/////////////////////////////////////////////

								window.clear();
								window.draw(game_over);
								window.draw(pp);
								window.display();
							}
						}
					}
				}
			}
			stick.setPosition(random_rectx + rand_width - 5, 498);
		}


		sf::RectangleShape r1(sf::Vector2f(r1_width, 300));
		sf::RectangleShape r2(sf::Vector2f(r2_width, 300));
		sf::RectangleShape random_rect(sf::Vector2f(rand_width, 300));
		sf::RectangleShape perfect_rect(sf::Vector2f(perfect_width, perfect_height));

		r1.setFillColor(sf::Color::Black);
		r2.setFillColor(sf::Color::Black);
		random_rect.setFillColor(sf::Color::Black);
		perfect_rect.setFillColor(sf::Color::Red);

		r1.setPosition(r1x, 500);
		r2.setPosition(r2x, 500);
		random_rect.setPosition(random_rectx, 500);
		perfect_rect.setPosition(perfect_posx, 500);

		window.clear(sf::Color::White);

		window.draw(back);
		window.draw(back2);
		window.draw(r1);
		window.draw(r2);
		window.draw(random_rect);
		window.draw(stickHero);
		window.draw(perfect_rect);
		window.draw(stick);
		window.draw(score);
		window.draw(lifee);

		window.display();

		

	}
	musicc.play();
}


scoring:
{
	int xx = 1;
	string name;

	int aa;
	bool flagg = false;
	int ccc = cnt;
	cnt = 0;

	while (window.isOpen())
	{
		window.setFramerateLimit(300);

		sf::Texture g_over;
		g_over.loadFromFile("nameSave.jpg");
		sf::Sprite gover;
		gover.setTexture(g_over);
		gover.setPosition(0, 0);


		sf::Font fnt;
		fnt.loadFromFile("Pacifico.ttf");


		bool br = 1;




		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();


				break;

			case sf::Event::TextEntered:
				if (event.text.unicode != 13 && event.text.unicode != 8)
				{
					name.push_back((char)event.text.unicode);
				}
				else if (event.text.unicode == 8)
				{
					if (!name.empty())
						name.pop_back();
				}
				else if (!name.empty() && event.text.unicode == 13)
				{
					br = 0;
				}
				break;
				break;
			}
		}

		if (!br)
		{
			std::ofstream ofs("example.txt", std::ofstream::out);

			ofs << name;
			ofs << "\n";
			ofs << ccc;
			ofs.close();
		}


		if (!br)
		{
			std::ofstream ofs("example.txt", std::ofstream::out);

			ofs << name;
			ofs << "\n";
			ofs << ccc;
			ofs.close();
			goto main_menu;
		}


		sf::Font font;
		font.loadFromFile("high.ttf");
		sf::Text text;
		text.setFont(font);
		text.setString(name);
		text.setColor(sf::Color::Black);
		text.setCharacterSize(75);
		text.setPosition(900 / 2 - text.getGlobalBounds().width / 2, 330);


		window.clear();


		window.draw(gover);

		window.draw(text);

		window.display();
	}
}



exit_game:
{
	return EXIT_SUCCESS;
}
}
