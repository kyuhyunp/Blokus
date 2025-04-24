#include "ResourceManager.h"

ResourceManager::ResourceManager() {


	if (!mFont.openFromMemory(&helvetica_255_Helvetica_ttf, helvetica_255_Helvetica_ttf_len)) {
		throw std::runtime_error("Error while loading the font Helvetica.");
	}
}

const sf::Font& ResourceManager::getFont() const{
	return mFont;
}
