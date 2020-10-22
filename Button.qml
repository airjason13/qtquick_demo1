import QtQuick 2.0

Item {
    Rectangle {
        id: samplebutton
        color: "#d7d2cc"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#d7d2cc"
            }

            GradientStop {
                position: 1
                color: "#304352"
            }
        }
        anchors.fill: parent

        Connections {
            target: samplebutton
            onClicked: print("clicked")
        }


    }

}
