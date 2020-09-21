/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** TCPclient
*/

#ifndef BABEL_TCPCLIENT_HPP
#define BABEL_TCPCLIENT_HPP

#include <QtCore>
#include <QtNetwork>

#include "../../../GlobalClasses/Serializer/Serializer.hpp"

#include "header.hpp"

class Core;

class Client : public QObject
{
Q_OBJECT
public:
    explicit Client(Core *newCore, const std::string &ipaddr = SERVER_ADDRESS,  QObject *parent = nullptr);

public slots:
    bool connectToHost(const QString &host);
    bool sendData(const QByteArray &bdata);
    const void readData() const;

private:
    QTcpSocket *socket;
    Core *_core;
};

#endif //BABEL_TCPCLIENT_HPP
