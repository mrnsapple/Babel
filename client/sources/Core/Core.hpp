/*
** EPITECH PROJECT, 2019
** Client
** File description:
** client
*/
//#include <QThread>
#include "../GraphicalUserInterface/Window/Window.hpp"
#include "header.hpp"
#include "../../sources/ClientServerCommunication/TCPclient.hpp"
#include "../../../GlobalClasses/Serializer/Serializer.hpp"
#include "../../../GlobalClasses/Request/Request.hpp"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <winsock2.h>
#include <iphlpapi.h>
#pragma comment(lib, "IPHLPAPI.lib")
#else
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#ifndef CORE_HPP_
#define CORE_HPP_

class Core {
    friend class Client;
    friend class Window;
public:
    Core(int ac, char **av);
    void StartWindow();
    void callContact(const std::string &, int udpClientPort);
private:
    void logIn(const std::string &username, const std::string &password, int port) const;
    void fetchFriends();
    void transitionToMainWindow(const std::vector<UserFriends> &);

    void addContact(const std::string &friendName);

    void changeStatus(const std::string &newStatus);
    void treatFriendResponse(const Keyword &, const std::string &fromusername);
    void statusCallback(const std::string &newStatus);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    std::string getIPAddressWin() const;
#else
    std::string getIPAdress() const;
#endif
    
//    TODO HEAVY WIP

    void treatRequest(const BinaryData &);

//signals:
    //void newFortune(const QString &fortune);
private:
    int myId;
    std::unique_ptr<Window> _win;
    std::unique_ptr<Client> server;
    
};

#endif /* !CLIENT_HPP_ */
