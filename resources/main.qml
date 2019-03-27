import QtQuick 2.7
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

ApplicationWindow {
  minimumWidth: 640
  minimumHeight: 320

  title: qsTr("Лабораторная работа №6")
  visible: true

  footer: TabBar {
    id: bar
    width: parent.width

    Repeater {
      model: ["Первое", "Второе", "Третье"]

      TabButton {
        text: [qsTr(modelData), qsTr("задание")].join(" ")
      }
    }
  }

  StackLayout {
    anchors.fill: parent
    currentIndex: bar.currentIndex

    Item {
      Task1 {}
    }

    Item {
      Task2 {}
    }

    Item {
      Task3 {}
    }
  }

}
