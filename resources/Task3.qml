import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import vsdt.labwork6 1.0

ColumnLayout {
  id: root

  anchors.fill: parent
  anchors.margins: 20

  Task3 {
    id: task
  }

  RowLayout {
    ColumnLayout {
        Label {
            Layout.fillWidth: true
            text: qsTr("Ширина")
        }
        TextField {
            Layout.fillWidth: true
            text: task.width
            onEditingFinished: {
                task.width = Math.abs(parseInt(text)) || 0
            }
        }
    }
    ColumnLayout {
        Label {
            Layout.fillWidth: true
            text: qsTr("Высота")
        }
        TextField {
            Layout.fillWidth: true
            text: task.height
            onEditingFinished: {
                task.height = Math.abs(parseInt(text)) || 0
            }
        }
    }
  }

  Label {
    Layout.fillWidth: true
    text: qsTr("Исходная матрица")
  }
  Repeater {
    model: task.height
    delegate: RowLayout {
      property int row: index
      Repeater {
        model: task.width
        delegate: TextField {
          Layout.fillWidth: true
          Layout.fillHeight: true
          text: task.matrix[parent.row][index]
          readOnly: true
          selectByMouse: true
        }
      }
    }
  }

  Label {
    Layout.fillWidth: true
    text: qsTr("Результат")
  }

  RowLayout {
    Repeater {
      model: task.width
      delegate: TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: task.resultVector[modelData]
        readOnly: true
        selectByMouse: true
      }
    }
  }
}

