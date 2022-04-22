#include "lightsensorplugin.h"

LightSensorPlugin::LightSensorPlugin(QObject *parent)
    : QObject(parent)
{
    qInfo() << "Sensor de luz creado";
}

LightSensorPlugin::~LightSensorPlugin()
{
    qInfo() << "Sensor de luz destruido";
}

float LightSensorPlugin::getValue()
{
    return _value += 0.1;
}
