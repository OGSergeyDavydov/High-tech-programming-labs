#include <stdio.h>
#include <string.h>
#include <math.h>
#define SHOP_LEN 2
#define STUDENTS_LEN 1

typedef struct
{
    char name[100];
    float cost;
    int count;
} product;

typedef struct
{
    char day[20];
    char month[20];
    char year[40];
} data;

typedef struct
{
    char full_name[100];
    data date;
    char group[100];
} student;

typedef struct
{
    float real;
    float imaginary;
} complex_number;

void add_complex_numbers(complex_number a, complex_number b,
complex_number *res, int param)
{
    if (param > 0)
    {
        res->real = a.real + b.real;
        res->imaginary = a.imaginary + b.imaginary;
    }
    else
    {
        res->real = a.real - b.real;
        res->imaginary = a.imaginary - b.imaginary;
    }
}

void mult_complex_numbers(complex_number a, complex_number b,
complex_number *res)
{
    res->real = a.real*b.real - a.imaginary*b.imaginary;
    res->imaginary = a.imaginary*b.real + a.real*b.imaginary;
}

void divide_complex_numbers(complex_number a, complex_number b,
complex_number *res)
{
    if (b.real == 0 && b.imaginary == 0)
        printf("Zero division error\n");
    else
    {
        res->real = (a.real*b.real + a.imaginary*b.imaginary)
        / (b.real*b.real + b.imaginary*b.imaginary);
        res->imaginary = (a.imaginary*b.real - a.real*b.imaginary)
        / (b.real*b.real + b.imaginary*b.imaginary);
    }
}

void scalar_mult_complex_numbers(complex_number *num, float scalar)
{
    num->real *= scalar;
    num->imaginary *= scalar;
}

void print_complex_number(complex_number num)
{
    if (num.imaginary < 0)
        printf("%g - %gi\n", num.real, (fabs(num.imaginary)));
     else if (num.imaginary == 0)
        printf("%g\n", num.real);
    else
        printf("%g + %gi\n", num.real, num.imaginary);
}

void bubble_sort(student *students, int array_lenght)
{
    student temp;
    for (int i = 0; i < array_lenght; i++)
    {
      for (int j = i + 1; j < array_lenght; j++)
      {
          if (strcmp(students[i].full_name, students[j].full_name) > 0)
          {
            temp = students[i];
            students[i] =  students[j];
            students[j] = temp;
          }
       }
    }
}

int main()
{
  /* Task 1
    int count_goods = 0;
    float inp_cost;
    product shop[SHOP_LEN];

    for (int i = 0; i < SHOP_LEN; i++)
    {
        printf("Insert name, cost and number of the product %i\n", i+1);
        scanf("%s", (shop[i].name));
        scanf("%g", &(shop[i].cost));
        scanf("%d", &(shop[i].count));
    }

    printf("\nList of products:\n");
    for (int i = 0; i < SHOP_LEN; i++)
        printf("Product %d - %s, %g, %d\n", i+1, shop[i].name,
        shop[i].cost, shop[i].count);

    puts("\nInsert a product cost to filter goods");
    scanf("%g", &inp_cost);
    for (int i = 0; i < SHOP_LEN; i++)
    {
        if (shop[i].cost > inp_cost)
        {
        printf("Product %i - %s, %g, %d\n", i+1, shop[i].name,
        shop[i].cost, shop[i].count);
        count_goods += 1;
        }
    }

    if (!count_goods)
        puts("\nThere is no such products in the shop");
    */
    /* Task 2
    student students[STUDENTS_LEN];
    for (int i = 0; i < STUDENTS_LEN; i++)
    {
    printf("Insert full name\n");
    gets(students[i].full_name);

    printf("Date of birth in format dd.mm.yyyy separated by new line\n");
    gets(students[i].date.day);
    gets(students[i].date.month);
    gets(students[i].date.year);

    printf("group\n");
    gets(students[i].group);
    }

    bubble_sort(students, STUDENTS_LEN);
    printf("\nSorted List of students:\n");
    for (int i = 0; i < STUDENTS_LEN; i++)
    {
    printf("%d. %s, %s.%s.%s, %s\n", i+1, students[i].full_name,
    students[i].date.day, students[i].date.month, students[i].date.year,
    students[i].group);
    }
    */

    complex_number a = {1, 7};
    complex_number b = {1, 1};
    complex_number z;
    complex_number z1;
    complex_number z2;

    add_complex_numbers(a, b, &z, 1);
    mult_complex_numbers(a, b, &z1);
    divide_complex_numbers(a, b, &z2);
    scalar_mult_complex_numbers(&a, 5);
    print_complex_number(z1);

    return 0;
}
