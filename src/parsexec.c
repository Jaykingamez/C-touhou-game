#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "action.h"
#include "thirst.h"
#include "hunger.h"
#include "typetext.h"
#include "playSound.h"

bool action();

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
      bool result = executeAsk(noun);
      // you die lol
      if (!result)
      {
        return result;
      }
      return action();
    }
    else if (strcmp(verb, "intro") == 0)
    {
      typeText("Intro");
      playMusic("sound/horror.wav");
      typeText("You are a proud asexual man/woman. Which is why living in Gensokyo is almost impossible");
      typeText("Some of the inhabitants don't get it when you say no. They are Youkai, they aren't used to being rejected.");
      typeText("But you didn't expect things to turn out like this...");
      typeText("You don't know what the Youkai did to you, but your head hurts. You don't remember your name...");
      typeText("Something is covering your eyes. Even if you forced them open, an endless void of darkness greeted you.\nYour hands were tied behind your back, the restraints are biting into your skin.");
      playStop();
      playSoundPar("sound/step3.wav", 100);
      typeText("You're sitting on something and based off your posture, you guess it's a chair. You hear footsteps...");
      playSoundPar("sound/hey.wav", 100);
      typeText("Mysterious girl: \"Ah, you're finally awake.\"");
      typeText("There was one problem, you don't recognize the woman's voice.");
      typeText("Mysterious girl: \"I have told you many times, but it seems you wouldn't listen, making me resort to this. This is all your fault, you understand don't you?\"");
      typeText("You struggled to shake your head. You couldn't shake your head, something kept it in place, and your mouth was gagged.\n");
      playSoundPar("sound/gasp.wav", 100);
      typeText("Mysterious girl: \"Ara ara, I'm so so sorry...\"");
      typeText("The damn thing was removed from your mouth. You could speak, but what should you say?");
      typeText("As your stomach growled and your throat was parched with thirst, you realized your starving, and that you're thirsty");
      typeText("You didn't feel like chit chatting. Sating your current needs was the goal.");
      typeText("You only had the energy to utter a single word at a time. As your mouth hung open, before closing");
      typeText("Memories from your time at Ms Keine, flooded your mind, when asking questions one should use 5W1H. You don't know why they appeared, but they seemed useful.");
      typeText("And considering that you're blindfolded, you guess that whoever they are, really wants you to guess their identity.");
      typeText("So what to ask?");
      typeText("food or water?");
      typeText("Your mind were only swarmed with thoughts on them.");
      printf("\n");
    }
    else
    {
      printf("I don't know how to '%s'.\n", verb);
      return action();
    }
  }
  return true;
}

// Return false, die.
bool action()
{
  increaseHunger();
  increaseThirst();
  if (checkHungerDead() || checkThirstDead())
  {
    if (checkHungerDead())
    {
      typeText("Do you know what happens to during starvation? Your cells cannibalize themselves. So your body eats itself. You have been eaten, none other by yourself. Blame your horrible caretaker. Or is it your fault for not knowing to speak up?");
      typeText("Game Over");
      typeText("Press any key and enter to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
    else if (checkThirstDead())
    {
      typeText("Do you know what happens when you die from thirst? Your kidney fails. And when your kidney fails, good things don't happen. Blame your horrible caretaker. Or is it your fault for not knowing to speak up?");
      typeText("Game Over");
      typeText("Press any key and enter to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
  }
  printHunger();
  printThirst();
  return true;
}