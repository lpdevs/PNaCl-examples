#ifndef _BAR_H_
#define _BAR_H_

#include "plugin.h"

class Bar : public Plugin
{
    public:
        Bar();
        ~Bar();
        virtual void test();
};

class BarFactory : PluginFactory
{
    public:
        Bar * getInstance();
};

BarFactory gBarFactory;

#endif
