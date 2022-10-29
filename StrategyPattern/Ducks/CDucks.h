#pragma once
#include <memory>

#include "DanceBehavior.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

using namespace std;

class CDuck
{
public:
	CDuck(unique_ptr<IFlyBehavior>&& flyBehavior, unique_ptr<IQuackBehavior>&& quackBehavior, unique_ptr<IDanceBehavior>&& danceBehavior);
	void Swim() const;
	void Quack() const;
	void Fly() const;
	void Dance() const;
	void SetFlyBehavior(unique_ptr<IFlyBehavior>&& flyBehavior);
	void SetQuackBehavior(unique_ptr<IQuackBehavior>&& quackBehavior);
	void SetDanceBehavior(unique_ptr<IDanceBehavior>&& danceBehavior);
	virtual void Display() const = 0;
	virtual ~CDuck() = default;

private:
	unique_ptr<IFlyBehavior> m_flyBehavior;
	unique_ptr<IQuackBehavior> m_quackBehavior;
	unique_ptr<IDanceBehavior> m_danceBehavior;
};

class MallardDuck : public CDuck
{
public:
	MallardDuck()
		: CDuck(make_unique<FlyWithWings>(), make_unique<QuackBehavior>(), make_unique<DanceTheWaltz>())
	{
	}

	void Display() const override;
};

class RedheadDuck : public CDuck
{
public:
	RedheadDuck()
		: CDuck(make_unique<FlyWithWings>(), make_unique<QuackBehavior>(), make_unique<DanceTheMinuet>())
	{
	}
	void Display() const override;
};

class DecoyDuck : public CDuck
{
public:
	DecoyDuck()
		: CDuck(make_unique<FlyNoWay>(), make_unique<MuteQuackBehavior>(), make_unique<DanceNoWay>())
	{
	}
	void Display() const override;
};

class RubberDuck : public CDuck
{
public:
	RubberDuck()
		: CDuck(make_unique<FlyNoWay>(), make_unique<SqueakBehavior>(), make_unique<DanceNoWay>())
	{
	}
	void Display() const override;
};

class ModelDuck : public CDuck
{
public:
	ModelDuck()
		: CDuck(make_unique<FlyNoWay>(), make_unique<QuackBehavior>(), make_unique<DanceNoWay>())
	{
	}
	void Display() const override;
};
