#include "game.h"

RenderWindow window;

Game::Game(void)
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	window.create(VideoMode(800, 800), "Chess Game", Style::Default,
		settings);

	state = END;
	window.setFramerateLimit(60);

	if (!font.loadFromFile("arial.ttf"))
	{
		MessageBox(NULL, "Font not found!", "ERROR", NULL);
		return;
	}

	state = MENU;
}


Game::~Game(void)
{
}


void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case MENU:
			menu();
			break;
		case GAME:
			single();
			break;
		}
	}
}


void Game::menu()
{
	/*Text title("CHESS", font, 80);
	title.setStyle(Text::Bold);
	title.setFillColor(Color::White);

	title.setPosition(600 / 2 - title.getGlobalBounds().width / 2, 20);
*/
	const int ile = 3;

	Text tekst[ile];

	string str[] = { "Player vs Player","Player vs Computer","Exit" };
	for (int i = 0; i < ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 100 + i * 100);
	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			//klikniêcie PvP
			else if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
			}
			//klikniêcie PvsC
			else if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
			}

			//klikniêcie EXIT
			else if (tekst[2].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
		}
		for (int i = 0; i < ile; i++)
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setFillColor(Color::Green);
			else tekst[i].setFillColor(Color::White);

		window.clear(Color::White);

		Texture t;
		t.loadFromFile("images/menu.jpg");
		Sprite s(t);
		window.draw(s);
		/*window.draw(title);*/
		for (int i = 0; i < ile; i++)
			window.draw(tekst[i]);

		window.display();
	}
}

void Game::single()
{
	Engine engine(window);

	engine.runEngine();

	state = GAME; 
}