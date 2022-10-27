#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define size 1000
#define MAX 100

void int_bubble_sort(int *array, int array_lenght,
int ascending)
{
    for (int i = 0; i < array_lenght; i++)
    {
        for (int j = i + 1; j < array_lenght; j++)
        {
            if (ascending > 0)
            {
                if (array[i] > array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            } else {
                if (array[i] < array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}

void str_bubble_sort(char array[][MAX], int array_lenght,
int ascending)
{
    char temp[array_lenght];

    for (int i = 0; i < array_lenght; i++)
    {
        for (int j = i + 1; j < array_lenght; j++)
        {
            if (ascending == 1)
            {
                if (strcmp(array[i], array[j]) > 0)
                {
                    strcpy(temp, array[i]);
                    strcpy(array[i], array[j]);
                    strcpy(array[j], temp);
                }
            } else {
                if (strcmp(array[i], array[j]) < 0)
                {
                    strcpy(temp, array[i]);
                    strcpy(array[i], array[j]);
                    strcpy(array[j], temp);
                }
            }
        }
    }
}

int main()
{
    int *numbers = malloc(size * sizeof(int));
    char books[][MAX] = {
    "AnnaKarenina", "WutheringHeights", "JaneEyre",
    "TheBrothersKaramazov", "TheGreatGatsby",
    "ThePictureofDorian_Gray", "ToKillaMockingbird"
    };

    int n = sizeof(books) / sizeof(books[0]);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        numbers[i] = rand() % 50000 + 1;

    puts("Sorted array of integers:");
    int_bubble_sort(numbers, size, -1);

    for (int i = 0; i < size; i++)
        printf("%d\n", numbers[i]);
    
    printf("\n");

    puts("Sorted array of strings:");
    str_bubble_sort(books, n, 1);

    for (int i = 0; i < n; i++)
        printf("%s\n", books[i]);
    
    return 0;
}
