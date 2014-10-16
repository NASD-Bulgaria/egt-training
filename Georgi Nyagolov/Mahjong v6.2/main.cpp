#include "GameApplication.h"

int main(int argc, char* args[]) {
    GameApplication game;
	if (game.init()) {
		if (game.loadMedia()) {
            game.gameLoop();
		} else {
            printf("Failed to load media!\n");
		}
    } else {
		printf("Failed to initialize!\n");
	}
	return 0;
}
