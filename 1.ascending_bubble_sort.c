#include <stdio.h>
#include <stdlib.h>
#define numbers_lenght 10000

void bubble_sort(int *array, int array_lenght)
{
    for (int i = 0; i < array_lenght; i++)
    {
        for (int j = i + 1; j < array_lenght; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void print_array(int *array, int array_lenght)
{   
    for (int i = 0; i < array_lenght; i++)
    {
      printf("%d\n", array[i]);  
    }
    printf("\n");
}

int main()
{   
    int *numbers = malloc(numbers_lenght * sizeof(int));

    for (int i = 0; i < numbers_lenght; i++)
    {
        numbers[i] = rand() % 50000 + 1;
    }
    
    bubble_sort(numbers, numbers_lenght);
    print_array(numbers, numbers_lenght);

    return 0;
}
