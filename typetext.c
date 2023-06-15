#include<windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

void typeText(char* text) {
    printf("\n\n");
    for(int i = 0; i < strlen(text); i++) {
        Sleep(30);
        if ( kbhit() ) {
            if ( getch() == '\r' ) {
                // print the rest of the text
                printf("%s", text + i);
                fflush(stdout);
                return;
            }
        }
        putchar(text[i]);
        fflush(stdout);
    }
    Sleep(200);
}