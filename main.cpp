#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include "control.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    qDebug()<<"Jason test";
    QObject* topLevel     = engine.rootObjects().first();
    QQuickWindow* rootWin = qobject_cast<QQuickWindow *>( topLevel );
    control *control = new class control();
    control->initialize( rootWin );



    return app.exec();
}
