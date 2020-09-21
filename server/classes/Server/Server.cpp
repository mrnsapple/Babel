/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Server
*/

#include "Server.hpp"
#include "../../../GlobalClasses/Serializer/Serializer.hpp"
#include "../../../GlobalClasses/Request/Request.hpp"

Server::Server(boost::asio::io_context &io_context) : _acceptor(io_context, tcp::endpoint(tcp::v4(), DEFAULT_SERVER_PORT))
{
    acceptIncomingConnection();
}

void Server::insertSession(std::weak_ptr<Session> wp)
{
    _connections.push_back(wp);
}

void Server::sendGlobal(const int &whoCalls, const int &whoIsCalled, const std::string &callingIpAddr, const std::string &calledIpAddr,
                        const int &callingPort, const int &calledPort) {
    boost::asio::streambuf yeet;
    Serializer::encodeData(Request::constructRequest(CallResponse, callingIpAddr, callingPort, calledIpAddr, calledPort), yeet);
    overActives([&](Session &session) { session.broadcastWrite(yeet);});
}

void Server::sendFriendRequest(const std::string &whoIsSending, const int &friendId)
{
    boost::asio::streambuf buffer;
    Serializer::encodeData(Request::constructRequest(FriendAddResponse, whoIsSending, friendId), buffer);
    overActives([&](Session &session) {session.broadcastWrite(buffer);}, friendId);
}



template <typename T>
void Server::overActives(T function, const int &id)
{
    std::vector<std::shared_ptr<Session>> activeCon;
    {
        for (auto &session : _connections) {
            if (auto connection = session.lock())
                activeCon.push_back(connection);
        }
    }
    if (id == UNDEFINED_ID) {
        std::for_each(activeCon.begin(), activeCon.end(), [&](const std::shared_ptr<Session> &connection){function(*connection);});
    } else {
        std::for_each(activeCon.begin(), activeCon.end(), [&](const std::shared_ptr<Session> &connection){
            if (connection->sessionId == id)
                function(*connection);
        });

//        for (auto &connection : activeCon) {
//            if (connection->sessionId == id) {
//                function(*connection);
//                break;
//            }
//        }
    }
}

// handle new connection async
void Server::acceptIncomingConnection()
{

    _acceptor.async_accept([this](boost::system::error_code errorCode, tcp::socket socket) {
        if (!errorCode) {
            auto session = std::make_shared<Session>(std::move(socket), this);
            insertSession(session);
            session->start();
        }
        acceptIncomingConnection();
    });
}