#ifndef __PLAYSOUND_H__
#define __PLAYSOUND_H__
void playSoundPar(char* filename, int volume);
void playStop(); 
void playMusic(char* filename);
typedef struct {
    char* filename;
    int volume;
} S_SOUND_PARAM;
#endif