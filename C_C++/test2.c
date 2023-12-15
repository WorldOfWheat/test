#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int secret = rand() % 100 + 1;
    printf("Secret: %i\n", secret);
    printf("Guess 1 to 100\n");

    int guess;
    do
    {
        scanf("%i", &guess);
        if (guess > secret) printf("Too large\n");
        else printf("Too low\n");
    } while ((guess ^ secret) != 0);
    

    printf("Correct\n");

    return 0;
}