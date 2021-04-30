import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml.Models 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


Window {
    width: 400
    height: 150
    visible: true
    title: qsTr("Broadcast Sender")

    ColumnLayout {
        anchors.fill: parent
        TextArea {
            id: textarea
            Layout.fillWidth: true
            placeholderText: "Digite a mensagem a ser enviada para o receiver"
            background: Rectangle { color: "black"; opacity: 0.1; radius: 2 }
            wrapMode: "WrapAtWordBoundaryOrAnywhere"
        }

        Button {
            Layout.alignment: Qt.AlignCenter
            text: "Enviar"
            onPressed: {
                sender.broadcastDatagram(textarea.text)
            }
        }
        RowLayout {
            Layout.alignment: Qt.AlignCenter
            Text {
                id: textContent
                text: `Enviadas ${sender.messageNo} solicitações`
            }
        }
    }


}
