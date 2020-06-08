#include <iostream>
#include "Utility.h"

void Print(const char* message)
{
	std::cout << message << std::endl;
}

void ClearScreen()
{
	system("CLS");
}