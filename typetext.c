#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

void typeText(char* text) {
    printf("\n\n");
    // Uncomment this for not debug
    // printf("%s", text);
    // Comment out all stuff below for debug
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


void typeTextf(char *format, ...) {
    char buffer [201];
    va_list args;

    va_start(args, format);
    vsnprintf(buffer, 200, format, args);
    va_end(args);
    typeText(buffer);
}