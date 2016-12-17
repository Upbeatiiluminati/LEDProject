import QtQuick 2.5
import QtQuick.Controls 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    color: "#171212"
    maximumHeight: 720
    maximumWidth: 1280
    minimumHeight: 720
    minimumWidth: 1280
    StackLayout {
        id: swapView
        anchors.fill: parent
        Image {
            id: fc
            source: "FilledCircle.png"
            anchors.centerIn: parent

            RowLayout {
                anchors.verticalCenterOffset: 0
                anchors.horizontalCenterOffset: 15
                anchors.centerIn: parent
                Dial {
                    id: dial1
                    stepSize: 1
                    from: 0
                    value: 5
                    to: 255
                    Layout.preferredHeight: 190
                    Layout.preferredWidth: 190
                 onValueChanged: seri.change_Color(qsTr("r %1").arg(dial1.value))
                    visible: true
                    Rectangle {
                        id: rect1
                        color: "#6c0000"
                        width: 20
                        height: 20
                        anchors.verticalCenterOffset: 110
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                Dial {
                    id: dial2
                    stepSize: 1
                    to: 255
                    from: 0
                    value: 5
                    Layout.preferredHeight: 190
                    Layout.preferredWidth: 190
                onValueChanged: seri.change_Color(qsTr("g %1").arg(dial2.value))
                    Rectangle {
                        id: rect2
                        width: 20
                        height: 20
                        color: "#318f02"
                        anchors.verticalCenterOffset: 110
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                Dial {
                    id: dial3
                    stepSize: 1
                    from: 0
                    value: 5
                    to: 255
                    Layout.preferredHeight:190
                    Layout.preferredWidth:190
                onValueChanged: seri.change_Color(qsTr("b %1").arg(dial3.value))
                    Rectangle {
                        id: rect3
                        width: 20
                        height: 20
                        color: "#004ada"
                        anchors.verticalCenterOffset: 110
                        anchors.horizontalCenterOffset: 0
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                    }
                }
            }
        }
        Text {
            id: te
            color: "#ffffff"
            text: qsTr(seri.Author)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
            anchors.fill: parent
            anchors.centerIn: parent
        }
    }
    TabBar
    {
        id:tabB
        onCurrentIndexChanged: swapView.currentIndex = tabB.currentIndex
        TabButton
        {

            text: qsTr("Control")
            antialiasing: true
        }
        TabButton
        {
            text: qsTr("Info")
        }
    }
}
