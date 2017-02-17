#include "bar.h"
#include <iostream>

using namespace std;

Bar::Bar()
{
	cout << "	Bar created [Bar.cc - Bar::Bar()]" << endl; 
}

Bar::~Bar()
{
	cout << "	Bar destroyed [Bar.cc - Bar::~Bar()]" << endl; 
}

void Bar::test()
{
	cout << "	Bar tested [Bar.cc - Bar::test()]" << endl;
}

Bar* BarFactory::getInstance()
{
	cout << "	Making Bar [Bar.cc BarFactory::getInstance()]" << endl;  
	return new Bar; 
}

