import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    color: "#2c4762"

    Text {
        text: "Tumblr Reader"
        color: "white"
        font.pixelSize: 30
        font.bold: true
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
