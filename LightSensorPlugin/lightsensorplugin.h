#ifndef TEMPSENSORPLUGIN_H
#define TEMPSENSORPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include <QDebug>

#include "plugininterface.h"

class LightSensorPlugin : public QObject, PluginInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "GabiAndi.LightSensorPlugin")
        Q_INTERFACES(PluginInterface)

    public:
        explicit LightSensorPlugin(QObject *parent = nullptr);
        ~LightSensorPlugin();

        float getValue() override;

    private:
        float _value = 0;
};

#endif // TEMPSENSORPLUGIN_H
