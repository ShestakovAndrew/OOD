#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Observer.h"
#include "ObserverTest.h"

TEST_CASE("Removing yourself in method Update should`t lead undefined behavior.")
{
	CWeatherData wd;

	CRemovedObserverTest display(wd);
	wd.RegisterObserver(display, 1);

	wd.SetMeasurements(3, 0.7, 760);
}

TEST_CASE("High priority observers should be alerted first.")
{
	std::stringstream ss;
	CWeatherData wd;

	CPriorityObserverTest ob1(ss, 1);	
	CPriorityObserverTest ob2(ss, 2);
	CPriorityObserverTest ob3(ss, 3);

	wd.RegisterObserver(ob1, 1);
	wd.RegisterObserver(ob2, 3);
	wd.RegisterObserver(ob3, 2);

	wd.SetMeasurements(3, 0.7, 760);

	REQUIRE(ss.str() == "231");
}