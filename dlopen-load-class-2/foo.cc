#include "foo.h"
#include <iostream>

using namespace std;

Foo::Foo()
{
	cout << "	Foo created [foo.cc - Foo::Foo()]" << endl; 
}

Foo::~Foo()
{
	cout << "	Foo destroyed [foo.cc - Foo::~Foo()]" << endl; 
}

void Foo::test()
{
	cout << "	Foo tested [Foo.cc - Foo::test()]" << endl;
}

Foo* FooFactory::getInstance()
{
	cout << "	Making foo [foo.cc FooFactory::getInstance()]" << endl;  
	return new Foo; 
}

