#include <cs50.h>
#include <stdio.h>

int main()
{
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    for (int row = 1; row <= height; row++)
    {
        for (int space = 1; space <= height - row; space++)
        {
            printf(" ");
        }
        for (int block = 1; block <= row * 2 - 1; block++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
