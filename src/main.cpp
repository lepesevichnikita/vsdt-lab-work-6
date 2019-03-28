#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QtQml/QQmlApplicationEngine>

#include "task1.h"

int main(int argc, char *argv[])
{
  QUrl mainUrl(QStringLiteral("qrc:///main.qml"));
  QGuiApplication app(argc, argv);
  qmlRegisterType<Task1>("vsdt.labwork6", 1, 0, "Task1");

  QQmlApplicationEngine engine;
  engine.load(mainUrl);
  return app.exec();
}
