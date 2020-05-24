//An actual Static Class and not a singleton (finally)

#pragma once

extern "C"
{ 
	// #include <SDL2/SDL.h>
    #include <SDL2/SDL_mixer.h>
}

#include <string>


class Audio 
{
    public:

        static void init(int frequency = 44100, int numChannels = 2, int sampleSize = 2048);

        //ToDo: Maybe consider adding Load Music/Sound Functions        
        static void playMusic(std::string path, float volume, int repeat = -1);

        static void playSound(std::string path, float volume, int repeat = 0);

        static void flush();

        //Pause Music
        //Resume Music
        //Fade In Music
        //Fade Out Music

};

//ToDo: Shouldn't be singleton, put into some other system! Look at how Graphics.hpp is done

//The music that will be played
static Mix_Music *gMusic = NULL;

//The sound effects that will be used
static Mix_Chunk gSounds[4];

// Mix_Chunk *gScratch = NULL;
// Mix_Chunk *gHigh = NULL;
// Mix_Chunk *gMedium = NULL;
// Mix_Chunk *gLow = NULL;