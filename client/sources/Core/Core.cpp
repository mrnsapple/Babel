/*
** EPITECH PROJECT, 2019
** core
** File description:
** main program class
*/

#include <unordered_map>
#include <functional>
#include "Core.hpp"
#include <sys/types.h>

Core::Core(int ac, char **av) //:  _app(new QApplication(ar, argv))
{
    myId = UNDEFINED_ID;
    if (ac == 1)
        server = std::make_unique<Client>(this);
    else
        server = std::make_unique<Client>(this, av[1]);
    _win =  std::make_unique<Window>(1280, 720, this);
}

void Core::StartWindow()
{
    _win->setLogin();
}

void Core::treatRequest(const BinaryData &bData)
{
    auto user = bData.userData;
    //std::cout << "datamessage:"<<bData.message << std::endl;
    const std::unordered_map<Keyword, std::function<void()>> map{
            {LoginResponse, [&]() {
                myId = user.userId;
                //Create UDP socket with created IP
                _win->initUDPSocket(user.username);
                fetchFriends();}},
            {FetchFriendsResponse, [&]() {
                auto friends = bData.friends;
                transitionToMainWindow(friends);
            }},
            {ChangeStatusResponse, [&]() {
                _win->changeStatus(user.userStatus);
            }},
            {CallResponse, [&]() {
                std::cout << "Calling Port : " << user.userId << std::endl;
                std::cout << "Calling ip adress : " << user.addInfo << std::endl;
                std::cout << "called Port : " << user.addInfoInt << std::endl;
                std::cout << "called  ip adress : " << user.addInfoTwo << std::endl;
//              HANDLE CALLLS
                    _win->startCall(user.userId, user.addInfo, user.addInfoInt, user.addInfoTwo);

            }},
            {AddFriendResponse, [&]() {
                _win->addContact(user.addInfo);
            }},
            {WrongUsername, [&]() {
                std::cerr << "What : " << user.userStatus << std::endl  << "Where : " << user.addInfo << std::endl;
            }},
            {FriendAddResponse, [&]() {
                    _win->friendadded(user.username);
            }}
    };

    const auto end = map.end();
    auto it = map.find(bData.message);
    if (it != end)
        return it->second();
    else
        throw GeneralException("An impossible exception with enum out of range", __FUNCTION__);
}



void Core::logIn(const std::string &username, const std::string &password, int port) const
{
    try {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            std::string ip = getIPAddressWin();
        #else
            std::string ip = getIPAdress();
        #endif
        std::cout << ip << std::endl;
        QByteArray bData = Serializer::encodeData(Request::constructRequest(Login, username, password, port, ip));
        server->sendData(bData);
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl << e.getContext() << std::endl;
    }
}

void Core::fetchFriends()
{
    try {
        QByteArray bData = Serializer::encodeData(Request::constructRequest(FetchFriends, User{myId}));
        server->sendData(bData);
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl << e.getContext() << std::endl;
    }
}

void Core::transitionToMainWindow(const std::vector<UserFriends> &friends)
{
    _win->createMainResources();
    _win->fetchFriends(friends);
    _win->createStatusBox();
    _win->setMain();
}



void Core::addContact(const std::string &friendName)
{
    try {
        QByteArray bData = Serializer::encodeData(Request::constructRequest(AddFriend,
                User{myId}, friendName));
        server->sendData(bData);
    } catch (Exception &e) {
        std::cerr << e.what() << std::endl << e.getContext() << std::endl;
    }
}

void Core::treatFriendResponse(const Keyword &keyword, const std::string &fromusername)
{
    try {
        auto bData = Serializer::encodeData(Request::constructRequest(keyword, User{myId, fromusername}));
        server->sendData(bData);
    } catch (Exception &e) {
        std::cerr << e.what() << std::endl << e.getContext() << std::endl;
    }
}


void Core::changeStatus(const std::string &newStatus) {
    try {
        QByteArray bData = Serializer::encodeData(Request::constructRequest(ChangeStatus, User{myId}, newStatus));
        server->sendData(bData);
    } catch (Exception &e) {
        std::cerr << e.what() << std::endl << e.getContext() << std::endl;
    }
}

void Core::callContact(const std::string &contactUsername, int myPort)
{
    auto bData = Serializer::encodeData(Request::constructRequest(Call, myId, contactUsername, myPort));
    server->sendData(bData);
}
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
std::string Core::getIPAddressWin() const
{
    WSAData wsaData;
    char ac[80];
    if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
        throw GeneralException("Error when getting local host name.", __FUNCTION__);
    }

    struct hostent *phe = gethostbyname(ac);
    if (phe == 0) {
        throw GeneralException("Bad host lookup.", __FUNCTION__);
    }

    for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
        struct in_addr addr;
        memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
        std::string ipaddr = inet_ntoa(addr);
        if (ipaddr != "127.0.0.1") {
            WSACleanup();
            return ipaddr;
        }
    }
    WSACleanup();
    return "";
}

#else
std::string Core::getIPAdress() const
{
    int f;
    struct ifaddrs *addrs;
    getifaddrs(&addrs);
    while (addrs) {
        if (addrs->ifa_addr && addrs->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *pAddr = (struct sockaddr_in *)addrs->ifa_addr;
            if (strcmp(inet_ntoa(pAddr->sin_addr), "127.0.0.1") != 0) {
                return std::string(inet_ntoa(pAddr->sin_addr));
            }
        }
        addrs = addrs->ifa_next;
    }
    return "";
}
#endif