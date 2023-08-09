import QtQuick
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 240
    height: 680
    visible: true
    property int  currentChannel: 0
    property int  currentVolume: 50

    Column
    {
        id: buttons
        height: parent.height * 0.7
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"─"
                font.pointSize: 30
                onClicked:
                {
                    if (currentVolume > 0) currentVolume -=10;
                }
            }

            Button
            {
                text:"✛"
                font.pointSize: 30
                onClicked:
                {
                    if (currentVolume < 100) currentVolume += 10;
                }
            }

            Button
            {
                text:"←"
                font.pointSize: 30
                onClicked:
                {
                    if (currentChannel > 0)  currentChannel -= 1;
                }
            }

            Button
            {
                text:"→"
                font.pointSize: 30
                onClicked:
                {
                    if (currentChannel < 9)  currentChannel += 1;
                }
            }
        }

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"⓿"
                font.pointSize: 30
                onClicked: {currentChannel = 0}
            }

            Button
            {
                text:"❶"
                font.pointSize: 30
                onClicked: {currentChannel = 1}
            }
        }

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"❷"
                font.pointSize: 30
                onClicked: {currentChannel = 2}
            }

            Button
            {
                text:"❸"
                font.pointSize: 30
                onClicked: {currentChannel = 3}
            }
        }

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"❹"
                font.pointSize: 30
                onClicked: {currentChannel = 4}
            }

            Button
            {
                text:"❺"
                font.pointSize: 30
                onClicked: {currentChannel = 5}
            }
        }

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"❻"
                font.pointSize: 30
                onClicked: {currentChannel = 6}
            }

            Button
            {
                text:"❼"
                font.pointSize: 30
                onClicked: {currentChannel = 7}
            }
        }

        Row
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Button
            {
                text:"❽"
                font.pointSize: 30
                onClicked: {currentChannel = 8}
            }

            Button
            {
                text:"❾"
                font.pointSize: 30
                onClicked: {currentChannel = 9}
            }
        }
    }

    Rectangle
    {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: buttons.bottom
        Column
        {
            anchors.horizontalCenter: parent.horizontalCenter

            Text
            {
                id: channel
                text: 'Current channel: ' + currentChannel;
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }

            Text {
                id: volume
                text:'Current volume: ' + currentVolume + '%';
                font.pointSize: 18
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.top: channel.bottom
            }

        }
    }


}

/*
Что нужно сделать

Реализуйте простой симулятор управления телевизором с помощью пульта, представленного в виде графического интерфейса с кнопками.

Интерфейс представляет собой вертикальное окно (в портретной ориентации) размером 240х680 пикселей.
На пульте находятся кнопки переключения каналов от 0 до 9, кнопки перехода к следующему и предыдущему каналу, кнопки увеличения и уменьшения громкости с шагом в 10%.

Снизу пульта находится мини-дисплей с отображением текущего статуса: текущий выбранный канал и текущий уровень громкости в процентах.
Что оценивается

Полнота графического интерфейса и корректность реализации логики программы и всех кнопок.
Как отправить работу на проверку

На проверку отправить архив с файлами исходного кода .cpp, заголовочными файлами .h, конфигурацией проекта CMakeLists.txt,
а также ресурсными файлами(.jpg, .gif, .wav, … ) которые необходимы  для запуска проекта Qt.
*/


