#ifndef _PLUGIN_H_
#define _PLUGIN_H_

class Plugin
{
    public:
        // default constructor
        virtual void test() { };
        virtual ~Plugin() {};
};

class PluginFactory
{
    public:
        virtual Plugin * getInstance() = 0;
};

#endif

