#include <stdio.h>
#include <stdbool.h>
#include "hunger.h"

#define INCREASE 10
#define FULL 100

// Increase to 100, you die
// Increase 10 after every conversation
int hunger = 20;

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

void printHunger()
{
  printf("\n If hunger reaches %d you die, it increases by %d after every action", FULL, INCREASE);
  printf("\n Hunger: %d", hunger);
}