#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
//#include <curses.h>
//#include "textbase.h"
#include "DEAD.h"

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define PINK    "\033[35m"      /* Pink */
 #define HEY     "\033[30m"      /* ?  */
 #define WHITE   "\033[37m"      /* White */

 void WakeUp();           //Situation 1
 void HearAtDoor();       //Situation 2
 void HideInCupboard();   //Situation 3
 void HidingUnderBed();   //Situation 4
 void HidingBehindDoor(); //Situation 5
 void LivingRoom();       //Situation 6
 void ExitLocked();       //Situation 8
 void BrokenVase();       //Situation 9
 void KeyHolder();        //Situaiton 10 
 void CreatureKitchen();  //Situation 11
 void EmptyBathroom();    //Situation 12
 void EnterBathroom();    //Situation 13
 void Bathtub();          //Situation 14
 void BedroomRush();      //Situaiton 15
 void BedroomStay(int n); //Situation 16
 void KitchenStay(int n); //Situation 17
 void ShavedandPerfumed(int n); //Situation 18
 void CreatureInBathroom(); //Situation 19
 void EmptyKitchen();     //Situation 20
 void Refregirator();     //Situation 21
 void Cupboard();         //Situation 22
 void SomethingMissing(); //Situation 23
 void Mixture();          //Situation 24
 void StuckCreatureBath(); //Situation 25
 void Kitchen();          //Situation 26
 void TapWaterKitchen();  //Situation 27
 void LookKitchen();      //Situation 28
 void WaterinBathroom();  //Situation 29
 void LookBedroom();      //Situation 30
 void CheckVomit();       //Situation 31
 void Razor();            //Situation 32
 void EndOfGame();        //SUCCESS! End of game

 char *situation;

 /****
 char getch()
 {
 //#include <unistd.h>   //_getch
 //#include <termios.h>  //_getch
     char buf=0;
     struct termios old={0};
     fflush(stdout);
     if(tcgetattr(0, &old)<0)
	 perror("tcsetattr()");
     old.c_lflag&=~ICANON;
     old.c_lflag&=~ECHO;
     old.c_cc[VMIN]=1;
     old.c_cc[VTIME]=0;
     if(tcsetattr(0, TCSANOW, &old)<0)
	 perror("tcsetattr ICANON");
     if(read(0,&buf,1)<0)
	 perror("read()");
     old.c_lflag|=ICANON;
     old.c_lflag|=ECHO;
     if(tcsetattr(0, TCSADRAIN, &old)<0)
	 perror ("tcsetattr ~ICANON");
     printf("%c\n",buf);
     return buf;
  }****/

 int main()
 {
   system("clear");

   WakeUp();

  char str;
   str = getchar();
   printf("Press Enter to Play, Ctrl-C to Exit.\n");

   char stri;
   stri = getchar();
   if(str != '\0') WakeUp();
 }

 //Situation 1
 void WakeUp()
 {
   system("clear");

   printf(GREEN "You slowly wake up, still a bit groggy.\n ");
   printf(WHITE "You realize you're in your bed in the middle of the night.\n");
   printf("Something is strange...\n Before you're able to think, ");
   printf("you hear a cracking door outside of your room.\n");
   printf("What do you do?\n\n");

   printf("(1) You open your door and scream \"Who goes there?\".\n");
   printf("(2) You silently go to your door and try to hear other noises.\n");
   printf("(3) You hide in your cupboard.\n");

   char str;
   str = getchar();
   if(str == '1') DEATH1();
   else if(str == '2') HearAtDoor();
   else HideInCupboard();

 }

 // Situation 2
 void HearAtDoor()
 {
   system("clear");

   printf("At the door, you hear very light steps coming in your direction.");
   printf("\n\n");

   printf("(1) You silently go to your bed, pretending nothing happened.\n");
   printf("(2) You quickly hide under your bed.\n");
   printf("(3) You don't move.\n");
   //Enter key
   char stri;
   stri = getchar();
   //Option Number
   char str;
   str = getchar();
   if(str == '1') DEATH2();
   else if(str == '2') HidingUnderBed();
   else HidingBehindDoor();
 }

 //Situation 3
 void HideInCupboard()
 {
   system("clear");

   printf("5 seconds after your hiding, something enters in your room.\n");
   printf("You can't see it clearly, but you suddenly feel terror by its ");
   printf("presence.\n This creature faces your bed.\n You can see it pulling");
   printf(" over the blanket.\n The creature grunts and leaves the room.\n");
   printf("This creature wants you no good.\n\n");

   printf("(1) You close the door, lock it and hide again under the bed.\n");
   printf("(2) You wait a little and then go to the next room (living room).\n");
   printf("(3) You go out and choke the creature with a coat-hanger.\n");

 //The first character is the number, the second the Enter key.
   char stri;
   stri = getchar();
   char str;
   str = getchar();
   if(str == '1') DEATH4();
   else if(str == '2') LivingRoom();
   else DEATH6();
 }

 //Situation 4
 void HidingUnderBed()
 {
   system("clear");

   printf("A few seconds later, something enters in the room.\n");
   printf("You can only see its bare feet coming and turning around in the roo");
   printf("m.\n The creature faces your bed. You can hear it pulling over the ");
   printf("blanket.\n The creature grunts and leaves the room, leaving the ");
   printf("door opened.\n This creature wants you no good.\n\n");

   printf("(1) You close the door, lock it and hide again under the bed\n");
   printf("(2) You follow the creature, stealthy.\n");
   printf("(3) You wait a little and then go to the next room (living room).\n");

   char stri;
   stri = getchar();
   char str;
   str = getchar();
   if(str == '1') DEATH4();
   else if(str == '2') DEATH3();
   else LivingRoom();
 }

 //Situation 5
 void HidingBehindDoor()
 {
   system("clear");

   printf("The creature steps inside the room.\n");
   printf("However, you are hidden behind the door, so it cannot see you.\n");
   printf("It turns around, pulls over the blanket,"RED" grunts"WHITE);
   printf(" then goes away, leaving the door opened.\n");
   printf("You have now time to think.\n\n");

   printf("(1) You go to the next room (living room).\n");
   printf("(2) You close the door and go back to sleep.\n");
   printf("(3) You stealthily follow the creature.\n");

   char stri;
   stri = getchar();
   char str;
   str = getchar();
   if(str == '1') LivingRoom();
   else if(str == '2') DEATH4();
   else DEATH3();
 }

 //Situation 6
 void LivingRoom()
 {
   system("clear");

   printf("You arrive in the living room, empty.\n");
   printf(PINK"OBJECTIVE"WHITE": Leave the house unharmed.\n");
   printf("The room is connected to three other rooms: your bedroom, ");
   printf("the kitchen and the "BLUE"bathroom"WHITE".\n");
   printf("On the table, in the middle of the room, there is a broken vase, wi");
   printf("th"BLUE" dry"WHITE" flowers and no spilled"BLUE" water" WHITE ".\n");
   printf("The " GREEN "EXIT" WHITE " is at the opposite side of the room.\n\n");


   printf("(1) You go to the" GREEN " EXIT" WHITE " door.\n");
   printf("(2) You want to check the "BLUE"bathroom"WHITE".\n");
   printf("(3) You prefer to go to the kitchen.\n");

   char str;
   str = getchar();
   char stri;
   stri = getchar();
   if(stri == '1') ExitLocked();
   else if(stri == '2') EnterBathroom();
   else DEATH1();
 }

 //Situation 8
 void ExitLocked()
 {
   system("clear");

   printf("The door is " PINK "locked" WHITE ".");
   printf(" You have to find the key to open it.\n\n");

   printf("(1) You go to the kitchen.\n");
   printf("(2) You check the key holder.\n");
   printf("(3) You check the "BLUE"vase"WHITE" on the table.\n");

   char str;
   str = getchar();
   char stri;
   stri = getchar();
   if(stri == '1') DEATH1();
   else if(stri == '2') KeyHolder();
   else BrokenVase();
 }

 //Situation 9
 void BrokenVase()
 {
   system("clear");

   printf("The vase is completely broken, the flowers are completely");
   printf(BLUE " dry"WHITE"\n and there are no spilled " BLUE "water"WHITE".\n");
   printf("You remember them to be very healthy the previous day.\n");
   printf(PINK "DISCOVERY" WHITE ":");
   printf(" The creature has to do something with"BLUE" water"WHITE".\n\n");

   printf("(1) You want to eavesdrop on the"BLUE" bathroom"WHITE".\n");
   printf("(2) You prefer to eavesdrop to the kitchen.\n");
   printf("(3) You check the key holder.\n");

   char str;
   str = getchar();
   char stri;
   stri = getchar();
   if(stri == '1') EmptyBathroom();
   else if(stri == '2') CreatureKitchen();
   else KeyHolder();
 }

 //Situaiton 10 
 void KeyHolder()
 {
   system("clear");

   printf("The key were supposed to be there, but they have purposely");
   printf(" been removed.\n" PINK "DISCOVERY" WHITE ": ");
   printf("The creature has to do something with the key.\n\n");
   printf("(1) You want to eavesdrop on the "BLUE"bathroom"WHITE".\n");
   printf("(2) You want to eavesdrop on the kitchen.\n");
   printf("(3) You check the "BLUE"vase"WHITE" on the table.\n");

   char str;
   str = getchar();
   char stri;
   stri = getchar();
   if(stri == '1') EmptyBathroom();
   else if(stri == '2') KeyHolder();
   else BrokenVase();
 }

 //Situation 11
 void CreatureKitchen(int n)
 {
   n++;
   system("clear");

   printf("You can hear noises through the door.\nThrough the key hole, you ");
   printf("can see a very dark shape, that seems to eat, kind of, something.\n");
   printf(PINK"DISCOVERY"WHITE": the creature must have eaten the key.\n");
   printf("OBJECTIVE: Make the creature"HEY" vomit"WHITE" to get the key back.\n\n");
   printf("(1) You enter the room.\n");
   printf("(2) You want to eavesdrop the "BLUE"bathroom"WHITE".\n");
   printf("(3) You don't move.\n");

   char str;
   str = getchar();
   char stri;
   stri = getchar();
   if(stri == '1') DEATH2();
   else if(stri == '2') EmptyBathroom();
   else if (n < 3 ) CreatureKitchen(n);
   else DEATH3();
 }

 //Situation 12
 void EmptyBathroom()
 {
 system("clear");

 printf("You can't hear anything. You don't see anything through ");
 printf("the keyhole either.\n\n");
 printf("(1) You enter the room.\n");
 printf("(2) You eavesdrop the kitchen.\n");
 printf("(3) You check again.\n");

 char str;
 str = getchar();
 char stri;
 stri = getchar();

 if (stri == '1') EnterBathroom();
  else if(stri == '2') CreatureKitchen(0);
  else EmptyBathroom();
 }

