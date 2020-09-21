/*
** EPITECH PROJECT, 2019
** encode sound
** File description:
** encodesound
*/

#include "UDPclient.hpp"

#ifndef Encodesound
#define Encodesound

class EncodeSound {
public:
    struct PackedSound {
        //int    _magic_code;
        //int64_t    _timestamp;
        int    _soundSize;
        char     _sound[500];
        bool  _wantsContinueCall;
    };
    EncodeSound();
    ~EncodeSound();
    static Message getMessage(std::string sound, int soundSize, bool wantsContinueCall);
protected:
private:
};

#endif /* !EncodeSound */