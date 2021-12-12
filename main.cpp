#include "source/Game.h"

int main()
{
	Music music;
	RenderWindow window(VideoMode(1203, 821), "The Game!");
	Texture gameover;
	Sprite gameover1;
	int a = RunGame();

	if (a == -1) {
		music.openFromFile("files/mario_die.ogg");
		music.play();
		gameover.loadFromFile("files/images/game_over.png");		
		gameover1.setTexture(gameover);
		gameover1.setTextureRect(IntRect(400, 150, 1203, 821));
		gameover1.setPosition(0, 0);
	}
	else if (a == 0) {
		music.openFromFile("files/game_over.ogg");
		music.play();
		gameover.loadFromFile("files/images/won.png");
		gameover1.setTexture(gameover);
		gameover1.setTextureRect(IntRect(100, 50, 650, 400));
		gameover1.setPosition(270, 250);
	}

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(gameover1);
		window.display();
	}

	return 0;
}

