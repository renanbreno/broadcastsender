#ifndef SENDER_H
#define SENDER_H

#include <QObject>


QT_BEGIN_NAMESPACE
class QUdpSocket;
QT_END_NAMESPACE

class Sender : public QObject
{
    Q_OBJECT
public:
    Sender();
    Q_PROPERTY(int messageNo READ messageNo NOTIFY messageNoChanged);
    Q_INVOKABLE void broadcastDatagram(QString message);

public slots:
    int messageNo();

signals:
    void messageNoChanged();
private:
    QUdpSocket *udpSocket = nullptr;
    int m_messageNo = 0;
};

#endif // SENDER_H
