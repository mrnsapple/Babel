/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** TCPclient
*/

#include <QDebug>
#include <QHostAddress>
#include <iostream>
#include <sstream>
#include <functional>
#include <unordered_map>
#include "TCPclient.hpp"
#include "../Core/Core.hpp"

Client::Client(Core *newCore, const std::string &ipaddr, QObject *parent) : QObject(parent)
{
    _core = newCore;
    socket = new QTcpSocket(this);
    connectToHost(ipaddr.c_str());
    connect(socket, SIGNAL(readyRead()), SLOT(readData()));
}

bool Client::connectToHost(const QString &host)
{
    socket->connectToHost(host, SERVER_PORT);
    return socket->waitForConnected();
}


/*Serialize and send the BinaryArchive over the socket to the server*/
bool Client::sendData(const QByteArray &bdata)
{
    if(socket->state() == QAbstractSocket::ConnectedState) {
        socket->write(bdata); //write size of data
        return socket->waitForBytesWritten();
    } else
        return false;
}

/*Read BinaryArchive from data and deserialize it*/
const void Client::readData() const
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        QByteArray data = socket->readAll();
        //        deserialize data. Later on we should add a parsing on message.
        try {
            _core->treatRequest(Serializer::decodeData(data));
        } catch(const Exception &e) {
            std::cerr << e.what() << std::endl << e.getContext() << std::endl;
        }
    }
}
