#ifndef __DIALOGUE_H__
#define __DIALOGUE_H__
typedef struct dialogue
{
  const char *action;   // Eg. Ask
  const char *tag;      // E.g. food
  const char *dialogue; // What the player is asking
  const char *response; // Response from girl
  const char *comment;  // Comment from player (hinting who the hell the girl is)
} DIALOGUE;

DIALOGUE dialogues[];

#define food (dialogues + 0)
#define water (dialogues + 1)
#define what (dialogues + 2)
#define who (dialogues + 3)
#define where (dialogues + 4)
#define when (dialogues + 5)
#define how (dialogues + 6)
#define why (dialogues + 7)
#define suika (dialogues + 8)
#define iku (dialogues + 9)
#define tenshi (dialogues + 10)
#define endOfDialogues (dialogues + 11)
#endif
