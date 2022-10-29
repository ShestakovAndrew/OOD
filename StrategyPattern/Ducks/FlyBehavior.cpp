#include <iostream>

#include "FlyBehavior.h"

void FlyWithWings::Fly()
{
	++m_countOfFlights;
	std::cout << "I'm flying with wings for the " << m_countOfFlights << " time(s)" << std::endl;
}

void FlyNoWay::Fly()
{
}
