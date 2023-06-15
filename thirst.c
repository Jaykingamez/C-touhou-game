#include <stdio.h>
#include <stdbool.h>
#include "thirst.h"
#include "typetext.h"

#define INCREASE 10
#define FULL 100

// Increase to 100, you die
// Increase by 10 after every conversation
int thirst = 80;

// If return false, not dead
// If return true, very dead
void increaseThirst()
{
  thirst += INCREASE;
}

void fillThirst()
{
  thirst = 0;
}

bool checkThirstDead()
{
  if (thirst >= 100)
  {
    return true;
  }
  return false;
}

char *thirstDescription()
{
  if (thirst >= 80)
  {
    return "You're so thirsty, it is almost as if you might die from thirst.";
  }
  else if (thirst >= 60)
  {
    return "That once lush oasis of a tongue has now begun desertification. Not to worry,  you're pretty fine. You think.";
  }
  else if (thirst >= 40)
  {
    return "Thoughts of a drink reached your mind before vanishing. You have better things to think about than your thirst";
  }
  else if (thirst >= 20)
  {
    return "It was a nice drink. But it was how long ago? You can't remember";
  }
  else
  {
    return "Liquid. WATER. LIQUID DEATH! WAAAGGGHHHH!";
  }
}

void printThirst()
{
  // printf("Thirst: %d", thirst);
  typeText(thirstDescription());
}