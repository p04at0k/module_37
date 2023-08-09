import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window
{
    width: 640
    height: 480
    visible: true

    Rectangle
    {
        id: videoContainer
        color: "black"
        width: parent.width
        height: parent.height * 0.9
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }

    ProgressBar
        {
            id: progressBar
            width: parent.width * 0.99
            height: 15
            anchors.top: videoContainer.bottom
            anchors.horizontalCenter: parent.horizontalCenter

        }

    Column {
        id: controlContainer
        anchors.top: progressBar.bottom
        anchors.bottom: progressBar.top
        anchors.left: parent.left
        anchors.right: parent.right

        Row {
            id: buttonRow
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"▶️"
                font.pointSize: 15
                onClicked: {videoContainer.play()}
            }

            Button
            {
                text:"⏸️"
                font.pointSize: 15
                onClicked: {videoContainer.pause()}
            }

            Button
            {
                text:"⏹"
                font.pointSize: 15
                onClicked: {videoContainer.stop()}
            }

            Button
            {
                text:"⏪️"
                font.pointSize: 15
                onClicked: {videoContainer.seek(videoPlayer.position - 5000)}
            }

            Button
            {
                text:"⏩️"
                font.pointSize: 15
                onClicked: {videoContainer.seek(videoPlayer.position + 5000)}
            }
        }
    }

}


