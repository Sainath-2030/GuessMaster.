#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 0 and 99
    int randomNumber = rand() % 100;
    printf("Random number between 0 and 99: %d\n", randomNumber);

    return 0;
}
