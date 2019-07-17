//
// Created by zhufk on 2019/7/16.
//
#include "org_fmod_example_EffectUtis.h"
#include "inc/fmod.hpp"
#include <stdlib.h>
#include <unistd.h>

#define MODE_NORMAL 0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5

#include <android/log.h>

#define LOGI(FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"jason",FORMAT,##__VA_ARGS__);
using namespace FMOD;

JNIEXPORT void JNICALL Java_org_fmod_example_EffectUtis_fix
        (JNIEnv *env, jclass jcls, jstring path_jstr, jint type) {
    System *system;
    Sound *sound;
    Channel *channel;
    DSP *dsp;
    bool playing = true;
    float frequency = 0;

    const char *path_cstr = env->GetStringUTFChars(path_jstr, NULL);
    try {
        System_Create(&system);
        system->init(32, FMOD_INIT_NORMAL, NULL);
        system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);
        switch (type) {
            case MODE_NORMAL:
                LOGI("%s", path_cstr);
                system->playSound(sound, 0, false, &channel);
                LOGI("%s", "fix normal");
                break;
            case MODE_LUOLI:
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_DASHU:
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 0.8);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_JINGSONG:
                system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW, 0.5);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_GAOGUAI:
                system->playSound(sound, 0, false, &channel);
                channel->getFrequency(&frequency);
                frequency = frequency * 1.6;
                channel->setFrequency(frequency);
                break;
            case MODE_KONGLING:
                system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 20);
                system->playSound(sound, 0, false, &channel);
                channel->addDSP(0, dsp);
                break;
            default:
                break;
        }
    } catch (...) {
        goto end;
    }
    system->update();
    while (playing){
        channel->isPlaying(&playing);
        usleep(10000*1000);
        playing= false;
    }
    goto end;
//    usleep(5000 * 1000);
end:
    env->ReleaseStringUTFChars(path_jstr, path_cstr);
    sound->release();
    system->close();
    system->release();
}
