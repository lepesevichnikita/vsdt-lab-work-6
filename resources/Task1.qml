import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import QtQuick.Controls 1.4 as OldControls

import vsdt.labwork6 1.0

ColumnLayout {
  id: root
  anchors.fill: parent
  anchors.margins: 20

  Task1 {
    id: task1
  }

  Label {
    Layout.fillWidth: true
    Layout.fillHeight: true
    text: qsTr("Индекс вектора с наименьшей суммой элементов ") + (task1.indexOfVectorWithMaxSumOfItems + 1)
  }

  RowLayout {
      Label {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: qsTr("Произведение ненулевых элементов данного вектора ")
      }
      TextField {
        Layout.fillWidth: true
        Layout.fillHeight: true
        text: task1.productOfNonZeroItems
        readOnly: true
        selectByMouse: true
      }
  }

  Repeater {
    model: task1.matrix.length
    delegate: RowLayout {
      id: row
      property var numbers: task1.matrix[index]
      property int row: index
      Repeater {
        model: numbers.length
        delegate: TextField {
          id: textField
          property int column: index
          Layout.fillWidth: true
          Layout.fillHeight: true
          text: numbers[index].toFixed(2)
          readOnly: true
          selectByMouse: true

          onEditingFinished: {
            var changedMatrix = task1.matrix
            changedMatrix[parent.row][column] = parseFloat(text)
            task1.matrix = changedMatrix
          }
        }
      }
    }
  }
}
