#define CATCH_CONFIG_MAIN
#include <sstream>

#include <catch2/catch.hpp>
#include "../ObjectAdapter/app.h"

TEST_CASE("Drawing a line between BeginDraw() and EndDraw() should be successfully")
{
	std::stringstream ss;
	modern_graphics_lib::CModernGraphicsRenderer renderer(ss);
	app::CModernGraphicsAdapter adapter(renderer);

	renderer.BeginDraw();
	adapter.MoveTo(1, 2);
	adapter.LineTo(3, 4);
	renderer.EndDraw();

	CHECK(ss.str() == "<draw>\n\t<line fromX=\"1\" fromY=\"2\" toX=\"3\" toY=\"4\">\n\t</line>\n</draw>\n");
}

TEST_CASE("Without calling BeginDraw() on renderer should be impossible call methods on adapter")
{
	std::stringstream ss;
	modern_graphics_lib::CModernGraphicsRenderer renderer(ss);
	app::CModernGraphicsAdapter adapter(renderer);

	CHECK_THROWS(renderer.DrawLine({ 1, 2 }, { 3, 4 }));
}

TEST_CASE("After destroying renderer should be impossible call methods on adapter")
{
	std::stringstream ss;
	modern_graphics_lib::CModernGraphicsRenderer renderer(ss);
	renderer.BeginDraw();

	{
		app::CModernGraphicsAdapter adapter(renderer);

		adapter.MoveTo(1, 2);
		adapter.LineTo(3, 4);
	}

	CHECK_NOTHROW(renderer.DrawLine({ 1, 2 }, { 3, 4 }));
}

TEST_CASE("After calling EndDraw() on renderer, should not be call methods on adapter")
{
	std::stringstream ss;
	modern_graphics_lib::CModernGraphicsRenderer renderer(ss);
	app::CModernGraphicsAdapter adapter(renderer);

	renderer.BeginDraw();
	adapter.MoveTo(1, 2);
	adapter.LineTo(3, 4);
	renderer.EndDraw();

	CHECK_THROWS(adapter.LineTo(100, 200));
}