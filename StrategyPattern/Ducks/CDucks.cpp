#include <cassert>
#include <iostream>

#include "CDucks.h"

CDuck::CDuck(unique_ptr<IFlyBehavior>&& flyBehavior,
	unique_ptr<IQuackBehavior>&& quackBehavior,
	unique_ptr<IDanceBehavior>&& danceBehavior)
{
	assert(flyBehavior);
	assert(quackBehavior);
	assert(danceBehavior);

	SetFlyBehavior(move(flyBehavior));
	SetQuackBehavior(move(quackBehavior));
	SetDanceBehavior(move(danceBehavior));
}

void CDuck::Swim() const
{
	cout << "I'm swimming" << endl;
}

void CDuck::Quack() const
{
	m_quackBehavior->Quack();
}

void CDuck::Fly() const
{
	m_flyBehavior->Fly();
}

void CDuck::Dance() const
{
	m_danceBehavior->Dance();
}

void CDuck::SetFlyBehavior(unique_ptr<IFlyBehavior>&& flyBehavior)
{
	assert(flyBehavior);
	m_flyBehavior = move(flyBehavior);
}

void CDuck::SetQuackBehavior(unique_ptr<IQuackBehavior>&& quackBehavior)
{
	assert(quackBehavior);
	m_quackBehavior = move(quackBehavior);
}

void CDuck::SetDanceBehavior(unique_ptr<IDanceBehavior>&& danceBehavior)
{
	assert(danceBehavior);
	m_danceBehavior = move(danceBehavior);
}

void MallardDuck::Display() const
{
	cout << "I'm mallard duck!" << endl;
}

void RedheadDuck::Display() const
{
	cout << "I'm redhead duck!" << endl;
}

void DecoyDuck::Display() const
{
	cout << "I'm decoy duck!" << endl;
}

void RubberDuck::Display() const
{
	cout << "I'm rubber duck!" << endl;
}

void ModelDuck::Display() const
{
	cout << "I'm model duck!" << endl;
}
