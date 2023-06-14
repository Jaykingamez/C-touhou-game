#include <stdio.h>
#include <stdbool.h>
#include "hunger.h"

#define INCREASE 10
#define FULL 100

// Increase to 100, you die
// Increase 10 after every conversation
int hunger = 80;

// If return false, not dead
// If return true, very dead
void increaseHunger()
{
  hunger += INCREASE;
}

void fillHunger()
{
  hunger = 0;
}

bool checkHungerDead()
{
  if (hunger >= 100)
  {
    return true;
  }
  return false;
}

char *hungerDescription()
{
  if (hunger >= 80)
  {
    return "You might be vegan. But it doesn't matter. If you don't eat anything, you're pretty sure you will die.";
  }
  else if (hunger >= 60)
  {
    return "Your belly growls, wishing for sustenance. But no sustenance will come, until you ask for it";
  }
  else if (hunger >= 40)
  {
    return "Eat bugs. Live in pod. That is your life right now. But no bugs to eat.";
  }
  else if (hunger >= 20)
  {
    return "The delicious food you just ate? Probably in your gut. The thought that you might have consumed human flesh... disturbs you. Youkai girls, am I right lads?";
  }
  else if (hunger >= 0)
  {
    return "What did you just ate? Who cooked this delicious meal? Or the cook can't cook and just ask someone else to do it for them...";
  }
}

void printHunger()
{
  // printf("Hunger: %d", hunger);
  printf(hungerDescription());
}