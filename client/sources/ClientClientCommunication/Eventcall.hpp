/*
** EPITECH PROJECT, 2019
** eventcall
** File description:
** eventcall
*/


#include <QDebug>
#include <QWidget>
#include <QTimer>

#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include "../GraphicalUserInterface/List/List.hpp"
#include "../GraphicalUserInterface/Label/Label.hpp"
#include "../ClientClientCommunication/UDPclient.hpp"

#include "Voice.hpp"
#include "EncodeSound.hpp"
#include "DecodeSound.hpp"
#ifndef eventcall
#define eventcall
class Core;

class Eventcall :public QMainWindow{
    Q_OBJECT
	public:
		Eventcall(List *list, Label* statusIcon, Core *core);
        std::shared_ptr<UDPclient> _UDPclient;
        void initUDPSocket(std::string host);
    public slots:

        bool checkPicCall();
        bool startCallLoop();
        void checkCloseCall();
        bool receiveCall();
        void setSelectedContact(std::string &);
        void qTimerInit();
        bool startCall(const int &callingPort, const std::string &callingIpAddr, const int &calledPort, const std::string &calledIpAddr);
        void    setStatusIcon(Label *statusIcon);

        void readData();
        void writeData();


	protected:
	private:
        EncodeSound _encodedSound;
        DecodeSound _decodeSound;

        std::unique_ptr<Voice> voiceManager;
        List *_list;
        Label *_statusIcon;
        std::string _selectedContact;
        Core *_core;
    QTimer *timer;
        int _portClientToCommunicate;
        QHostAddress _hostClientToCommunicate;


};

#endif /* !eventcall */
