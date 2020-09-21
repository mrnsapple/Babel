/*
** EPITECH PROJECT, 2019
** decodesound
** File description:
** decodesound
*/

#include "DecodeSound.hpp"

DecodeSound::DecodeSound()
{
}

DecodeSound::~DecodeSound()
{
}

EncodeSound::PackedSound DecodeSound::decodeTheSound(Message message)
{
    EncodeSound::PackedSound packedSound;

    memcpy(&packedSound, message._sound.data(), message._soundSize);
    qDebug() << message._sound.data();
    qDebug() << "packedsound:\n" <<packedSound._sound << ":\n";
    return packedSound;
}
