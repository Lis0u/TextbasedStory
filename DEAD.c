#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "DEAD.h"

#define RED     "\033[31m"      /* Red */
#define WHITE   "\033[37m"      /* White */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */

void DEATH1()
{
  system("clear");

  printf("An evil creature stands before you and rips you apart.\n");
  printf(" You're " RED "DEAD" WHITE".\n\n");
}

void DEATH2()
{
  system("clear");

  printf("The door opens and something steps inside.\n"); 
  printf("You just have the time to see the creature before ");
  printf("it rips you apart.\n");
  printf("You're" RED "DEAD" WHITE ".\n\n");
}

void DEATH3()
{
  system("clear");

  printf("Your stealth skills are too low.\n");
  printf("The creature turns, stands before you, and rips you apart.\n");
  printf(" You're" RED " DEAD" WHITE".\n\n");
}

void DEATH4()
{
  system("clear");

  printf("You really thought it would save you?\n");
  printf("The creature notices your presence, comes to you whatever the ");
  printf("obstacle and rips you apart.\n You're" RED " DEAD" WHITE ".\n\n");
}

void DEATH5()
{
  system("clear");

  printf("You suddenly feel sick. You throw up and pass away.\n");
  printf(" You're" RED " DEAD" WHITE".\n\n");
}

void DEATH6()
{
  system("clear");

  printf("You're not strong enough. What were you thinking?\n");
  printf("An evil creature stands before you and rips you apart.\n");
  printf(" You're " RED "DEAD" WHITE".\n\n");
}

void DEATH7()
{
  system("clear");

  printf("Huhuh. You're " RED "DEAD" WHITE".\n\n");
}

void DEATH8()
{
  system("clear");

  printf("The creature spotted your perfume.\n");
  printf("An evil creature stands before you and rips you apart.\n");
  printf(" You're " RED "DEAD" WHITE".\n\n");
}

void DEATH9()
{
  system("clear");

  printf("To not move makes you sleepy...\n");
  printf("Before you realize it, you fall on the ground and make a noise.\n");
  printf("An evil creature stands before you and rips you apart.\n");
  printf(" You're " RED "DEAD" WHITE".\n\n");
}
