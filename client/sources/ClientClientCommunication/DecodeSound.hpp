/*
** EPITECH PROJECT, 2019
** decodeSOund
** File description:
** decodeSound
*/
#include "EncodeSound.hpp"
#include "UDPclient.hpp"

#ifndef decodesound
#define decodesound

class DecodeSound {
	public:
		DecodeSound();
		~DecodeSound();
        EncodeSound::PackedSound decodeTheSound(Message message);

	protected:
	private:
};

#endif /* !decodesound */
