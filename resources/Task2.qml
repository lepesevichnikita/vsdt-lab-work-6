import QtQuick 2.7
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.3

import vsdt.labwork6 1.0

ColumnLayout {
  id: root

  anchors.fill: parent
  anchors.margins: 20

  FileDialog {
    id: fileDialog
    title: qsTr("Пожалуйста, выберите изображение")
    folder: shortcuts.pictures
    selectMultiple: false

    Component.onCompleted: {
      visible: true
    }
  }

  Task2 {
    id: task
    imageName: fileDialog.fileUrl
  }

  RowLayout {
    ColumnLayout {
      Label {
        Layout.fillWidth: true
        text: qsTr("Минимальная интенсивность")
      }
      TextField {
        Layout.fillWidth: true
        text: task.minDepth
        onEditingFinished: {
          task.minDepth = parseInt(text) || 0
        }
      }
    }
    ColumnLayout {
      Label {
        Layout.fillWidth: true
        text: qsTr("Максимальная интенсивность")
      }
      TextField {
        Layout.fillWidth: true
        text: task.maxDepth
        onEditingFinished: {
          task.maxDepth = parseInt(text) || 0
        }
      }
    }
  }

  Label {
    Layout.fillWidth: true
    text: qsTr("Выбранный файл:") + fileDialog.fileUrl
  }

  Button {
    Layout.fillWidth: true
    text: qsTr("Выбрать изображение")
    onClicked: {
      fileDialog.open()
    }
  }


  RowLayout {
    ColumnLayout {
      Label {
        Layout.fillWidth: true
        text: qsTr("Исходное изображение")
      }
      Image {
        id: selectedFile
        Layout.fillWidth: true
        Layout.fillHeight: true
        source: fileDialog.fileUrl
      }
    }
    ColumnLayout {
      Label {
        Layout.fillWidth: true
        text: qsTr("Изменённое изображение")
      }
      Image {
        id: changedFile
        Layout.fillWidth: true
        Layout.fillHeight: true
        source: task.imageAsBase64
      }
    }
  }

  Label {
    Layout.fillWidth: true
    text: qsTr("Высота:") + selectedFile.sourceSize.height
  }
  Label {
    Layout.fillWidth: true
    text: qsTr("Ширина :") + selectedFile.sourceSize.width
  }
}
