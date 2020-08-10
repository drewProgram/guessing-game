// standard io - input/output
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// \n does the enter
int main() {
printf("\n\n");
printf("   _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._\n");
printf(".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-.\n");
printf(" )                                                                           (\n");
printf("(                                                                             )\n");
printf(" )                                                                           (\n");
printf("(                                                                             )\n");
printf(" )                                                                           (\n");
printf("(                         WELCOME TO THE GUESSING GAME                        )\n");
printf(" )                                                                           (\n");
printf("(                                                                             )\n");
printf(" )                                                                           (\n");
printf("(                                                                             )\n");
printf(" )                                                                           (\n");
printf("(                                                                             )\n");
printf(" )                                                                           (\n");
printf("(___       _       _       _       _       _       _       _       _       ___)\n");
printf("    `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-'\n");
printf("            `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-'\n");
printf("                    `-._.-' (__  _) (__  _) (_ _ _) `-._.-'\n");
printf("                            `-._.-' (_ ___) `-._.-'\n");
printf("                                    `-._.-'\n");
printf("\n\n");
  // get the seconds of 1970 untill now
  int seconds = time(0);
  // passing the seconds as the seed for the rand()
  srand(seconds);

  int randomNumber = rand();
  
  // rand generates gigantic numbers, so in order to get a lower number
  // we use this trick of getting the rest of the division.
  int secretNumber = randomNumber % 100;

  int attempts = 1;
  int maxAttempts;
  int guess;
  int correctAnswer;

  double points = 1000;
  
  int won = 0;

  int difficulty;
  printf("In what difficulty do you wish to play?\n");
  printf("(1) Easy  (2) Medium  (3) Hard\n\n");
  printf("Choose one: ");
  scanf("%d", &difficulty);

  switch(difficulty) {
    case 1:
      maxAttempts = 15;
      break;

    case 2:
      maxAttempts = 10;
      break;

    default:
      maxAttempts = 6;
      break;
  }

  for(int i = 1; i <= maxAttempts; i++)
  {
    printf("Attempt %d\n", i);
    printf("Which number is your guess?\n");

    scanf("%d", &guess);
    printf("Your guess was %d.\n", guess);

    if (guess < 0) 
    {
      printf("Only type positive numbers!!!\n");

      // it's like break, but just go to the next iteration
      continue;
    }

    correctAnswer = (guess == secretNumber);
    int higherAnswer = guess > secretNumber;

    if (correctAnswer)
    {
      won = 1;

      break;
    }
    else if (higherAnswer)
    {
      printf("Your guess was higher than the secret number.\n");
    }

    else
    {
      printf("Your guess was lower than the secret number.\n");
    }

    // casting and absolute number
    double lostPoints = abs(guess - secretNumber) / (double)2;

    points -= lostPoints;
    attempts++;
  }

  printf("GAME OVER\n");

  if (won)
  {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOO           OOOOO         \n");
        printf("            OOOOOOOOOOOOOO             \n");
        printf("              OOOOOOOOOO               \n");
        printf("\n\n");
    printf("Congratz, YOU WON!!!\n");
    printf("***** You finished the game with %d attempts and %.1f points *****", attempts, points);

  }
  else
  {
    printf("Sorry, you lost the game! Reopen the game and try again!\n\n");
    printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
  }
}
