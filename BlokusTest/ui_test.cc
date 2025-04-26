#include "pch.h"
#include "../Blokus/Sidebar.h"
#include <memory>
#include <SFML/Graphics.hpp>

namespace ui_test {

	class MockSidebar : public Sidebar {
	public:
		MockSidebar(const ResourceManager& rm) : Sidebar(rm) {}
			MOCK_METHOD(void, updateBorder, (), (override));

	};
    
    

	TEST(SidebarTest, ResizeTest) {
		ResourceManager rm;
		MockSidebar sidebar(rm);
		EXPECT_CALL(sidebar, updateBorder())                  
			.Times(::testing::AtLeast(1));

		// Original
		EXPECT_NO_THROW(sidebar.resize());


	
	}
}

