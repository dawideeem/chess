#include "Engine.h"



void Engine::loadPosition()
{
	int k = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			int n = board[i][j];
			if (!n) continue;
			int x = abs(n) - 1;
			int y = n > 0 ? 1 : 0;
			f[k].setTextureRect(IntRect(size * x, size * y, size, size));
			f[k].setPosition(size * j, size * i);
			k++;
		}

}

Engine::Engine(RenderWindow& win)
{
	window = &win;




}


Engine::~Engine()
{
}
void Engine::runEngine()
{

	Texture t1, t2;
	t1.loadFromFile("images/figures1.png");
	t2.loadFromFile("images/board.png");
	Sprite s(t1);
	Sprite s1(t2);

	for (int i = 0; i < 32; i++) f[i].setTexture(t1);

	loadPosition();


	while (window->isOpen())
	{

		Vector2i pos(Mouse::getPosition(*window));
		while (window->pollEvent(e)) {
			if (e.type == Event::Closed) window->close();

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
					for(int i=0;i<32;i++)
					if (f[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						isMove = true; n = i;
						dx = pos.x - f[i].getPosition().x;
						dy = pos.y - f[i].getPosition().y;
					}
			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					isMove = false;
					Vector2f p = f[n].getPosition() + Vector2f(size / 2, size / 2);
					Vector2f newPos = Vector2f(size * int(p.x / size), size * int(p.y / size));
					f[n].setPosition(newPos);
				}
			if (isMove) f[n].setPosition(pos.x - dx, pos.y - dy);
		}
		window->clear(sf::Color::White);
		window->draw(s1);
		for (int i = 0; i < 32; i++) window->draw(f[i]);
		window->display();
	}
}

