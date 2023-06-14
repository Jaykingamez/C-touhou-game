#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dialogue.h"
#include "noun.h"
#include "thirst.h"
#include "hunger.h"

// edit this later
void executeAsk(const char *noun)
{
  DIALOGUE *obj = getDialogueOption("what you want to ask", noun);
  if (obj == NULL)
  {
    // already handled by getDialogueOption
  }
  else
  {
    printf("\n\nYou: %s", obj->dialogue);
    printf("\n\nMysterious girl: %s", obj->response);
    printf("\n\nYour thoughts: %s", obj->comment);
    printf("\n");

    // check if ask food/water then sated TODO
    // printf("Tag: %s", obj->tag);
    if (strcmp(obj->tag, "food") == 0)
    {
      fillHunger();
    }
    else if (strcmp(obj->tag, "water") == 0)
    {
      fillThirst();
    }
  }
}