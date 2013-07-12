#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "backend.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Backend backend;

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/voicr/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
