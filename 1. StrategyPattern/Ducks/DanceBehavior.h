#pragma once
#include <iostream>

struct IDanceBehavior
{
	virtual ~IDanceBehavior() {};
	virtual void Dance() = 0;
};

class DanceTheWaltz : public IDanceBehavior
{
public:
	void Dance() override;
};

class DanceTheMinuet : public IDanceBehavior
{
public:
	void Dance() override;
};

class DanceNoWay : public IDanceBehavior
{
public:
	void Dance() override;
};

