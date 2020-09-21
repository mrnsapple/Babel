/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Serializer
*/

#include "Serializer.hpp"
#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>

void Serializer::encodeData(const BinaryData &binaryData, boost::asio::streambuf &buffer)
{
    std::ostream os(&buffer);
    cereal::BinaryOutputArchive oarchive(os);
    oarchive(binaryData);
}

QByteArray Serializer::encodeData(const BinaryData &binaryData)
{
    boost::asio::streambuf tempStream;
    std::ostream os(&tempStream);

    cereal::BinaryOutputArchive oarchive(os);
    oarchive(binaryData);
    std::string ss((std::istreambuf_iterator<char>(&tempStream)), std::istreambuf_iterator<char>());
    return QByteArray(ss.c_str(), ss.length());
}

QByteArray Serializer::encodeSound(const Message &message)
{
    boost::asio::streambuf tempStream;
    std::ostream os(&tempStream);

    cereal::BinaryOutputArchive oarchive(os);
    oarchive(message);
    std::string ss((std::istreambuf_iterator<char>(&tempStream)), std::istreambuf_iterator<char>());
    return QByteArray(ss.c_str(), ss.length());
}

BinaryData  Serializer::decodeData(const QByteArray &data)
{
    BinaryData binData;
    std::istringstream iss(data.toStdString());
    {
        cereal::BinaryInputArchive iarchive(iss);
        iarchive(binData);
    }
    return binData;
}

Message Serializer::decodeSound(const QByteArray &data)
{
    Message message;
    std::istringstream iss(data.toStdString());
    {
        cereal::BinaryInputArchive iarchive(iss);
        try {iarchive(message);}
        catch (const cereal::Exception &e) {
            message._sound = std::vector<unsigned char>();
            message._soundSize = 0;
        };
    }
    return message;
}

BinaryData Serializer::decodeData(const std::string &data)
{
    BinaryData binData;
    std::istringstream iss(data);
    {
        cereal::BinaryInputArchive iarchive(iss);
        iarchive(binData);
    }
    return binData;
}