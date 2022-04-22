#include "application.h"

Application::Application(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Creado el controlador de aplicacion";

    // Timer
    appCloseTimer = new QTimer(this);

    connect(appCloseTimer, &QTimer::timeout, this, [this](){
        this->deleteLater();
    });

    appCloseTimer->setSingleShot(true);

    appCloseTimer->start(5000);

    // Se obtiene el nombre de todos los archivos bajo la carpeta "plugins"
    QDir pluginsDir(QCoreApplication::applicationDirPath());

    if (!pluginsDir.exists(PLUGINS_DIR))
    {
        pluginsDir.mkdir(PLUGINS_DIR);
    }

    pluginsDir.cd(PLUGINS_DIR);

    const QStringList pluginsFiles = pluginsDir.entryList(QDir::Filter::Files);

    // Carga de plugins bajo la carpeta "plugins"
    pluginList = new QObjectList();

    for (const QString &pluginFile : pluginsFiles)
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(pluginFile));

        QObject *pluginInstance = pluginLoader.instance();

        if (pluginInstance)
        {
            pluginList->append(pluginInstance);

            qInfo() << "Plugin" << pluginFile << "cargado";

            // Ver valores de los sensores
            PluginInterface *interface = qobject_cast<PluginInterface *>(pluginInstance);

            qDebug() << "Valor del sensor" << interface->getValue();
        }

        else
        {
            qInfo() << "Plugin" << pluginFile << "no cargado";

            qInfo() << pluginLoader.errorString();
        }
    }
}

Application::~Application()
{
    // Borramos el timer
    delete appCloseTimer;

    // Borramos las instancias de los plugins
    for (const QObject *plugin : *pluginList)
    {
        delete plugin;
    }

    delete pluginList;

    qInfo() << "Destruido el controlador de aplicacion";
}
