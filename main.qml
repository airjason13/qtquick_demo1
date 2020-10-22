import QtQuick 2.12
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Window {
    id: mainWin
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property alias samplebutton : button

    signal qmlSetName( string name )
    signal qmlUpdateName( string name )

    Button {

        id: button
        x: 186
        y: 127
        width: 121
        height: 108
        text: "TEXT"
        //onClicked: mainWin.qmlSetName("Jason")

        Connections {
            target: button
            onClicked: mainWin.qmlSetName("Jason")
        }
    }
}
