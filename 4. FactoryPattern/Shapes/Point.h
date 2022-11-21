#pragma once

struct Point
{
	double x = 0;
	double y = 0;

	bool operator==(Point const& point) const
	{
		return ((*this).x == point.x) && ((*this).y == point.y);
	}
	bool operator!=(Point const& point) const
	{
		return !(*this == point);
	}
};
