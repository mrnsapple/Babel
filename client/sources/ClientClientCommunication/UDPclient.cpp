/*
** EPITECH PROJECT, 2019
** udpclient
** File description:
** udpclient
*/

#include "UDPclient.hpp"
#include "Eventcall.hpp"
#include "EncodeSound.hpp"
#include "../../../GlobalClasses/Serializer/Serializer.hpp"

UDPclient::UDPclient() : _messageNo(0), _continueCall(true)
{
    _udpSocket = new QUdpSocket(this);
    QObject::connect(_udpSocket, SIGNAL(readyRead()), this, SLOT(markAsReadable()));
}

UDPclient::~UDPclient()
{
    if (_udpSocket)
        delete _udpSocket;
}

bool UDPclient::connectToHost(const QHostAddress &host,int port )
{
    _host = host;
    _port = port;
     _udpSocket->connectToHost(host, port);
    return true;
}

void UDPclient::markAsReadable()
{
    std::cout <<"[Something arrived to UDP socket, messageNo is:" << _messageNo << "\n";
    _thereIsToRead = true;
}

bool UDPclient::writeData(Message message, const QHostAddress &host, int port)
{
    std::cout << message._sound.data();
    _udpSocket->write(Serializer::encodeSound(message));
    _messageNo++;
    return false;
}

Message UDPclient::readData()
{
    Message message;

    auto byteArray = _udpSocket->readAll();
    message = Serializer::decodeSound(byteArray);

    qDebug() << ",message:" << message._sound.data();

    _thereIsToRead = false;
    return message;
}

void  UDPclient::closeClient(void)
{
    _udpSocket->close();
    _messageNo = 0;
}