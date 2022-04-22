#ifndef PLUGINBASE_H
#define PLUGINBASE_H

#include <QtPlugin>

class PluginInterface
{
    public:
        virtual float getValue() = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "GabiAndi.PluginInterface")

#endif // PLUGINBASE_H
