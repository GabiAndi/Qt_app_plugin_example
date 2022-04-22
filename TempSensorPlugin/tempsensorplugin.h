#ifndef TEMPSENSORPLUGIN_H
#define TEMPSENSORPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "plugininterface.h"

#include <QDebug>

class TempSensorPlugin : public QObject, PluginInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID "GabiAndi.TempSensorPlugin")
        Q_INTERFACES(PluginInterface)

    public:
        explicit TempSensorPlugin(QObject *parent = nullptr);
        ~TempSensorPlugin();

        float getValue() override;

    private:
        float _value = 0;
};

#endif // TEMPSENSORPLUGIN_H
