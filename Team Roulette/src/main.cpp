#include "../GameObjects/RouletteApplication.h"

using namespace GameObjects;

int main(int argc, char* args[]) {
	RouletteApplication* app = new RouletteApplication();
	app->start();
	return 0;
}
