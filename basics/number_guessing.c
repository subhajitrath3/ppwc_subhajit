/*
 * Number Guessing Game
 * Demonstrates: random numbers, loops, conditionals
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;
    const int MAX_ATTEMPTS = 7;
    
    // Initialize random seed
    srand(time(NULL));
    secret = rand() % 100 + 1;  // Random number between 1-100
    
    printf("=== Number Guessing Game ===\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it!\n\n", MAX_ATTEMPTS);
    
    do {
        attempts++;
        printf("Attempt %d: Enter your guess: ", attempts);
        scanf("%d", &guess);
        
        if (guess == secret) {
            printf("🎉 Congratulations! You guessed it in %d attempts!\n", attempts);
            break;
        } else if (guess < secret) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }
        
        if (attempts < MAX_ATTEMPTS) {
            printf("Try again.\n");
        }
        
    } while (attempts < MAX_ATTEMPTS);
    
    if (guess != secret) {
        printf("\n😞 Game over! The number was %d\n", secret);
    }
    
    return 0;
}