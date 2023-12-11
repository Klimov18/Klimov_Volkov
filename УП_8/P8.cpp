#include "Massive.h"
#include "Program.h"
#include<iostream>

int main()
{
	Program pr;
	Massive *list = new Massive;
	pr.menu(*list);
	return 0;
}
