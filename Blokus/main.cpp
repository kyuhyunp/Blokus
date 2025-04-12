#include "GameEngine.h"


int main() {
	ResourceManager resourceManager;
	GameEngine engine(resourceManager);
	engine.run();

	return 0;
}