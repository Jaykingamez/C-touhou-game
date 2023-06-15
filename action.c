#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dialogue.h"
#include "noun.h"
#include "thirst.h"
#include "hunger.h"

// edit this later
bool executeAsk(const char *noun)
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
    if (strcmp(obj->tag, "suika") == 0)
    {
      // Waterboarding bruh
      printf("\n\nA towl was thrown against your face. As you felt a kick, you slumped against the ground. Struggling with all your might against the towel, you struggled.");
      printf("\n\nMysterious girl: Since you think I'm some sort of alcoholic, I am very happy to oblige your fantasy.");
      printf("\n\nA liquid was poured against the towel, pressing against your nostrils.");
      printf("\n\nYou struggle as it pressed against your nostrils, slowly suffocating you. You fee like gagging, but something is pressing the towel against your face.");
      printf("\n\nMysterious girl: It seems I need to get the message into thick skull. I AM NOT SUIKA. I am fine with wasting perfectly good liquor for this.");
      printf("\n\nYou don't know how long it lasted. But eventually, you became like any other meat on the dinner table, unbreathing.");
      printf("\n\nPress any key to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
    else if (strcmp(obj->tag, "iku") == 0)
    {
      // Death by electric chair
      printf("\n\nMysterious girl: You think I'm IKU? Huhhahahahaahah.");
      printf("\n\nThe girl scampered off, leaving you by your lonesome with your thoughts.");
      printf("\n\nYou felt an object being placed against your head, and you could feel your restraints getting tighter.");
      printf("\n\nMysterious girl: Let me give you a taste of Iku.");
      printf("\n\nYour muscles shake as thousands of volts enter your body, your muscles dance, and dance as you scream. A chorus of laughter bursted out from the girl as she watched you suffer.");
      printf("\n\nMysterious girl: Do you think I'm Iku now?");
      printf("\n\nAs you hear footsteps approach you, the pain stopped, and the pain was never felt again.");
      printf("\n\nPress any key to exit, all the best for your next try, you damned soul.");
      getchar();
      return false;
    }
    else if (strcmp(obj->tag, "tenshi") == 0)
    {
      // true ending
      printf("\n\nThe damn thing blocking your eyes was removed and before your sight was like a goddess after your harrowing experience");
      printf("n\nBut then it set in that the cute girl before you was the one who kidnapped you and almost got you killed. Scanning her from head to toe, there was one thing you are sure of, you are not into her.");
      printf("\n\nShe stepped closer to you, and if this was a movie, you feel that there should be some romantic tension, but there wasn't because the girl was a monster.");
      printf("\n\nThe girl snapped her fingers, and a red laser from somewhere cut your restraints like butter. It was as if she was demonstrating her abilities.");
      printf("It's your turn, maestro. Pick the ending you woud like. Just type the number.");

      printf("\n\n1) She's hella cute, even tho I'm not into her, we could be friends you know. Perhaps she's misunderstood.");
      printf("\n\n2) Your fists are roaring to destroy the monster disguised as a girl ");
      printf("\n\n3) This reality is dumb. I can become anything. So I will destroy this reality.");
      printf("\n\n");
      char input = getchar();
      // printf("%d", input);
      // printf("%c", input);
      // getchar();
      // Tenshi enjoyer ending
      if (input == '1')
      {
        printf("\n\nTenshi: Abandon your pride and serve me peasant");
        printf("\n\nOn Second thought, you wonder if you made the right choice");
        printf("\n\nBut as a proud asexual man/woman, you are a mere human. You won't be able to fight her.");
        printf("\n\nGetting up from your seat, you embraced her");
        printf("\n\nAnd she embraced you.");
        printf("\n\nPress any key to exit, why this ending lol. Cringe romance ending.");
        getchar();
        return false;
      }
      // Tenshi killer ending
      else if (input == '2')
      {
        printf("\n\nYou felt roaring BGM as a metal solo began tearing through the skies. You firmed your expressions, but the blue hair loli only got confused.");
        printf("\n\nPulling back your arms, you struck her right in the cheek, sending her flying onto the ground.");
        printf("\n\nAs the girl struggled to get up, you ran towards her, and leapt, dropping an elbow drop on her abdomen.");
        printf("\n\nPining her to the ground, you launched blow after blow against her face.");
        printf("\n\nYou felt pretty good.");
        printf("\n\nThen you realized you might be hitting a man-eating machine...");
        printf("\n\nYou were knocked back by a giant rock, slamming you into the wall. As your lone eye stared at the girl, she whipped out her sword, and ended your miserable life.");
        printf("\n\nPress any key to exit, I would do this ending too.");
        getchar();
        return false;
      }
      // Tenshi joke ending
      else
      {
        printf("\n\n☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢☢!!!");
        printf("\n\nRandom loud voice from the heavens: NO ONE ESCAPES FROM GENSOKYO!!!!!");
        printf("\n\nBut your stand manifested, GOLDEN EXPERIENCE!");
        printf("\n\nAnd you killed Yukari, Reimu, Marisa and all the crazy people trying to stop you.");
        printf("\n\nAnd then you realized, you are Giorno Giovanni, why the fuck are you doing here?");
        printf("\n\nPress any key to exit, To be continued.......");
        getchar();
        return false;
      }
    }
  }
}