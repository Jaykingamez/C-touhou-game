#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "dialogue.h"
#include "typetext.h"

static bool dialogueHasTag(DIALOGUE *obj, const char *noun)
{
  return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}

static DIALOGUE *getDialogue(const char *noun)
{
  DIALOGUE *obj, *res = NULL;
  for (obj = dialogues; obj < endOfDialogues; obj++)
  {
    if (dialogueHasTag(obj, noun))
    {
      res = obj;
    }
  }
  return res;
}

DIALOGUE *getDialogueOption(const char *intention, const char *noun)
{
  DIALOGUE *obj = getDialogue(noun);
  if (obj == NULL)
  {
    typeTextf("I don't understand %s.\n", intention);
  }
  return obj;
}
