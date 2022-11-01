#include "Designer.h"
#include <iostream>

CDesigner::CDesigner(IShapeFactory& factory)
	: m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& stream) const
{
	CPictureDraft draft;
	std::string line;

	while (std::getline(stream, line) && line != "exit")
	{
		try
		{
			draft.AddShape(m_factory.CreateShape(line));
		}
		catch (std::exception const& e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}
	}

	return draft;
}
