/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Database
*/

#include <cstdarg>
#include "Database.hpp"


using std::make_unique;

// private function member to get sql connection as there is no way to put storage as private variable
auto Database::getStorage()
{
    return make_storage(DATABASE_FILENAME,
                        make_table("User",
                                   make_column("userId", &User::userId, autoincrement(), primary_key()),
                                   make_column("username", &User::username),
                                   make_column("password", &User::password),
                                   make_column("email", &User::fake_email),
                                   make_column("addInfoInt", &User::addInfoInt),//this is the udpp port
                                   make_column("userStatus", &User::userStatus),
                                   make_column("ipAddr", &User::ipAddr)),
                        make_table("FriendList",
                                   make_column("friendId", &FriendList::friendId, autoincrement(), primary_key()),
                                   make_column("from", &FriendList::from),
                                   make_column("to", &FriendList::to),
                                   make_column("friendStatus", &FriendList::friendStatus)
                                   ));
}

//sync schema aka creation / synchronization
Database::Database()
{
    auto storage = getStorage();
    storage.sync_schema();
}

//get user from database
int Database::getUser(const User &logUser)
{
    std::cout << "[Login user with udp port:" << logUser.addInfoInt<<" and ip"<< logUser.ipAddr<<"]\n";
    auto storage = getStorage();
    auto user = storage.get_all<User>(where(c(&User::username) == logUser.username and c(&User::password) == logUser.password));
    int insertId;
    if (user.empty()) {
        std::cout << "put user there\n";
        insertId = insertUser(logUser);
    } else {
        user[0].ipAddr = logUser.ipAddr;
        storage.update(user[0]);
        insertId = user[0].userId;
    }
    return insertId;
}

int Database::insertUser(const User &user)
{
    auto storage = getStorage();
    auto insertId = storage.insert(user);
    return insertId;
}

std::pair<std::string, int> Database::addFriend(const size_t  &from, const std::string &friendUsername)
{
    /*get storage*/
    auto storage = getStorage();

    /*get users*/
    auto friendUser = storage.get_all<User>(where(c(&User::username) == friendUsername));

    /*check if there's only one user for friend*/
    if (friendUser.empty()) {
        throw DatabaseError("A person with that username doesn't exist", __FUNCTION__);
    }

    /*insert into UserFriends table*/
    auto insertId = storage.insert(FriendList{-1, (int)from,
            (int)friendUser[0].userId, "Pending Request"});

    return std::make_pair(storage.get<User>(from).username, friendUser[0].userId);
}


std::string Database::changeStatus(const User &user) {
    auto storage = getStorage();

    auto dbUser = storage.get<User>(user.userId);

    dbUser.userStatus = user.userStatus;

    /*Update user with new status and return it*/
    storage.update(dbUser);
    return user.userStatus;
}

std::vector<UserFriends> Database::getFriends(const User &who)
{
    std::vector<UserFriends> friends;
    /*get storage*/
    auto storage = getStorage();

    auto userId = who.userId;

    /*get friends*/
    auto databaseFriends = storage.get_all<FriendList>(where(c(&FriendList::from) == userId or c(&FriendList::to) == userId));
    std::for_each(databaseFriends.begin(), databaseFriends.end(),
            [&] (const auto &dbFriend) {
        auto ffriend = storage.get<User>(dbFriend.from == userId ? dbFriend.to : dbFriend.from);
        friends.push_back(UserFriends{ffriend.username, "", dbFriend.friendStatus});
    });
    return friends;
}

int Database::getIdByUsername(const std::string &username)
{
    auto storage = getStorage();
    auto user = storage.get_all<User>(where(c(&User::username) == username));
    if (user.empty())
        throw DatabaseError("No such user in the database", __FUNCTION__);
    else 
        return user[0].userId;
}

void Database::denyFriend(const User &information)
{
    auto storage = getStorage();
    auto AcceptorFriend = information.userId;
    auto fren = information.username;

    /*SELECT User.userId
     * FROM Users u
     * JOIN Friends f
     * On u.userId = f.from
     * and u.username=fren
     * and f.to = AcceptorFriend
     * */
    auto row = storage.select(columns(&User::userId, &FriendList::friendId),
                              join<FriendList>(on(
                                      c(&User::userId) == &FriendList::from
                                      and c(&User::username) == fren
                                      and c(&FriendList::to) == AcceptorFriend
                              )));
    int frenId = std::get<0>(row[0]);
    int insertionId = std::get<1>(row[0]);
    storage.update(FriendList{insertionId, frenId, AcceptorFriend, "Denied"});
}

void Database::acceptFriend(const User &information)
{
    auto storage = getStorage();
    auto AcceptorFriend = information.userId;
    auto fren = information.username;

    /*SELECT User.userId
     * FROM Users u
     * JOIN Friends f
     * On u.userId = f.from
     * and u.username=fren
     * and f.to = AcceptorFriend
     * */
    auto row = storage.select(columns(&User::userId, &FriendList::friendId),
                              join<FriendList>(on(
                                      c(&User::userId) == &FriendList::from
                                      and c(&User::username) == fren
                                      and c(&FriendList::to) == AcceptorFriend
                              )));
    int frenId = std::get<0>(row[0]);
    int insertionId = std::get<1>(row[0]);
    storage.update(FriendList{insertionId, frenId, AcceptorFriend, "Accepted"});
}

std::string Database::getIpAddr(const std::string &username) const
{
    auto storage = getStorage();
     auto user = storage.get_all<User>(where(c(&User::username) == username));

    return  user[0].ipAddr;
}

std::string Database::getIpAddr(const int &userId) const
{
    auto storage = getStorage();
    auto user = storage.get_all<User>(where(c(&User::userId) == userId));

    return  user[0].ipAddr;
}

int Database::getUdpPort(const std::string &username) const
{
    auto storage = getStorage();
    auto user = storage.get_all<User>(where(c(&User::username) == username));

    return  user[0].addInfoInt;
}