/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Voice
*/

#include "Voice.hpp"
#include "../../../GlobalClasses/Exceptions/Exceptions.hpp"

void Voice::init(std::shared_ptr <UDPclient> udpclient)
{

    _UDPclient = udpclient;
    err = Pa_Initialize();
    if (err != paNoError)
        throw VoiceException(Pa_GetErrorText(err), __FUNCTION__);
    numBytes = FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE;

    initParameters();
    sampleBlock.resize(numBytes);
    buffer.resize(numBytes);
    err = Pa_OpenStream(&stream, &inputParams, &outputParams, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, NULL, NULL);
    if (err != paNoError)
        throw VoiceException(Pa_GetErrorText(err), __FUNCTION__);
}

void Voice::opusInit()
{
    encoder = opus_encoder_create(SAMPLE_RATE, NUM_CHANNELS, OPUS_APPLICATION_VOIP, &error);
    if (error < 0)
        throw VoiceException("failed to create Opus encoder", __FUNCTION__);
    decoder = opus_decoder_create(SAMPLE_RATE, NUM_CHANNELS, &error);
    if (error < 0)
        throw VoiceException("Failed to create Ous decoder", __FUNCTION__);
}

void Voice::start()
{
    err = Pa_StartStream(stream);
    if (err != paNoError)
        throw VoiceException(Pa_GetErrorText(err), __FUNCTION__);

}


void Voice::stop()
{
    err = Pa_StopStream(stream);
    if (err != paNoError)
        throw VoiceException(Pa_GetErrorText(err), __FUNCTION__);
}

void Voice::play(const int &port, const QHostAddress &host)
{
    /*record and encode*/
    err = Pa_WriteStream( stream, sampleBlock.data(), FRAMES_PER_BUFFER);
    if (err != paNoError)
        throw VoiceException(Pa_GetErrorText(err), __FUNCTION__);
    int size = opus_encode_float(encoder, sampleBlock.data(), FRAMES_PER_BUFFER, buffer.data(), SAMPLE_SIZE);
    std::cout << "encoded " << size << std::endl;
    _UDPclient->writeData(Message{buffer, size},  host, port);

    auto received = _UDPclient->readData();

    /*the other side ended the call*/
    if (received.optionalMessage == "End Call")
        _UDPclient->setcontinueCall(false);

//    sampleBlock.assign(sampleBlock.size(), 0);

    /*decode and playback*/
    size = opus_decode_float(decoder, received._sound.data() , received._soundSize, sampleBlock.data(), FRAMES_PER_BUFFER * NUM_CHANNELS, 0);
    std::cout << "DECODE " << size << std::endl;
    err = Pa_ReadStream( stream, sampleBlock.data(), FRAMES_PER_BUFFER );


}

void Voice::initParameters()
{
    inputParams.device = Pa_GetDefaultInputDevice();
    inputParams.channelCount = NUM_CHANNELS;
    inputParams.sampleFormat = PA_SAMPLE_TYPE;
    inputParams.suggestedLatency = Pa_GetDeviceInfo(inputParams.device)->defaultLowInputLatency;

    outputParams.device = Pa_GetDefaultOutputDevice();
    outputParams.channelCount = NUM_CHANNELS;
    outputParams.sampleFormat = PA_SAMPLE_TYPE;
    outputParams.suggestedLatency = Pa_GetDeviceInfo(outputParams.device)->defaultLowOutputLatency;

}

Voice::~Voice()
{
    Pa_CloseStream(stream);
    Pa_Terminate();
    opus_encoder_destroy(encoder);
    opus_decoder_destroy(decoder);
}