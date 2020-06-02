#include "Audio.hpp"

#define AUDIO_FORMAT MIX_DEFAULT_FORMAT

void Audio::init(int frequency, int numChannels , int sampleSize)
{
    if( Mix_OpenAudio( frequency, AUDIO_FORMAT, numChannels, sampleSize ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}

void Audio::playMusic(std::string path, float volume, int repeat)
{
    //Loads into free buffer
    gMusic = Mix_LoadMUS(path.c_str());
    if( gMusic == NULL )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    //SetVolume
    Mix_VolumeMusic(volume * MIX_MAX_VOLUME);

    //Then play it!
    Mix_PlayMusic(gMusic, repeat);

}

void Audio::playSound(std::string path, float volume, int repeat)
{
    //Loads into free buffer then plays it
}

void Audio::flush()
{
    //Free Music and Audio chunks!
    Mix_FreeMusic(gMusic);
    gMusic = NULL;

    //Mix_FreeChunk(Audio files);
}