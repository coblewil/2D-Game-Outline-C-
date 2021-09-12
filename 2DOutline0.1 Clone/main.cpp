#include "Game.h"
#include <iostream>
#include <memory>

int main(int argc, char* args[]) {

	printf( "Welcome to the Placeholder...\n" );
	std::shared_ptr<Game> game = Game::create("Placeholder", 800, 500);
	game->run();

	/*Game test{"Placeholder", 640, 360};
	test.run();*/

	return 0;
}