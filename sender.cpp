#include "sender.h"
#include <QtNetwork>
#include <QtCore>

Sender::Sender()
{
    udpSocket = new QUdpSocket();
}

void Sender::broadcastDatagram(QString message)
{
    QByteArray datagram = message.toLatin1();
    udpSocket->writeDatagram(datagram, QHostAddress::Broadcast, 45454);
    ++m_messageNo;

    emit messageNoChanged();
}

int Sender::messageNo()
{
    return m_messageNo;
}
