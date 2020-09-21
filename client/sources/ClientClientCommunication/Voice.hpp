/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Voice
*/

#ifndef BABEL_VOICE_HPP
#define BABEL_VOICE_HPP


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

#include "opus.h"

#include "portaudio.h"
#include "../ClientClientCommunication/UDPclient.hpp"

#define SAMPLE_RATE  (48000)
#define FRAMES_PER_BUFFER (480)
#define NUM_CHANNELS    (2)



#define PA_SAMPLE_TYPE  paFloat32
#define SAMPLE_SIZE (4)


class Voice {
public:
    ~Voice();
    void init(std::shared_ptr <UDPclient> udpclient);
    void opusInit();
    void start();
    void stop();
    void play(const int &port, const QHostAddress &host);

private:
    OpusDecoder *decoder;
    OpusEncoder *encoder;
    void initParameters();
    PaStream *stream;
    PaError err;
    int error;
    std::vector<float> sampleBlock;
    std::vector<unsigned char> buffer;
    int numBytes;
    PaStreamParameters inputParams;
    PaStreamParameters outputParams;

    std::shared_ptr<UDPclient> _UDPclient;
};


#endif //BABEL_VOICE_HPP
