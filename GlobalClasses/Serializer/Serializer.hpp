/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Serializer
*/

#ifndef BABEL_SERIALIZER_HPP
#define BABEL_SERIALIZER_HPP

#include <boost/asio.hpp>
#include <QByteArray>
#include "header.hpp"

class Serializer {
public:
    static void encodeData(const BinaryData &, boost::asio::streambuf &);
    static QByteArray encodeData(const BinaryData &);
    static QByteArray encodeSound(const Message &);
    static BinaryData decodeData(const QByteArray &);
    static Message decodeSound(const QByteArray &buffer);
    static BinaryData decodeData(const std::string &);
private:
};


#endif //BABEL_SERIALIZER_HPP
