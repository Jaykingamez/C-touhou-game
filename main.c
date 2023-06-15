#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h"

static char input[100] = "intro";

static bool getInput(void)
{
  printf("\n\n--> ");
  return fgets(input, sizeof input, stdin) != NULL;
}

int main()
{
  while (parseAndExecute(input) && getInput())
    ;
  parseAndExecute("ending");
  return 0;
}