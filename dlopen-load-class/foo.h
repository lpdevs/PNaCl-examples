#ifndef _FOO_H_
#define _FOO_H_

#include "plugin.h"

class Foo : public Plugin
{
    public:
        Foo();
        ~Foo();
        virtual void test();
};


class FooFactory : PluginFactory
{
    public:
        Foo * getInstance();
};

FooFactory gFooFactory;

#endif
