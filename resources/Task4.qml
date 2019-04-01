import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import vsdt.labwork6 1.0

ColumnLayout {
    id: root
    anchors.fill: parent
    anchors.margins: 20

    Task4 {
        id: task
    }

    Label {
        Layout.fillWidth: true
        text: qsTr("Результат")
    }
    Repeater {
        model: task.resultVector.length
        delegate: TextField {
            Layout.fillWidth: true
            text: task.resultVector[index].toFixed(2)
            readOnly: true
            selectByMouse: true
        }
    }
}
