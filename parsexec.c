#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "action.h"

bool parseAndExecute(char *input)
{
  char *verb = strtok(input, " \n");
  char *noun = strtok(NULL, " \n");
  if (verb != NULL)
  {
    if (strcmp(verb, "quit") == 0)
    {
      return false;
    }
    else if (strcmp(verb, "ask") == 0)
    {
      executeAsk(noun);
    }
    else if (strcmp(verb, "intro") == 0)
    {
      printf("\n\nIntro");
      printf("\n\nYou are a proud asexual man/woman. Which is why living in Gensokyo is almost impossible");
      printf("\n\nSome of the inhabitants don't get it when you say no. They are Youkai, they aren't used to being rejected.");
      printf("\n\nBut you didn't expect things to turn out like this...");
      printf("\n\nYou don't know what the Youkai did to you, but your head hurts. You don't remember your name...");
      printf("\n\nA blindfold was put over your eyes, your hands were tied behind your back. You're sitting on something, and I can hear footsteps...\n");
      printf("\n\nMysterious girl: \"Ah, you're finally awake.\"");
      printf("\n\nThere was one problem, you don't recognize the woman's voice.");
      printf("\n\nMysterious girl: \"I have told you many times, but it seems you wouldn't listen, making me resort to this. This is all your fault, you understand don't you?\"\n\n");
      printf("\n\nYou struggled to shake your head. You couldn't shake your head, something kept it in place, and your mouth was gagged.\n");
      printf("\n\nMysterious girl: \"Ara ara, I'm so so sorry...\"");
      printf("\n\nThe damn thing was removed from your mouth. You could speak, but what should you say?");
      printf("\n\nAs stomach growled and your throat was parched with thirst, you realized your starving, and that you're thirsty");
      printf("\n\nYou didn't feel like chit chatting. Sating your current needs was the goal.");
      printf("\n\nSyntax Format: Action Topic");
      printf("\n\nExample: ask food");
      printf("\n\nExample: ask water");
      printf("\n\nHint: 5W1H, once you figure who they are, type: ask <character_name>");
      printf("\n");
    }
    else if (strcmp(verb, "ending") == 0)
    {
      printf("\n\n☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢!!!");
      printf("\n\nNO ONE ESCAPES FROM GENSOKYO!!!!!");
      printf("\n\nBut your stand manifested, GOLDEN EXPERIENCE!");
      printf("\n\nAnd you killed Yukari, Reimu, Marisa and all the crazy people trying to stop you.");
      printf("\n\nAnd then you realized, you are Giorno Giovanni, why the fuck are you doing here?");
    }
    else
    {
      printf("I don't know how to '%s'.\n", verb);
    }
  }
  return true;
}