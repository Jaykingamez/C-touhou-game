// Compile with -lwinmm
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <playsound.h>

DWORD WINAPI playSoundThread(LPVOID lpParam)
{
    S_SOUND_PARAM* param = (S_SOUND_PARAM*)lpParam;
    // waveOutSetVolume(0, ((0xFFFF) * param->volume) / 100);
    // waveOutSetVolume(1, ((0xFFFF) * param->volume) / 100);
    PlaySound(TEXT(param->filename), NULL , SND_ASYNC);
    return 0;
}
void playMusic(char* filename) {
    // waveOutSetVolume(0, ((0xFFFF) * 20) / 100);
    // waveOutSetVolume(1, ((0xFFFF) * 20) / 100);
    PlaySound(TEXT(filename), NULL , SND_ASYNC);
}
void playStop() {
    PlaySound(NULL, NULL , SND_ASYNC);
}

void playSoundPar(char* filename, int volume) {
    S_SOUND_PARAM *param = malloc(sizeof(S_SOUND_PARAM));
    param->filename = filename;
    param->volume = volume;
    HANDLE thread = CreateThread(NULL, 0, playSoundThread, param, 0, NULL);
    CloseHandle(thread);
}
