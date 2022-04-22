#include "tempsensorplugin.h"

TempSensorPlugin::TempSensorPlugin(QObject *parent)
    : QObject(parent)
{
    qInfo() << "Sensor de temperatura creado";
}

TempSensorPlugin::~TempSensorPlugin()
{
    qInfo() << "Sensor de temperatura destruido";
}

float TempSensorPlugin::getValue()
{
    return _value += 0.1;
}
