#include <QApplication>
#include <QQmlApplicationEngine>
#include <serial.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlEngine engine;

    Serial seri;
    engine.rootContext()->setContextProperty("seri",&seri);
    QQmlComponent component(&engine,QUrl(QStringLiteral("qrc:/main.qml")));
    component.create();
    return app.exec();
}
