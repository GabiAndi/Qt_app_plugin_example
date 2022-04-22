#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#include <QDebug>
#include <QCoreApplication>
#include <QPluginLoader>
#include <QDir>
#include <QTimer>

#include "plugininterface.h"

class Application : public QObject
{
        Q_OBJECT

    public:
        explicit Application(QObject *parent = nullptr);
        ~Application();

    private:
        const char *PLUGINS_DIR = "plugins";

        QObjectList *pluginList = nullptr;

        QTimer *appCloseTimer = nullptr;
};

#endif // APPLICATION_H
