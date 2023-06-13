#include <stdio.h>
#include <stdbool.h>
#include "thirst.h"

#define INCREASE 10
#define FULL 100

// Increase to 100, you die
// Increase by 10 after every conversation
int thirst = 20;

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

void printThirst()
{
  printf("\n If thirst reaches %d you die, it increases by %d after every action", FULL, INCREASE);
  printf("\n Thirst: %d", thirst);
}