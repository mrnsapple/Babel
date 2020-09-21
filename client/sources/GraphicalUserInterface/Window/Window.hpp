//
// Created by nelrum on 18/9/19.
//

#ifndef BABEL_WINDOW_HPP
#define BABEL_WINDOW_HPP

#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QDialogButtonBox>
#include <QComboBox>
#include <iostream>
#include <string>
#include "../LineEdit/LineEdit.hpp"
#include "../Label/Label.hpp"
#include "../PushButton/PushButton.hpp"
#include "../List/List.hpp"
#include "../ComboBox/ComboBox.hpp"
#include "header.hpp"
#include <QtCore>
#include "../../ClientServerCommunication/TCPclient.hpp"
#include "../../ClientClientCommunication/Eventcall.hpp"
#include "../../ClientClientCommunication/UDPclient.hpp"
using std::make_unique;
using std::make_shared;

class Core;

class Window : public QMainWindow {
    Q_OBJECT
public:
    Window(int width, int height, Core *newCore,  QWidget *parent = nullptr);
    void setLogin();
    void setMain();
    void keyPressEvent(QKeyEvent *event) override;
    void fetchFriends(const std::vector<UserFriends> &);
    void createMainResources();
    void createStatusBox();
    void friendadded(const std::string &username);
    void addContact(const std::string &conline);
    void changeStatus(const std::string &status);
    void startCall(const int &callingPort, const std::string &callingIpAddr, const int &calledPort, const std::string &calledIpAddr);
    void initUDPSocket(std::string host) { _eventcall->initUDPSocket(host); }

private slots:
    void checkLogin();
    //void checkPicCall();
    //void checkCloseCall();
    void getSelectedContact();
    void addContactEventCatch();
    void addChangeStatusEventCatch();

private:
    void createLoginResources();
    void closeLoginResources();
    auto createNewContactBox();


    int         _width;
    int         _height;
    LineEdit* _userLine;
    LineEdit* _passLine;
    LineEdit* _addContactLine;
    Label* _userLabel;
    Label* _passLabel;
    Label* _statusIcon;
    PushButton *_confirmButton;
    PushButton* _callButton;
    PushButton* _endButton;
    List* _list;
    std::string _username;
    std::string _selectedContact;
    ComboBox* _statusBox;
    Core *_core;
    Eventcall *_eventcall;

};

#endif //BABEL_WINDOW_HPP
