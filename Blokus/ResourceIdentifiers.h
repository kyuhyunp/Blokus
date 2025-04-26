#ifndef RESOURCEIDENTIFIER_H 
#define RESOURCEIDENTIFIER_H 

// Forward Declaration
namespace sf {
	class Font;
}

namespace Fonts {
	enum ID {
		Helvetica,
	};
}


template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;


#endif
