// Compile with -lwinmm
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

DWORD WINAPI playSoundThread(LPVOID lpParam)
{
    char* filename = (char*)lpParam;
    PlaySound(filename, NULL , SND_FILENAME);
    return 0;
}

void playSoundPar(char* filename) {
    HANDLE thread = CreateThread(NULL, 0, playSoundThread, filename, 0, NULL);
    CloseHandle(thread);
}
