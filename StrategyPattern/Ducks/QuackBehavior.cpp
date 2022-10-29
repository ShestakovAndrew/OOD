#include <iostream>

#include "QuackBehavior.h"

void QuackBehavior::Quack()
{
	std::cout << "Quack Quack!!!" << std::endl;
}

void SqueakBehavior::Quack()
{
	std::cout << "Squeek!!!" << std::endl;
}

void MuteQuackBehavior::Quack()
{
}
