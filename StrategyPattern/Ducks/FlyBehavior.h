#pragma once

struct IFlyBehavior
{
	virtual ~IFlyBehavior() {};
	virtual void Fly() = 0;
};

class FlyWithWings : public IFlyBehavior
{
public:
	void Fly() override;

private:
	size_t m_countOfFlights = 0;
};

class FlyNoWay : public IFlyBehavior
{
public:
	void Fly() override;
};