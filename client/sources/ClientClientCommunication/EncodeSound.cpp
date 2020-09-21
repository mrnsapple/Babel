#include "EncodeSound.hpp"

EncodeSound::EncodeSound()
{

}

EncodeSound::~EncodeSound()
{

}

Message EncodeSound::getMessage(std::string sound, int soundSize,bool wantsContinueCall)
{
    EncodeSound::PackedSound packedSound;
    Message message;

    packedSound._soundSize = soundSize;
    packedSound._wantsContinueCall = wantsContinueCall;
    std::memset(packedSound._sound, 0, sizeof(packedSound._sound));
    memcpy(packedSound._sound, sound.c_str(), sound.size());

    message._soundSize = sizeof(packedSound);
    //std::cout << packedSound._sound; 
    message._sound.assign(reinterpret_cast<char *>(&packedSound), reinterpret_cast<char *>(&packedSound + 1));
    return message;
} 