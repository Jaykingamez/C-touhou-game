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
      printf("You are a proud asexual man/woman. Which is why living in Gensokyo is almost impossible\n");
      printf("Some of the inhabitants don't get it when you say no. They are Youkai, they aren't used to being rejected.\n");
      printf("But you didn't expect things to turn out like this...\n");
      printf("You don't know what the Youkai did to you, but your head hurts. You don't remember your name...\n");
      printf("A blindfold was put over your eyes, your hands were tied behind your back. You're sitting on something, and I can hear footsteps...\n");
      printf("Ah, you're finally awake.\n\n");
      printf("There was one problem, you don't recognize the woman's voice.\n\n");
      printf("I have told you many times, but it seems you wouldn't listen, making me resort to some means. This is all your fault, you understand don't you?\n\n");
      printf("You couldn't shake your head, something kept it in place, and your mouth was gagged.\n");
      printf("Ara ara, I'm so so sorry...\n\n");
      printf("The damn thing was removed from your mouth. You could speak, but what should you say?\n");
      printf("As stomach growled and your throat was parched with thirst, you realized your starving, and that you're thirsty\n");
    }
    else if (strcmp(verb, "ending") == 0)
    {
      printf("☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢!!!\n");
      printf("NO ONE ESCAPES FROM GENSOKYO!!!!!\n");
      printf("But your stand manifested, GOLDEN EXPERIENCE!\n");
      printf("And you killed Yukari, Reimu, Marisa and all the crazy people trying to stop you.\n");
      printf("And then you realized, you are Giorno Giovanni, why the fuck are you doing here?\n");
    }
    else
    {
      printf("I don't know how to '%s'.\n", verb);
    }
  }
  return true;
}