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

    // add death flag if you mention wrong character
    // add some flavour dialogue

    // probably some multi choice ending, like remove blindfold
    // 1. Embrace your new super short yandere girlfrield you lolicon
    // 2. Sock her in the face, because she almost got you killed
    // 3. Become Giorno Giovanni
  }
}