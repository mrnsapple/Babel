//
// Created by nelrum on 18/9/19.
//

#include "Eventcall.hpp"
#include "../Core/Core.hpp"

Eventcall::Eventcall(List *list,Label *statusIcon, Core *core): _list(list), _statusIcon(statusIcon), _core(core)
{
    voiceManager = make_unique<Voice>();
    _UDPclient = make_shared<UDPclient>();
    srand (time(NULL));
    int randNum = rand()%(6000-4000 + 1) + 4000;
    for (
            randNum = rand()%(6000-4000 + 1) + 4000;
            !_UDPclient->connectToHost(QHostAddress(SERVER_ADDRESS), randNum);
            randNum = rand()%(6000-4000 + 1) + 4000);

}

void Eventcall::initUDPSocket(std::string host)
{ 
    _UDPclient->closeClient();
    _hostClientToCommunicate = QHostAddress(QString(host.c_str()));
    if (!_UDPclient->connectToHost(QHostAddress(QString(host.c_str())), _UDPclient->getPort()))
        std::cout << "second connection failed\n";
    QObject::connect(_UDPclient->_udpSocket, SIGNAL(readyRead()), this, SLOT(receiveCall()));
}

bool Eventcall::receiveCall()
{
    std::cout <<"[IN receivecall]\n";
    Message _receiveMessage;
    if (_UDPclient->getmessageNo() != 0)
        return false;
    qTimerInit();
    return true;
}

void    Eventcall::setStatusIcon(Label *statusIcon)
{
    _statusIcon = statusIcon;
}

//1) this is 1 function called  when call starts
bool Eventcall::checkPicCall()
{
    if (_selectedContact.empty()) {
        QMessageBox::warning(this, "Warning", " Select someone first to start a call");
        return false;
    }
    std::cout << "Calling " + _selectedContact << std::endl;
    QString newStatus = QString::fromStdString(":/InCall.png");
    _statusIcon->setPixmap(QIcon(newStatus).pixmap(25, 25));
    _core->callContact(_selectedContact,_UDPclient->getPort());
    return true;
}

bool Eventcall::startCall(const int &callingPort, const std::string &callingIpAddr, const int &calledPort, const std::string &calledIpAddr)
{
    if (callingPort == _UDPclient->getPort()) {
        _portClientToCommunicate = calledPort;
        _hostClientToCommunicate = QHostAddress(calledIpAddr.c_str());
    } else {
        _portClientToCommunicate = callingPort;
        _hostClientToCommunicate = QHostAddress(callingIpAddr.c_str());

    }
    _UDPclient->connectToHost(_hostClientToCommunicate, _portClientToCommunicate);
    qTimerInit();
    return true;
}

void Eventcall::qTimerInit()
{
    timer = new QTimer();
     try {
         voiceManager->init(_UDPclient);
         voiceManager->opusInit();
         voiceManager->start();
     } catch (const Exception &e) {
         std::cout << e.what() << std::endl << e.getContext() << std::endl;
     }

    QObject::connect(timer, &QTimer::timeout, this, &Eventcall::startCallLoop);
    timer->start(1);
}

bool Eventcall::startCallLoop()
{
    if(!_UDPclient->getcontinueCall())
        return false;
    try {voiceManager->play(_portClientToCommunicate, _hostClientToCommunicate);}
    catch (const Exception &e) { std::cout << e.what() << std::endl << e.getContext() << std::endl;}
    return true;
}

void Eventcall::readData()
{
    Message _receiveMessage;
    EncodeSound::PackedSound _receivePackedSound;

    _receiveMessage = _UDPclient->readData();
    _receivePackedSound = _decodeSound.decodeTheSound(_receiveMessage);
    if (_receivePackedSound._wantsContinueCall == false) {
        std::cout <<"[Other client said stop call]\n";
        _UDPclient->setcontinueCall(false);
    }
}

void Eventcall::writeData()
{
    Message _sendMessage;
    std::string sound = "sound to send\n";

    _sendMessage = _encodedSound.getMessage(sound, sound.size(), true);
    std::cout << "calling Port:"<< _portClientToCommunicate<<"\n";
    _UDPclient->writeData(_sendMessage, _hostClientToCommunicate, _portClientToCommunicate);

}

void Eventcall::checkCloseCall()
{
    Message _sendMessage;
    _sendMessage._soundSize = 0;
    _sendMessage.optionalMessage = "End Call";
    if (_selectedContact.empty()) {
        std::cout << "Select someone first" << std::endl;
    } else {
        _UDPclient->setcontinueCall(false);
        voiceManager->stop();
        _UDPclient->writeData(_sendMessage, _hostClientToCommunicate, _portClientToCommunicate);
        QObject::disconnect(timer, &QTimer::timeout, this, &Eventcall::startCallLoop);
        std::cout << "You ended the call with " + _selectedContact << std::endl;
        QString newStatus = QString::fromStdString("../client/assets/Online.png");
    }
}

void Eventcall::setSelectedContact(std::string &selectedContact)
{
    _selectedContact = selectedContact;
}