#include <QCoreApplication>

#include "application.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Application *application = new Application();

    QObject::connect(application, &Application::destroyed, &a, &QCoreApplication::quit);

    return a.exec();
}
