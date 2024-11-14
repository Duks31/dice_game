/* Dice game by Jonas */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int random_number()
{
    int number = rand() % 6 + 1; // Generates random number between 1 and 6
    return number;
}

int main()
{
    int balance = 1000; // Total money available
    int bet;            // Bet amount
    int guess;          // User's guess
    int dice;           // Random number between 1 and 6
    char play_again;    // variable to check whether the user wants to play again

    srand(time(NULL));

    printf("Welcome to the Dice game \n\nYou have $1000. You bet an amount of money and guess a number \nIf my guess and yours are the same, You Win else Try again later!.\n\n");

    while (balance > 0)
    {
        printf("Your current betting amount is $%d\n", balance);

        printf("How much do you want to bet? \n");
        scanf("%d", &bet); // take the bet as input to bet variable

        if (bet <= 0 || bet > balance)
        {
            printf("Invalid bet. Please bet an amount within your balance.\n");
            continue;
        }

        printf("Guess a number between 1 - 6. To exit enter 0\n\n");
        scanf("%d", &guess); // take the guess and store it in the guess variable

        if (guess == 0)
        {
            printf("Bye!!!");
            break;
        }

        if (guess < 1 || guess > 6)
        {
            printf("Invalid guess. Please guess a number between 1 and 6\n");
            continue;
        }

        sleep(2);
        dice = random_number();

        printf("Dice Rolled: %d\n", dice);

        if (guess == dice)
        {
            balance += (bet * 3);
            printf("Congratulations!!!\nYou Won. Your new balance is %d\n\n", balance);
        }
        else
        {
            balance -= bet;
            printf("You Lost. Your new balance is %d\n", balance);
            printf("The correct guess was %d\n\n", dice);
        }

        if (balance > 0) {
            printf("Do you want to play another round? (y/n): ");
            scanf(" %c", &play_again);

            if (play_again != 'y' && play_again != 'Y') {
                printf("Thanks for playing!. GoodBye!");
                break;
            }
        }
    }

    if (balance < 0) {
        printf("You have run out of money. Game over!\n");
    }

    return 0;   
}