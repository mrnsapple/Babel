/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** header
*/

#ifndef BABEL_HEADER_HPP
#define BABEL_HEADER_HPP

/* define name for the database
 * for debug, db will in memory
 * while for release on disk
 */

//#define DATABASE_FILENAME ":memory:"
#define DATABASE_FILENAME "babelDatabase.sqlite"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8080
#define DEFAULT_SERVER_PORT 8080

#define UNDEFINED_ID -1
#define UNDEFINED ""
#define DEFAULT_IP "0.0.0.0"

#include <iostream>
#include <memory>
#include <utility>
#include <typeinfo>
#include <boost/any.hpp>
#include "../Exceptions/Exceptions.hpp"

#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/access.hpp>
#include <cereal/types/base_class.hpp>

enum Keyword{
    /*Client -> Server Codes*/
    Login,
    FetchFriends,
    ChangeStatus,
    Call,
    AddFriend,

    /*Server -> Client response codes: No error*/
    LoginResponse,
    FetchFriendsResponse,
    ChangeStatusResponse,
    CallResponse,
    AddFriendResponse,
    FriendAddResponse,

    AcceptFriend,
    DenyFriend,
    /*Server -> Client response codes in case of an Error*/
    WrongUsername
};

struct Message {
    std::vector<unsigned char> _sound;
    int     _soundSize;
    std::string optionalMessage;

    template <class Archive>
    void serialize( Archive &ar)
    {
        ar(_sound, _soundSize, optionalMessage);
    }

};


/*User struct params {
 * 1) Id (optional, only used by the server to send back to client)
 * 2) Client's username
 * 3) Password
 * 4) Email (not really used)
 * 5) Ip address
 * 6) Variable argument which most likely used to note another user for call and addfriend requests
 * }
 * */

struct User {
    int userId;
    std::string username;
    std::string password;
    std::string fake_email;
    std::string userStatus;
    std::string ipAddr;
    std::string addInfo;
    int addInfoInt;
    int addInfoT;
    std::string addInfoTwo;

    friend class cereal::access;
    template <class Archive>
    void save(Archive &ar) const
    {
        ar(userId, username, password, fake_email, userStatus,
                ipAddr, addInfo, addInfoInt, addInfoT, addInfoTwo);
    }


    template <class Archive>
    void load(Archive &ar)
    {
        ar(userId, username, password, fake_email, userStatus,
           ipAddr, addInfo, addInfoInt, addInfoT, addInfoTwo);
    }
};
CEREAL_SPECIALIZE_FOR_ALL_ARCHIVES(User, cereal::specialization::member_load_save)

/*User friends structure {
 * Friend's username
 * Friend's ip address
 * Friend's current status when the request was executed
 * }*/
struct UserFriends {
    std::string username;
    std::string address;
    std::string userStatus;


    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(username, address, userStatus);
    }
};

CEREAL_SPECIALIZE_FOR_ALL_ARCHIVES(UserFriends, cereal::specialization::member_load_save)

/*Friend list structure for the database {
 * 1) FriendId autoincremented via database
 * 2) User's id who initiated the friend request
 * 3) User's id who was aadded
 * 4) Friend's status (Pending or accepted)
 * }*/
struct FriendList {
    int friendId;
    int from;
    int to;
    std::string friendStatus;
};


/*BinaryData archive for serialization and communication between server and client {
 * 1) Message which is a keyword
 * 2) User data structure, reference above (optional)
 * 3) Vector of friends if the request is friends fetching (optional)
 * }
 * */
struct BinaryData {
    Keyword message;

    User userData;
    std::vector<UserFriends> friends;


    template <class Archive>
    void serialize( Archive &ar)
    {
        ar(message, userData, userData);
    }



};


#endif //BABEL_HEADER_HPP
