#include <iostream>

#include "Canvas.h"
#include "Designer.h"
#include "Painter.h"
#include "ShapeFactory.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main()
{

	std::cout << "Use:\n"
		"line <outline color> <start point> <end point>"
		"rectangle <outline color> <fill color> <left top vertex> <width> <height>\n"
		"triangle <outline color> <fill color> <vertex 1> <vertex 2> <vertex 3>\n"
		"circle <outline color> <fill color> <center point> <radius>\n"
		"ellipse <outline color> <fill color> <center point> <horizontal radius> <vertical radius>\n"
		"regularPolygon <outline color> <fill color> <vertexe count> <center point> <radius>\n"
		"to stop enter shapes write \"exit\"\n\n";

	CShapeFactory factory;
	CDesigner designer(factory);
	CPictureDraft draft = designer.CreateDraft(std::cin);

	std::cout << "Do you want to draw draft? y/n" << std::endl;
	std::string answer;
	std::cin >> answer;

	if (answer == "y")
	{
		sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Shapes");
		CCanvas canvas(window);

		CPainter painter;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}

			window.clear(sf::Color::White);
			painter.DrawPicture(draft, canvas);
			window.display();
		}
	}

	return 0;
}