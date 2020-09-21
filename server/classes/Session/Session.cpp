/*
** Babel
** EPITECH PROJECT, 2019
** File description:
** Session
*/

#include "../Server/Server.hpp"
#include "Session.hpp"


Session::Session(tcp::socket socket, Server *server) : _socket(std::move(socket))
{
    BigBrother = server;
    database = std::make_unique<Database>();
}

void Session::start()
{
    readDataFromClient();
}

void Session::treatData(const BinaryData &bData)
{
    auto user = bData.userData;
    const std::unordered_map<Keyword, std::function<void()>> map {
            {Login, [&]() {
                std::cout << _socket.remote_endpoint().address().to_string() << std::endl;
                auto insertId = database->getUser(user);
                sessionId = insertId;
                try {Serializer::encodeData(Request::constructRequest(LoginResponse, user, insertId, user.ipAddr), buffer);}
                catch (Exception &e) {std::cerr << e.what() << std::endl << e.getContext() << std::endl;}
            }},
            {FetchFriends, [&]() {
                auto friends = database->getFriends(user);
                try {Serializer::encodeData(Request::constructRequest(FetchFriendsResponse, user, friends), buffer);}
                catch (Exception &e) {std::cerr << e.what() << std::endl << e.getContext() << std::endl;}

            }},
            {ChangeStatus, [&]() {
                auto newStatus = database->changeStatus(user);
                try {Serializer::encodeData(Request::constructRequest(ChangeStatusResponse, user, newStatus), buffer);}
                catch (Exception &e) {std::cerr << e.what() << std::endl << e.getContext() << std::endl;}

            }},
            {Call, [&]() {
                try {
                    /*get id, ip and port of the person who is called*/
                    auto calledId = database->getIdByUsername(bData.userData.addInfo);
                    auto calledipAddr = database->getIpAddr(bData.userData.addInfo);
                    auto calledport = database->getUdpPort(bData.userData.addInfo);

                    /*get port and ip adress of the person who is CALLING*/
                    auto callingipAddr = database->getIpAddr(bData.userData.userId);
                    int callingPort = user.addInfoInt;

                    BigBrother->sendGlobal(user.userId, calledId, callingipAddr, calledipAddr, callingPort, calledport);//user.addInfoInt);
                }
                catch (const DatabaseError &e) {
                    Serializer::encodeData(Request::constructRequest(WrongUsername, e.what(), e.getContext()), buffer);
                }

            }},
            {AddFriend, [&]() {
                try {
                    auto who = database->addFriend(user.userId, user.addInfo);
                    Serializer::encodeData(Request::constructRequest(AddFriendResponse, user), buffer);
                    BigBrother->sendFriendRequest(who.first, who.second);
                } catch (const DatabaseError &error) {
                    Serializer::encodeData(Request::constructRequest(WrongUsername, error.what(), error.getContext()), buffer);
                }
            }},
            {AcceptFriend, [&]() {
                try {
                    database->acceptFriend(user);
                } catch (const DatabaseError &e) {std::cerr << e.what() << std::endl << e.getContext() << std::endl;}
            }},
            {DenyFriend, [&]() {
                    try {
                        database->denyFriend(user);
                    } catch (const DatabaseError &e) {std::cerr << e.what() << std::endl << e.getContext() << std::endl;}
                }}
    };

    auto it = map.find(bData.message);
    if (it != map.end())
        it->second();
    else
        throw GeneralException("An impossible exception with enum out of range", __FUNCTION__);
    writeDataToClient();

}


void Session::readDataFromClient()
{
    auto self(shared_from_this());
    _socket.async_read_some(boost::asio::buffer(data, 8048),
            [this, self](boost::system::error_code errorCode, std::size_t length) {
        if (!errorCode) {
            treatData(Serializer::decodeData(std::string(data, 8048)));
        }
    });
}

void Session::broadcastWrite(boost::asio::streambuf &str)
{
    auto self(shared_from_this());
    boost::asio::async_write(_socket, str,
            [this, self](boost::system::error_code ec, std::size_t ) {
        if (!ec) {
            readDataFromClient();
        }
    });
}

void Session::writeDataToClient()
{
    auto self(shared_from_this());
    boost::asio::async_write(_socket, buffer,
            [this, self](boost::system::error_code ec, std::size_t ) {
        if (!ec) {
            readDataFromClient();
        }
    });
}