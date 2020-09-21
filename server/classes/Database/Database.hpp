/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Database
*/

#ifndef BABEL_DATABASE_HPP
#define BABEL_DATABASE_HPP

#include "header.hpp"

#include <sqlite3.h>
#include <sqlite_orm/sqlite_orm.h>

using namespace sqlite_orm;


class Database {
public:
    Database();
    int getIdByUsername(const std::string &);
    std::string getIpAddr(const std::string &username) const;
    std::string getIpAddr(const int &userId) const;
    int getUdpPort(const std::string &username) const;

    int getUser(const User &);
    std::string changeStatus(const User &);

    std::pair<std::string, int> addFriend(const size_t &from, const std::string &to);
    std::vector<UserFriends> getFriends(const User &);

    void denyFriend(const User &information);
    void acceptFriend(const User &information);
    
private:
    int insertUser(const User &);
    static auto getStorage();
};


#endif //BABEL_DATABASE_HPP