//Situation 13
void EnterBathroom()
{
  system("clear");

  printf("The bathroom is empty. There's a bath tub, the toilet, a ");
  printf("little shelf with medications, perfumes and razors just over ");
  printf("a sink.\n\n");
  printf("(1) You fill the bathtube with "BLUE"water"WHITE".\n");
  printf("(2) You use the razor, perfume, and random medications.\n");
  printf("(3) You go back to the living room.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') Bathtub();
  else if(stri == '2') ShavedandPerfumed(0);
  else LivingRoom();
}   

//Situation 14
void Bathtub()
{
  system("clear");
  printf("The "BLUE"water"WHITE" makes noises.\n\n");

  printf("(1) You don't move.\n");
  printf("(2) You rush to your bedroom and hide.\n");
  printf("(3) You go against the door to block it, just in case.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') DEATH2();
  else if(stri == '2') BedroomRush();
  else DEATH4();
}

//Situation 15
void BedroomRush()
{
  system("clear");

  printf("You're in your bedroom, hearing the flow of de "BLUE"water"WHITE".\n");
  printf("Through the keyhole, you can see the creature moving");
  printf("from the kitchen to the bathroom through the living room.\n\n");

  printf("(1) You don't move.\n");
  printf("(2) You go to the kitchen.\n");
  printf("(3) You eavesdrop on the "BLUE"bathroom"WHITE" door.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') BedroomStay(0);
  else if(stri == '2') EmptyKitchen();
  else CreatureInBathroom();
}

//Situation 16
void BedroomStay(int n)
{
  system("clear");

  n++;
  printf("Nothing changes. The creature do not seem to move.\n\n");

  printf("(1) You eavesdrop on the bathroom's door.\n");
  printf("(2) You go to the kitchen door.\n");
  printf("(3) You don't move.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') CreatureInBathroom();
  else if(stri == '2') EmptyKitchen();
  else if (n < 3 ) BedroomStay(n);
  else DEATH9();
}

//Situation 17
void KitchenStay(int n)
{
  system("clear");

  n++;
  printf("Nothing changes. The creature looks very hungry.\n\n");
  printf("(1) You don't move.\n");
  printf("(2) You want to eavesdrop on the bathroom.\n");
  printf("(3) You enter the room.\n");

char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') KitchenStay(n);
  else if(stri == '2') EmptyBathroom();
  else DEATH1();
} 

//Situation 18
void ShavedandPerfumed(int n)
{
  system("clear");

  //If too perfumed
  if(n>3) DEATH8();

  printf("You are now shaved (Where you needed to be) and you smell good.\n");
  printf("You're healthy, so there's no need to take pills or whatever.\n\n");

  printf("(1) You perfume and shave again.\n");
  printf("(2) You eavesdrop on the kitchen door.\n");
  printf("(3) You open the flow of the "BLUE"water"WHITE" in the bathtub.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') ShavedandPerfumed(n+1);
  else if(stri == '2') CreatureKitchen(0);
  else Bathtub();
}

//Situation 19
void CreatureInBathroom()
{
  system("clear");

  printf("You can see the creature drinking the water of the bathtub");
  printf(" through the keyhole.\n");
  printf("It won't move until there's no water left.\n\n");

  printf("(1) You go to the kitchen.\n");
  printf("(2) You don't move.\n");
  printf("(3) Lalalaliloula! :D\n");

 char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') EmptyKitchen();
 else if(stri == '2') CreatureInBathroom();
 else DEATH1();
}

//Situation 20
void EmptyKitchen()
{
  system("clear");

  printf("In the kitchen, you can see pieces of food everywhere on the");
  printf("floor.\n Funny thing. They're completly dry.\n\n");

  printf("(1) You check the refrigirator if there's anything to eat.\n");
  printf("(2) You check the cupboard fi there's anything left to eat.\n");
  printf("(3) You eavesdrop on the bathroom door.\n");

 char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') Refregirator(0);
 else if(stri == '2') Cupboard(0);
  else CreatureInBathroom();
}

//Situation 21
void Refregirator(int n)
{
  system("clear");

  n++;
  printf("The refregirator is a mess. But you can find a rotten egg, ");
  printf("two pieces of raw meat (that were supposed to be eaten 2 weeks ago)");
  printf(".\n You take them with you.\n Could be useful!\n\n");

  printf("(1) You check the cupboard if there's anything left to eat.\n");
  printf("(2) You start to bake a mixture with your ingredients.\n");
  printf("(3) You eat the ingredients.\n");

 char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') BedroomStay(0);
  else if(stri == '2')
    {
      if(n<2) SomethingMissing(n);
      else Mixture();
    }
  else DEATH5();
}

//Situation 22
void Cupboard(int n)
{
  system("clear");

  n++;

  printf("The cupboard is a mess. But you can find flour, ");
  printf("pieces of glass and a nail.\n You take them with you.\n");
  printf("Could be useful!\n\n");

  printf("(1) You start to bake a mixture with your ingredients.");
  printf("(2) You check the refregirator.\n");
  printf("(3) You eat the ingredients.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') 
    {
      if(n<2) SomethingMissing(n);
      else Mixture();
    }
  else if(stri == '2') Refregirator(n);
  else DEATH5();
}

//Situation 23
void SomethingMissing(int n)
{
  system("clear");

  printf("There's something missing...\n\n");

  printf("(1) You check the refregirator.\n");
  printf("(2) You check the cupboard.\n");
  printf("(3) You eat the ingredients.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') Refregirator(n);
  else if(stri == '2') Cupboard(n);
  else DEATH5();
}

//Situation 24
void Mixture()
{
  system("clear");

  printf("The mixture looks surprinsgly good. But it smells so bad...\n\n");

  printf("(1) You put the mixture on the living room's table and hide in your");
  printf(" bedroom.\n");
  printf("(2) You turn on the tap water.\n");
  printf("(3) You eat the mixture.\n");

  char str;
  str = getchar();
  char stri;
  stri = getchar();
  if(stri == '1') Refregirator(0);
  else if(stri == '2') Cupboard(0);
  else DEATH5();
}

//Situation 25
void StuckCreatureBath()
{
  system("clear");

  printf("");
  printf("");
  printf("");
  printf("");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') Refregirator(0);
 else if(stri == '2') Cupboard(0);
  else CreatureInBathroom();
}

//Situation 26
void Kitchen()
{
  system("clear");

  printf("In the kitchen, you can see the refregirator, ");
  printf("a cupboard, and an évier.\n\n");
  printf("(1) You turn on the water from the kitchen, and hide in your bedro");
  printf("om.\n(2) You eat what the creature left on the ground, you're so ");
  printf("hungry!\n(3) You come back to your bedroom.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') TapWaterKitchen();
 else if(stri == '2') DEATH5();
 else StuckCreatureBath();
}

//Situation 27
void TapWaterKitchen()
{
  system("clear");

  printf("It worked! The creature is coming out of the bathroom.\n");
  printf("It sees the plate on the table. It gets close to it, smells it,");
  printf(" unleash a grunt then go to the kitchen, attracted by the noise.\n");
  printf("Maybe the mixture smelled too bad?\n\n");
  printf("(1) You eavesdrop on the kitchen door.\n");
  printf("(2) You go to the bathroom.\n");
  printf("(3) You don't move.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') LookKitchen();
 else if(stri == '2') Cupboard(0);
  else CreatureInBathroom();
}

// Situation 28
void LookKitchen()
{
  system("clear");

  printf("You can see the monster going around, surely looking for you.\n\n");
  printf("(1) You go to the bathroom.\n");
  printf("(2) You go back in your bedroom.\n");
  printf("(3) You enter and scream \"Here I am bitch!\"\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') WaterinBathroom();
 else if(stri == '2') DEATH1();
 else DEATH1();
}

// Situation 29
void WaterinBathroom()
{
  system("clear");

  printf("In the bathroom, water keeps running. You can see perfume, a razor");
  printf(" and medications.\n\n");
  printf("(1) You take the perfume with you, use it on the mixture, turn of");
  printf(" the water and hide in your room.\n");
  printf("(2) You take the razor with you.\n");
  printf("(3) You turn off the water.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') Razor();
 else if(stri == '2') Cupboard(0);
  else CreatureInBathroom();
}

//Situation 30
void LookBedroom()
{
  system("clear");

  printf("The creature noticed the absence of noise in the bathroom.\n");
  printf("Through the keyhole of your bedroom, you see the creature going out");
  printf(" of the kitchen.\n It sees the mixture on the table, smells it.\n");
  printf(" No grunt. It eats it all.\nThen, the creature suffocates, ");
  printf("throws up, then goes to the bathroom.\n\n");

  printf("(1) You check what it just threw up.\n");
  printf("(2) You eat what he threw up.\n");
  printf("(3) You check the bathroom.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') CheckVomit();
 else if(stri == '2') DEATH5();
  else CreatureInBathroom();
}

//Situation 31
void CheckVomit()
{
  system("clear");

  printf("Everything's dry, aaaaand there's the key!\n\n");
  printf("(1) Screw that key, I want to hug the creature.\n");
  printf("(2) You use it to open the EXIT door.\n");
  printf("(3) You wake up.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') DEATH3();
 else if(stri == '2') EndOfGame();
 else WakeUp();
}

//Situation 32
void Razor()
{
  system("clear");

  printf("You have a razor with you.\n\n");
  printf("(1) You kill the creature with it.\n");
  printf("(2) You commit suicide.\n");
  printf("(3) You put it back on the shelf.\n");

char str;
 str = getchar();
 char stri;
 stri = getchar();
 if(stri == '1') DEATH6();
 else if(stri == '2') DEATH7();
 else WaterinBathroom();
}

//SUCCESS! End of game
void EndOfGame()
{
  system("clear");

  printf("You made it! You're out of your appartement!");
  printf(GREEN"SUCCESS"WHITE"!\n");
}     
