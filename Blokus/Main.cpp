#include "Application.h"
#include "ResourceIdentifiers.h"
#include "ResourceHolder.h"

void loadResources(FontHolder& fonts) {
	fonts.open(Fonts::Helvetica, "Resource/Fonts/Helvetica.ttf");
}

int main() {
	FontHolder fonts;
	loadResources(fonts);

	Application app(fonts);
	app.run();

	return 0;
}