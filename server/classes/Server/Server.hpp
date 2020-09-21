/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Server
*/

#ifndef BABEL_SERVER_HPP
#define BABEL_SERVER_HPP


#include <boost/asio.hpp>
#include "../Session/Session.hpp"
#include "header.hpp"


using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context &);
    void sendFriendRequest(const std::string &whoIsSending, const int &friendId);
    void sendGlobal(const int &whoCalls, const int &whoIsCalled, const std::string &ipAddr, const std::string &calledipAddr,
            const int &callerport, const int &callingport);

private:
    template <typename T>
    void overActives(T function, const int &id = UNDEFINED_ID);

    void insertSession(std::weak_ptr<Session> wp);
    void acceptIncomingConnection();
    tcp::acceptor _acceptor;
    std::vector<std::weak_ptr<Session>> _connections;
};


#endif //BABEL_SERVER_HPP
