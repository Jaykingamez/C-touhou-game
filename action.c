#include <stdio.h>
#include "dialogue.h"
#include "noun.h"

// edit this later
void executeAsk(const char *noun)
{
  DIALOGUE *obj = getDialogueOption("what you want to get", noun);
  if (obj == NULL)
  {
    // already handled by getDialogueOption
  }
  else
  {
    printf("\nYou: %s", obj->dialogue);
    printf("\nMysterious girl: %s", obj->response);
    printf("\nYour thoughts: %s", obj->comment);
    printf("\n");
  }
}