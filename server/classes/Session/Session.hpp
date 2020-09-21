/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Session
*/

#ifndef BABEL_SESSION_HPP
#define BABEL_SESSION_HPP

#include <utility>
#include <boost/asio.hpp>
#include <unordered_map>
#include <functional>
#include "header.hpp"
#include "../../../GlobalClasses/Serializer/Serializer.hpp"
#include "../../../GlobalClasses/Request/Request.hpp"


#include "../Database/Database.hpp"

using boost::asio::ip::tcp;
class Server;

class Session : public std::enable_shared_from_this<Session> {
    friend Server;
public:
    void writeDataToClient();
    void broadcastWrite(boost::asio::streambuf &str);
    Session(tcp::socket socket, Server *server);
    void start();

private:
    void readDataFromClient();
    void treatData(const BinaryData &);
    tcp::socket _socket;
    char data[8048];
    std::unique_ptr<Database> database;
    Server *BigBrother;
    boost::asio::streambuf buffer;
    int sessionId;
};


#endif //BABEL_SESSION_HPP
