#include <stdio.h>

// edit this later
void executeAsk(const char *noun)
{
  moveObject(getPossession(actorHere(), "ask", noun), player);
}