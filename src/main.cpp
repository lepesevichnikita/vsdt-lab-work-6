#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <QtQml/QQmlApplicationEngine>

#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

int main(int argc, char *argv[])
{
  QUrl mainUrl(QStringLiteral("qrc:///main.qml"));
  QGuiApplication app(argc, argv);
  qmlRegisterType<Task1>("vsdt.labwork6", 1, 0, "Task1");
  qmlRegisterType<Task2>("vsdt.labwork6", 1, 0, "Task2");
  qmlRegisterType<Task3>("vsdt.labwork6", 1, 0, "Task3");
  qmlRegisterType<Task4>("vsdt.labwork6", 1, 0, "Task4");

  QQmlApplicationEngine engine;
  engine.load(mainUrl);
  return app.exec();
}
