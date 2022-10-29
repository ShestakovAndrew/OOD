#pragma once

struct IQuackBehavior
{
	virtual ~IQuackBehavior() {};
	virtual void Quack() = 0;
};

class QuackBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};

class SqueakBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};

class MuteQuackBehavior : public IQuackBehavior
{
public:
	void Quack() override;
};