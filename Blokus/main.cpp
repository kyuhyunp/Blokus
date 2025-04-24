#include "Application.h"


int main() {
	ResourceManager resourceManager;
	Application app(resourceManager);
	app.run();

	return 0;
}