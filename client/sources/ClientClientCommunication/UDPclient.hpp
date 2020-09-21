/*
** EPITECH PROJECT, 2019
** udpclient
** File description:
** udpclient
*/

#include <QtNetwork/qudpsocket.h>
#include <QtCore>
#include <QtNetwork>
#include "header.hpp"
#include <iostream>
#ifndef UDPclientclass
#define UDPclientclass
//#include "Eventcall.hpp"

class UDPclient : public QObject {
Q_OBJECT
public:


    UDPclient();
    ~UDPclient();
public slots:

    bool connectToHost(const QHostAddress &,int port );
    bool writeData(Message message, const QHostAddress &host, int port);
    Message readData();
    void          closeClient(void);
    void markAsReadable();
    void open() {    _udpSocket->open(QUdpSocket::ReadOnly);}
    bool getThereIsToRead() { return _thereIsToRead; }
    void setThereIsToRead(bool var) { _thereIsToRead = var; }
    int getmessageNo() { return _messageNo; }
    void setcontinueCall(bool var) { _continueCall = var; }
    int getcontinueCall() { return _continueCall; }
public:
    int getPort() { return _port; }
    QUdpSocket *_udpSocket;
private:
    bool _thereIsToRead;
    bool _continueCall;
    int _messageNo;
    QHostAddress _host;
    int _port;
};

#endif /* !UDPclient */