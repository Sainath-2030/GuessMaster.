#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Rules of the Game:\n");
    printf("1) This game is played between 2 players.\n");
    printf("2) First, choose the number of rounds you want to play.\n");
    printf("3) At the start of each round, the computer generates a random number between 0 and 99.\n");
    printf("4) Each player takes turns guessing the number.\n");
    printf("5) If a player’s guess is higher than the actual number, the computer will say 'Lower number, please!'\n");
    printf("   If the guess is lower, the computer will say 'Higher number, please!'\n");
    printf("6) Each wrong guess reduces the player’s score by 10 points (each player starts with 100 points).\n");
    printf("7) The player with the higher score at the end of the game wins!\n");

    // Seed the random number generator
    srand(time(0));

    int n, rounds, score_1 = 100, score_2 = 100; // Initial scores for both players
    int randomNumber, guesses_1, guesses_2;

    // Prompt the user to enter the number of rounds
    do
    {
        printf("\nEnter the number of rounds you want to play: ");
        scanf("%d", &rounds);
    } while (rounds <= 0);

    // Loop for each round
    for (int i = 1; i <= rounds; i++)
    {
        // Generate a new random number for each round
        randomNumber = rand() % 100;

        // **Player 1's Turn**
        guesses_1 = 1; // Reset guess count for player 1
        printf("\nRound %d - Player 1's Turn:\n", i);
        
        // Player 1 guesses
        do
        {
            printf("Guess the number between 0 and 99: ");
            scanf("%d", &n);
        } while (n > 99 || n < 0);

        while (n != randomNumber)
        {
            if (randomNumber > n)
            {
                printf("Higher number, please!\n");
            }
            else
            {
                printf("Lower number, please!\n");
            }

            guesses_1++;
            score_1 -= 10; // Reduce score after each wrong guess

            printf("Guess again: ");
            scanf("%d", &n);
        }
        printf("Correct! Player 1 took %d guesses to find the number %d.\n", guesses_1, randomNumber);

        // **Player 2's Turn**
        guesses_2 = 1; // Reset guess count for player 2
        randomNumber = rand() % 100;  // New random number for Player 2's turn

        printf("\nRound %d - Player 2's Turn:\n", i);

        // Player 2 guesses
        do
        {
            printf("Guess the number between 0 and 99: ");
            scanf("%d", &n);
        } while (n > 99 || n < 0);

        while (n != randomNumber)
        {
            if (randomNumber > n)
            {
                printf("Higher number, please!\n");
            }
            else
            {
                printf("Lower number, please!\n");
            }

            guesses_2++;
            score_2 -= 10; // Reduce score after each wrong guess

            printf("Guess again: ");
            scanf("%d", &n);
        }
        printf("Correct! Player 2 took %d guesses to find the number %d.\n", guesses_2, randomNumber);
    }

    // Final Scores and Winner Announcement
    printf("\nFinal Scores:\n");
    printf("Player 1: %d\n", score_1);
    printf("Player 2: %d\n", score_2);

    if (score_1 > score_2)
    {
        printf("Congratulations! Player 1 wins the game.\n");
    }
    else if (score_2 > score_1)
    {
        printf("Congratulations! Player 2 wins the game.\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

