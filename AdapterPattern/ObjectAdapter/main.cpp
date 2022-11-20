#include "app.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Should we use new API (y)?";
	std::string userInput;
	if (std::getline(std::cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return 0;
}
