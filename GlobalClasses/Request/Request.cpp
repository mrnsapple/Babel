/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Request
*/

#include <iostream>
#include "Request.hpp"


BinaryData Request::constructRequest(const Keyword &action, const boost::any &one, const boost::any &two,
                                     const boost::any &three, const boost::any &four, const boost::any &five)
{
    //std::cout<< "action:"<<action<<"\n";
    const std::unordered_map<Keyword , std::function<BinaryData()>> map {
            {Login, [&]() {
                return BinaryData{Login, User{UNDEFINED_ID, any_cast<std::string>(one), any_cast<std::string>(two), "no_email", "Online", any_cast<std::string>(four), UNDEFINED, any_cast<int>(three)}};
            }},
            {FetchFriends, [&]() {
                User user = any_cast<User>(one);
                return BinaryData{FetchFriends, user};
            }},
            {ChangeStatus, [&]() {
                User user = any_cast<User>(one);
                auto newStatus = any_cast<std::string>(two);
                return BinaryData{ChangeStatus, User{user.userId, user.username, user.password, user.fake_email, newStatus}};
            }},
            {Call, [&]() {
                auto callerId = any_cast<int>(one);
                auto contactUsername = any_cast<std::string>(two);
                auto callerPort = any_cast<int>(three);
                return BinaryData{Call, User{callerId, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, UNDEFINED, contactUsername, callerPort}};
            }},
            {AddFriend, [&]() {
                auto user = any_cast<User>(one);
                auto friendName = any_cast<std::string>(two);
                return BinaryData{AddFriend, User{user.userId, user.username, user.password, user.fake_email, user.userStatus, user.ipAddr, friendName}};
            }},
            {LoginResponse, [&]() {
                auto user = any_cast<User>(one);
                auto insetID = any_cast<int>(two);
                return BinaryData{LoginResponse, User{insetID, user.ipAddr}};
            }},
            {FetchFriendsResponse, [&]() {
                auto user = any_cast<User>(one);
                auto friends = any_cast<std::vector<UserFriends>>(two);
                return BinaryData{FetchFriendsResponse, user, friends};
            }},
            {ChangeStatusResponse, [&]() {
                auto user = any_cast<User>(one);
                user.userStatus = any_cast<std::string>(two);
                return BinaryData{ChangeStatusResponse, user};
            }},
            {CallResponse, [&]() {
                auto callingIpAddr = any_cast<std::string>(one);
                auto callingPort = any_cast<int>(two);
                auto calledIpAddr = any_cast<std::string>(three);
                auto calledPort = any_cast<int>(four);
                User user;
                user.userId = callingPort;
                user.addInfoInt = calledPort;
                user.addInfo = callingIpAddr;
                user.addInfoTwo = calledIpAddr;
                return BinaryData{CallResponse, user};
            }},
            {AddFriendResponse, [&]() {
                return BinaryData{AddFriendResponse, any_cast<User>(one)};
            }},
            {WrongUsername, [&]() {
                auto what = any_cast<char const *>(one);
                auto context = any_cast<std::string>(two);
                auto info = User{};
                info.addInfo = context;
                info.userStatus = what;
                return BinaryData{WrongUsername, info};
            }},
            {FriendAddResponse, [&]() {
                return BinaryData{FriendAddResponse, User{any_cast<int>(two), any_cast<std::string>(one)}};
            }},
            {AcceptFriend, [&]() {
                auto user = any_cast<User>(one);
                return BinaryData{AcceptFriend, user};
            }},
            {DenyFriend, [&]() {
                auto user = any_cast<User>(one);
                return BinaryData{DenyFriend, user};
            }},

    };
    
    const auto end = map.end();
    auto it = map.find(action);
    if (it != end)
        return it->second();
    else
        throw GeneralException("An impossible exception with enum out of range", __FUNCTION__);
}