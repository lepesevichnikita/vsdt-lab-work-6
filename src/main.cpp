#include <QtGui/QGuiApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  QQuickView view;
  view.setResizeMode(QQuickView::SizeViewToRootObject);
  view.setSource(QUrl(QString("qrc:///main.qml")));
  app.exec();
}
