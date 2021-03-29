#include "Engine.h"




Engine::Engine(RenderWindow &win)
{
	window = &win;
	
	
	

}


Engine::~Engine()
{
}
void Engine::runEngine()
{
	/*Event event;
	Vector2i pos(Mouse::getPosition(*window));
	Texture t1;
	t1.loadFromFile("images/figury.png");
	Sprite s1(t1);

	if(event.type==Event::MouseButtonPressed)
		if(event.key.code==Mouse::Left)
			if (s1.getGlobalBounds().contains(pos.x, pos.y))
			{
				isMove = true;
				dx = pos.x - s1.getPosition().x;
				dy = pos.y - s1.getPosition().y;
			}
	if (event.type == Event::MouseButtonReleased)
		if (event.key.code == Mouse::Left)
			isMove = false;

	if(isMove) s1.setPosition(pos.x-dx,pos.y-dy);*/
	draw();

}

void Engine::draw()
{
	Texture t;
	t.loadFromFile("images/board.png");
	Sprite s(t);
	window->clear(sf::Color::White);
	window->draw(s);
	window->display();

}
